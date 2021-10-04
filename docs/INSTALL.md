INSTALL
===============================================================================

The installation process is composed of 4 basic steps:

* Step 1: **Deploy** the extension into the host server
* Step 2: **Load** the extension in the PostgreSQL instance
* Step 3: **Create** the extension inside the database
* Step 4: **Initialize** the extension internal data

There are multiple ways to install the extension :

* [Install on RedHat / CentOS]
* [Install with PGXN]
* [Install from source]
* [Install with docker]
* [Install as a black box]
* [Install on MacOS]
* [Install on Windows]
* [Install in the cloud]

In the examples below, we load the extension (step2) using a parameter called
`session_preload_libraries` but there are other ways to load it.
See [Load the extension] for more details.

If you're having any problem, check the [Troubleshooting] section.

[Install on RedHat / CentOS]: #install-on-redhat-centos
[Install with PGXN]: #install-with-pgxn
[Install from source]: #install-from-source
[Install in the cloud]: #install-in-the-cloud
[Install with docker]: #install-with-docker
[Install as a black box]: #install-as-a-black-box
[Install on MacOS]: #install-on-macos
[Install on Windows]: #install-on-windows
[Load the extension]: #addendum--load-the-extension
[Troubleshooting]: #addendum--troubleshooting

Choose your version : `Stable` or `Latest` ?
------------------------------------------------------------------------------

This extension is available in two versions :

* `stable` is recommended for production
* `latest` is useful if you want to test new features




Install on RedHat / CentOS
------------------------------------------------------------------------------

> This is the recommended way to install the `stable` extension
> This method works for RHEL/CentOS 7 and 8. If you're running RHEL/CentOS 6,
> consider upgrading or read the [Install With PGXN] section.

_Step 0:_ Add the [PostgreSQL Official RPM Repo] to your system. It should be
something like:

```console
sudo yum install https://.../pgdg-redhat-repo-latest.noarch.rpm
```

[PostgreSQL Official RPM Repo]: https://yum.postgresql.org/


_Step 1:_ Deploy

```console
sudo yum install postgresql_anonymizer12
```

(Replace `12` with the major version of your PostgreSQL instance.)

_Step 2:_  Load the extension.

```sql
ALTER DATABASE foo SET session_preload_libraries = 'anon';
```

(If you already loading extensions that way, just add `anon` the current list)

_Step 3:_  Create the extension and load the anonymization data

```sql
CREATE EXTENSION anon CASCADE;
```

_Step 4:_  Initialize the extension

```sql
SELECT anon.init();
```

All new connections to the database can now use the extension.


Install With [PGXN](https://pgxn.org/) :
------------------------------------------------------------------------------

> This method will install the `stable` extension


_Step 1:_  Deploy the extension into the host server with:

```console
sudo apt install pgxnclient postgresql-server-dev-12
sudo pgxn install postgresql_anonymizer
```

(Replace `12` with the major version of your PostgreSQL instance.)

_Step 2:_  Load the extension.

```sql
ALTER DATABASE foo SET session_preload_libraries = 'anon';
```

(If you already loading extensions that way, just add `anon` the current list)

_Step 3:_  Create the extension

```sql
CREATE EXTENSION anon CASCADE;
```

_Step 4:_  Initialize the extension

```sql
SELECT anon.init();
```

All new connections to the database can now use the extension.


**Additional notes:**

* PGXN can also be installed with `pip install pgxn`
* If you have several versions of PostgreSQL installed on your system,
  you may have to point to the right version with the `--pg_config`
  parameter. See [Issue #93] for more details.
* Check out the [pgxn install documentation] for more information.

[pgxn install documentation]: https://github.com/pgxn/pgxnclient/blob/master/docs/usage.rst#pgxn-install
[Issue #93]: https://gitlab.com/dalibo/postgresql_anonymizer/issues/93


Install From source
------------------------------------------------------------------------------

> This is the recommended way to install the `latest` extension

_Step 0:_ First you need to install the postgresql development libraries.
On most distributions, this is available through a package called
`postgresql-devel` or `postgresql-server-dev`.

_Step 1:_  Build the project like any other PostgreSQL extension:

```console
make extension
sudo make install
```

**NOTE**: If you have multiple versions of PostgreSQL on the server, you may
need to specify which version is your target by defining the `PG_CONFIG` env
variable like this:

```console
make extension PG_CONFIG=/usr/lib/postgresql/14/bin/pg_config
sudo make install PG_CONFIG=/usr/lib/postgresql/14/bin/pg_config
```



_Step 2:_  Load the extension.

```sql
ALTER DATABASE foo SET session_preload_libraries = 'anon';
```

(If you already loading extensions that way, just add `anon` the current list)

_Step 3:_  Create the extension

```sql
CREATE EXTENSION anon CASCADE;
```

_Step 4:_  Initialize the extension

```sql
SELECT anon.init();
```

All new connections to the database can now use the extension.





Install with Docker
------------------------------------------------------------------------------

If you can't (or don't want to) install the PostgreSQL Anonymizer extension
directly inside your instance, then you can use the docker image :

```console
docker pull registry.gitlab.com/dalibo/postgresql_anonymizer:stable
```

The image is available with 2 two tags:

* `latest` (default) contains the current developments
* `stable` is the based on the previous release

You can run the docker image like the regular [postgres docker image].

[postgres docker image]: https://hub.docker.com/_/postgres

For example:

Launch start a postgres docker container

```console
docker run -d --name anon -p 6543:5432 registry.gitlab.com/dalibo/postgresql_anonymizer
```

Connect :

```console
psql -h localhost -p6543 -U postgres
```

The extension is already created and initialized, you can use it directly:

```sql
# SELECT anon.partial_email('daamien@gmail.com');
     partial_email
-----------------------
 da******@gm******.com
(1 row)
```


**Note:** The docker image is based on the latest PostgreSQL version and we do
not plan to provide a docker image for each version of PostgreSQL. However you
can build your own image based on the version you need like this:

```shell
PG_MAJOR_VERSION=11 make docker_image
```

Install as a "Black Box"
------------------------------------------------------------------------------


You can also treat the docker image as an "anonymizing black box" by using a
specific entrypoint script called `/anon.sh`. You pass the original data
and the masking rules to the `/anon.sh` script and it will return a anonymized
dump.

Here's an example in 4 steps:

_Step 1:_  Dump your original data (for instance `dump.sql`)

```console
pg_dump [...] my_db > dump.sql
```

If you want to maintain the owners and grants, you need export them with
`pg_dumpall --roles-only` like this:

```console
(pg_dumpall [...] --roles-only && pg_dump [...] my_db ) > dump.sql
```


_Step 2:_  Write your masking rules in a separate file (for instance `rules.sql`)

```sql
SELECT pg_catalog.set_config('search_path', 'public', false);

CREATE EXTENSION anon CASCADE;
SELECT anon.init();

SECURITY LABEL FOR anon ON COLUMN people.lastname
IS 'MASKED WITH FUNCTION anon.fake_last_name()';

-- etc.
```

_Step 3:_  Pass the dump and the rules through the docker image and receive an
anonymized dump !

```console
IMG=registry.gitlab.com/dalibo/postgresql_anonymizer
ANON="docker run --rm -i $IMG /anon.sh"
cat dump.sql rules.sql | $ANON > anon_dump.sql
```

(this last step is written on 3 lines for clarity)

_NB:_ You can also gather _step 1_ and _step 3_ in a single command:

```console
(pg_dumpall --roles-only && pg_dump my_db) | cat - rules.sql | $ANON > anon_dump.sql
```


Install on MacOS
------------------------------------------------------------------------------

Although the extension is not officially supported on MacOS systems, it should
be possible to build the extension with the following lines:

```console
export C_INCLUDE_PATH="$(xcrun --show-sdk-path)/usr/include"
make extension
make install
```

Install on Windows
------------------------------------------------------------------------------

This extension is not supported on Windows.

However in theory it should be possible to compile it using Visual Studio.
we simply lack the time and resource to work on this topic. You can contact us
if you which to fund this effort.


Install in the cloud
------------------------------------------------------------------------------

> **WARNING** In previous versons, this extension could be installed on various
> Database As A Service platforms (such as Amazon RDS). Starting with version 0.9,
> this is not possible anymore. We do not support the former `standalone` method.
> If privacy and anonymity are a concern to you, we encourage you to contact the
> customer services of these platforms and ask them if they plan to add this
> extension to their catalog.


Addendum: Alternative ways to load the extension
------------------------------------------------------------------------------

Here's some additional notes about how you can load the extension:

### 1- Load only for one database

You can load the extension exclusively into a specific database like this:

```sql
ALTER DATABASE mydatabase SET session_preload_libraries='anon'
```

Then quit your current session and open a new one.

It has several benefits:

* First, it will be dumped by `pg_dump` with the`-C` option, so the database
  dump will be self efficient.

* Second, it is propagated to a standby instance by streaming replication.
  Which means you can use the anonymization functions on a read-only clone
  of the database (provided the extension is installed on the standby instance)

### 2- Load for the instance

You can load the extension with the `shared_preload_libraries` parameter.

```sql
ALTER SYSTEM SET shared_preload_libraries = 'anon'"
```

Then restart the PostgreSQL instance.


### 3- Load on the fly

For a one-time usage, You can the [LOAD] command

```sql
LOAD '/usr/lib/postgresql/12/lib/anon.so';
```

You can read the [Shared Library Preloading] section of the PostgreSQL documentation
for more details.

[LOAD]: https://www.postgresql.org/docs/current/sql-load.html
[Shared Library Preloading]:https://www.postgresql.org/docs/current/runtime-config-client.html#RUNTIME-CONFIG-CLIENT-PRELOAD


Addendum: Troubleshooting
------------------------------------------------------------------------------

If you are having difficulties, you may have missed a step during the
installation processes. Here's a quick checklist to help you:

### Check that the extension is present

First, let's see if the extension was correctly deployed:

```console
ls $(pg_config --sharedir)/extension/anon
ls $(pg_config --pkglibdir)/anon.so
```

If you get an error, the extension is probably not present on host server.
Go back to step 1.

### Check that the extension is loaded

Now connect to your database and look at the configuration with:

```sql
SHOW local_preload_libraries;
SHOW session_preload_libraries;
SHOW shared_preload_libraries;
```

If you don't see `anon` in any of these parameters, go back to step 2.

### Check that the extension is created

Again connect to your database and type:

```sql
SELECT * FROM pg_extension WHERE extname= 'anon';
```

If the result is empty, the extension is not declared in your database.
Go back to step 3.

### Check that the extension is initialized

Finally, look at the state of the extension:

```sql
SELECT anon.is_initialized();
```

If the result is not `t`, the extension data is not present.
Go back to step 4.
