PostgreSQL Anonymizer 0.11: Release Candidate 1
================================================================================

Paris, France, March 31, 2022

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[Static Masking] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions] such as Substitution, Randomization, Faking,
Pseudonymization, Partial Scrambling, Shuffling, Noise Addition and
Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[Static Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/static_masking/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/


Towards version 1.0 and beyond !
--------------------------------------------------------------------------------

This releases does not introduce major changes. It is focused on fixing
remaining bugs and removing obsoletes parts of the code.

In previous versions we allowed users de declare masking rules using a `COMMENT`
statement. This is not supported anymore. Use `SECURITY LABEL FOR anon` to
declare your rules... And use `COMMENT` to declare comments :)



How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and further versions.

On Red Hat, CentOS and Rocky Linux systems, you can install it directly from the
[official PostgreSQL RPM repository]:

    dnf install postgresql_anonymizer14

Then load the extension with:

    ALTER DATABASE foo SET session_preload_libraries = 'anon';

Create the extension inside the database:

    CREATE EXTENSION anon CASCADE;

And finally, initialize the extension

    SELECT anon.init();


For other systems, check out the [install] documentation:

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------

This release includes code, bugfixes, documentation, code reviews and ideas from
Christophe Courtois, Hrvoje Pavlinovic, Mike Tefft, Cristian Gomez Portes and
others we may have missed.

Many thanks to them!


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien
[Frédéric Yhuel]: https://www.dalibo.com/en/equipe#frederic


--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.10: An improved engine and a brand new tutorial
================================================================================

Paris, France, March 14, 2022

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[Static Masking] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions] such as Substitution, Randomization, Faking,
Pseudonymization, Partial Scrambling, Shuffling, Noise Addition and
Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[Static Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/static_masking/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/


Many improvements and a better dynamic masking engine
--------------------------------------------------------------------------------

This version is a major step toward the upcoming version 1.0 which will be
considered as production ready.

The main changes are focused on the `pg_dump_anon.sh` wrapper which is now
faster and more accurate.

The dynamic masking engine has been simplified and improved. The change is not
visible for end users but the inner workings are now more robust, in particular
the main event trigger that hides the real data to the masked roles.


A brand new tutorial
--------------------------------------------------------------------------------

Anonymization can be a difficult task and sometimes we just don't know where
to start ! In addition to the [project documentation], we are now publishing
a complete 4-hours workshop with practical examples, a series of exercises and
their solutions.

The result is a 50 pages document designed as a kickstarter to help you discover
how you can use PostgreSQL Anonymizer to protect the privacy and comply to the
GDPR requirements.

The tutorial is available here:

https://dali.bo/howto_anon_handout


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and further versions.

On Red Hat, CentOS and Rocky Linux systems, you can install it directly from the
[official PostgreSQL RPM repository]:

    dnf install postgresql_anonymizer14

Then load the extension with:

    ALTER DATABASE foo SET session_preload_libraries = 'anon';

Create the extension inside the database:

    CREATE EXTENSION anon CASCADE;

And finally, initialize the extension

    SELECT anon.init();


For other systems, check out the [install] documentation:

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------

This release includes code, bugfixes, documentation, code reviews and ideas from
Be Hai Tran, Florent Jardin, Yann B., Christophe Courtois, Vito Botta,
Cristiano S., Adrien S., Justin Wei (and others we may have missed).

Many thanks to them!

A final special thanks goes to [Frédéric Yhuel] for his work on the pl/pgsql code
and the documentation !

How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien
[Frédéric Yhuel]: https://www.dalibo.com/en/equipe#frederic


--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.9: Trusted Schemas and Support for PostgreSQL 14
================================================================================

Paris, France, July 2nd, 2021

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[Static Masking] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions] such as Substitution, Randomization, Faking,
Pseudonymization, Partial Scrambling, Shuffling, Noise Addition and
Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[Static Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/static_masking/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/


Reject masking filters if they don't belong to a trusted schema
--------------------------------------------------------------------------------

With `PostgreSQL Anonymizer`, the database owner can define custom masking
filters that would hide sensitive information based on internal business rules,
for instance a specific masking function that would remove names and phone numbers
from a JSON document.

For security reasons, the database administrator may want to restrict this
feature by accepting only the masking filters located inside a **trusted** schema.

To activate this security barrier, the administrator can simply enable a GUC
option called `anon.restrict_to_trusted_schemas`:

    ALTER SYSTEM SET anon.restrict_to_trusted_schemas = on;

And then declare which schemas are trusted:

    SECURITY LABEL FOR anon ON SCHEMA foo IS 'TRUSTED';

By default, the schemas `pg_catalog` and `anon` are trusted. The `public` schema
is not trusted (and it should never be...).

IMPORTANT: Activating this parameter may break some pre-existing masking rules!
If that's the case, the database administrator may have to move some custom
masking functions inside a trusted schema. For now, this parameter is disabled
by default. However it will be set to 'on' by default in future versions.

Users are strongly encouraged to activate this option as soon as possible.


Warning:  Support for Amazon RDS is now deprecated
--------------------------------------------------------------------------------

As announced in the previous version, we made the difficult choice to drop the
so-called `standalone installation method`. In practice, the `anon_standalone.sql`
file will not evolve anymore.

As a collateral effect, this means the extension won't work on most of the
Postgres-as-a-Service platforms, such as Amazon RDS, unless they decide to
actively support it.

If privacy and anonymity are a concern to you, we encourage you to contact the
customer services of these platforms and ask them if they plan to add this
extension to their catalog.


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and further versions.

On Red Hat, CentOS and Rocky Linux systems, you can install it directly from the
[official PostgreSQL RPM repository]:

    yum install postgresql_anonymizer12

Then load the extension with:

    ALTER DATABASE foo SET session_preload_libraries = 'anon';

Create the extension inside the database:

    CREATE EXTENSION anon CASCADE;

And finally, initialize the extension

    SELECT anon.init();


For other systems, check out the [install] documentation:

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

> **WARNING:** The project is still under active development and should be
> used carefully.

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------

This release includes code, bugfixes and ideas from Carlos Medeiros, Devrim Gündüz,
Andreas D, Thibaut Madelaine.

Many thanks to them!


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard] and [Frédéric Yhuel]

This is an open project, contributions are welcome. We need your feedback and
ideas! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien
[Frédéric Yhuel]: https://www.dalibo.com/equipe#frederic

--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.8: Masking foreign tables and partitions
================================================================================

Paris, France, February 8, 2021

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[Static Masking] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions] such as Substitution, Randomization, Faking,
Pseudonymization, Partial Scrambling, Shuffling, Noise Addition and
Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[Static Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/static_masking/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/

Improve performances and randomness
--------------------------------------------------------------------------------

Our latest efforts were focused on performance and improving the `shuffle`
algorithm and `fake` data filters. You may also notice that the `anonymize_database`
function is much faster.

Support for foreign tables and partitions
--------------------------------------------------------------------------------

You can now declare masking rules on partitions, inherited tables and foreign tables.
However keep in mind that the masking rules are **NOT INHERITED**. If you have
split a table into multiple partitions, you need to declare the masking rules for
each partition.


Warning:  Support for Amazon RDS will be deprecated in the next version
--------------------------------------------------------------------------------

This extension was never really intended to work on Database As A Service platforms
(such as Amazon RDS or Google Cloud SQL). It just happens to work currently using
the `standalone installation` method but **we will no longer actively support it**.
In practice, the `anon_standalone.sql` file will not evolve anymore.

In future versions, we will introduce features that will force us to deprecate
this method. If privacy and anonymity are a concern to you, we encourage you to
contact the customer services of these platforms and ask them if they plan to
add this extension to their catalog.

How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and further versions.

On Red Hat / CentOS systems, you can install it from the
[official PostgreSQL RPM repository]:

    yum install postgresql_anonymizer12

Then load the extension with:

    ALTER DATABASE foo SET session_preload_libraries = 'anon';

Create the extension inside the database:

    CREATE EXTENSION anon CASCADE;

And finally, initialize the extension

    SELECT anon.init();


For other systems, check out the [install] documentation :

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

> **WARNING:** The project is still under active development and should be
> used carefully.

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------

This release includes code, bugfixes and ideas from Rushal Verma, Paul Bonaud,
Dmitry Fomin, Rodrigo Otsuka , Nicolas Peltier, Matthieu Larcher and others.

Many thanks to them!


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien


--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.7: Generic Hashing and Advanced Faking
================================================================================

Eymoutiers, France, September 25, 2020

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[In-Place Anonymization] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions] such as Substitution, Randomization, Faking,
Pseudonymization, Partial Scrambling, Shuffling, Noise Addition and
Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[In-Place Anonymization]: https://postgresql-anonymizer.readthedocs.io/en/latest/in_place_anonymization/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/

Generic Hashing
--------------------------------------------------------------------------------

In theory, hashing is not a valid anonymization technique, however in practice
it is sometimes necessary to generate a determinist hash of the original data.
For instance, when a pair of  primary key / foreign key is a "natural key",
it may contain actual information (like a customer number containing a birth
date or something similar).

Hashing such columns allows to keep referential integrity intact even for
relatively unusual source data. Therefore, the extension provides 2 masking
functions:

* `anon.hash(value)`  will return a text hash of the value using a secret salt
  and a secret hash algorithm (see below)

* `anon.digest(value,salt,algorithm)` lets you choose a salt and the hash
  algorithm you want to use

By default a random secret salt is generated when the extension is initialized
and the default hash algortihm is `sha512`. You can change that if needed.

Keep in mind that hashing is a form of Pseudonymization. This means that the
real data can be rebuilt using the hashed value and the masking function. If an
attacker gets access to these elements, he or she can easily re-identify
some persons using `brute force` or `dictionary` attacks. Therefore, **the
salt and the algorithm used to hash the data must be protected with the
same level of security that the original dataset.**

Many thanks to Gunnar "Nick" Bluth for his help on this feature !


Advanced Faking
-------------------------------------------------------------------------------

Generating fake data is a complex topic. The anon extension offers a set of
basic faking functions but for more advanced faking methods, in particular
if you are looking for **localized fake data**, take a look at
[PostgreSQL Faker], an extension based upon the well-known [Faker python library].

[PostgreSQL Faker]: https://gitlab.com/dalibo/postgresql_faker
[Faker python library]: https://faker.readthedocs.io

This extension provides an advanced faking engine with localisation support

For example:

    CREATE SCHEMA faker;
    CREATE EXTENSION faker SCHEMA faker;
    SELECT faker.faker('de_DE');
    SELECT faker.first_name_female();
     first_name_female
    -------------------
     Mirja


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and further versions.

On Red Hat / CentOS systems, you can install it from the
[official PostgreSQL RPM repository]:


    yum install postgresql_anonymizer12

Then load the extension with:

    ALTER DATABASE foo SET session_preload_libraries = 'anon';

Create the extension inside the database:

    CREATE EXTENSION anon CASCADE;

And finally, initialize the extension

    SELECT anon.init();


For other systems, check out the [install] documentation :

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

> **WARNING:** The project is at an early stage of development and should be
> used carefully.

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------


This release includes code, bugfixes and ideas from Gunnar "Nick" Bluth,
Yann Robin, Christophe Courtois, Nikolay Samokhvalov.

Many thanks to them !


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas ! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien



--------------------------------------------------------------------------------



PostgreSQL Anonymizer 0.6: Pseudonymization and Improved Anonymous Exports
================================================================================

Eymoutiers, France, Mars 5, 2020

`PostgreSQL Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[In-Place Anonymization] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions]: Substitution, Randomization, Faking, Pseudonymization,
Partial Scrambling, Shuffling, Noise Addition and Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[In-Place Anonymization]: https://postgresql-anonymizer.readthedocs.io/en/latest/in_place_anonymization/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/

Pseudonymization
--------------------------------------------------------------------------------

[Pseudonymization] functions are similar to the faking functions in the sense
that they generate realistic values. The main difference is that pseudonymization
is deterministic : the functions will always return the same fake value based on
a seed and an optional salt.

    # SELECT anon.pseudo_email('Alice','salt123');
       pseudo_email
    -------------------
     fcadell56@ucoz.ru
    # SELECT anon.pseudo_email('Alice','salt123');
       pseudo_email
    -------------------
     fcadell56@ucoz.ru

**WARNING** : Pseudonymization is often confused with anonymization but in fact
they serve 2 different purposes. With pseudonymization, the real data can be
rebuilt using the pseudo data and the masking rule. If an attacker
gets access to these elements, he or she can easily re-identify some people
using `brute force` or `dictionary` attacks. Therefore, you should protect any
pseudonymized data with the same level of security that the original dataset.
The GDPR makes it very clear that personal data which have undergone
pseudonymization are still considered to be personal information.

[Pseudonymization]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/#pseudonymization



Improved Anonymous Exports
--------------------------------------------------------------------------------

The `anon.dump()` function was slow and unpractical. It is now deprecated and
replace by a tool named `pg_dump_anon` that you can use like the regular `pg_dump`
command:

    pg_dump_anon -h localhost -U bob mydb > anonymous_dump.sql

It uses the same connections parameters that `pg_dump`. The PostgreSQL
environment variables ($PGHOST, PGUSER, etc.)  and `.pgpass` are supported.
However the `plain` format is the only supported format. The other formats
(`custom`, `dir` and `tar`) are not supported.


Detecting Hidden Identifiers
--------------------------------------------------------------------------------

This extension makes it very easy to declare masking rules. But of course when
you're creating an anonymization strategy, the hard part is to scan the database
model to find which columns contains direct and indirect identifiers and then
decide how these identifiers should be masked.

We now provide a `detect()` function that will search for common identifiers
names based on a dictionary. For now, 2 dictionaries are available: English
('en_US') and French ('fr_FR'). By default the English dictionary is used:


    # SELECT anon.detect('en_US');
     table_name |  column_name   | identifiers_category | direct
    ------------+----------------+----------------------+--------
     customer   | CreditCard     | creditcard           | t
     customer   | id             | account_id           | t
     vendor     | Firstname      | firstname            | t

The identifier categories are based on the [HIPAA classification].

[HIPAA classification]: https://www.luc.edu/its/aboutits/itspoliciesguidelines/hipaainformation/18hipaaidentifiers/


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and later.

On Red Hat / CentOS systems, you can install it from the
[official PostgreSQL RPM repository]:


    yum install postgresql_anonymizer12


Then add 'anon' in the `shared_preload_libraries` parameter of your
`postgresql.conf` file. And restart your instance.

For other systems, check out the [install] documentation :

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

> **WARNING:** The project is at an early stage of development and should be
> used carefully.

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------


This release includes code, bugfixes and ideas from Sebastien Delobel, Sam
Buckingham, Thomas Clark, Joe Auty, Pierre-Henri Dubois Amy and Olleg Samoylov.

Many thanks to them !


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas ! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien



--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.5: Generalization and k-anonymity
================================================================================

Eymoutiers, France, November 6, 2019

`Postgresql Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

The extension supports 3 different anonymization strategies: [Dynamic Masking],
[In-Place Anonymization] and [Anonymous Dumps]. It also offers a large choice of
[Masking Functions]: Substitution, Randomization, Faking, Partial Scrambling,
Shuffling, Noise Addition and Generalization.

[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[In-Place Anonymization]: https://postgresql-anonymizer.readthedocs.io/en/latest/in_place_anonymization/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/

Generalization
--------------------------------------------------------------------------------

The idea of generalization is to replace data with a broader, less accurate
value. For instance, instead of saying "Bob is 28 years old", you can say
"Bob is between 20 and 30 years old". This is interesting for analytics because
the data remains true while avoiding the risk of re-identification.

PostgreSQL can handle generalization very easily with the [RANGE] data types,
a very poweful way to store and manipulate a set of values contained between
a lower and an upper bound.

[RANGE]: https://www.postgresql.org/docs/current/rangetypes.html

Here's a basic table containing medical data:

    SELECT * FROM patient;
         ssn     | firstname | zipcode |   birth    |    disease
    -------------+-----------+---------+------------+---------------
     253-51-6170 | Alice     |   47012 | 1989-12-29 | Heart Disease
     091-20-0543 | Bob       |   42678 | 1979-03-22 | Allergy
     565-94-1926 | Caroline  |   42678 | 1971-07-22 | Heart Disease
     510-56-7882 | Eleanor   |   47909 | 1989-12-15 | Acne


We want the anonymized data to remain **true** because it will be
used for statistics. We can build a view upon this table to remove
useless columns and generalize the indirect identifiers (zipcode and
birthday):


    CREATE MATERIALIZED VIEW generalized_patient AS
    SELECT
      'REDACTED'::TEXT AS firstname,
      anon.generalize_int4range(zipcode,1000) AS zipcode,
      anon.generalize_daterange(birth,'decade') AS birth,
      disease
    FROM patient;

This will give us a less accurate view of the data:

    SELECT * FROM generalized_patient;
     firstname |    zipcode    |          birth          |    disease
    -----------+---------------+-------------------------+---------------
     REDACTED  | [47000,48000) | [1980-01-01,1990-01-01) | Heart Disease
     REDACTED  | [42000,43000) | [1970-01-01,1980-01-01) | Allergy
     REDACTED  | [42000,43000) | [1970-01-01,1980-01-01) | Heart Disease
     REDACTED  | [47000,48000) | [1980-01-01,1990-01-01) | Acne


k-anonymity
--------------------------------------------------------------------------------

k-anonymity is an industry-standard term used to describe a property of an
anonymized dataset. The k-anonymity principle states that within a
given dataset, any anonymized individual cannot be distinguished from at
least `k-1` other individuals. In other words, k-anonymity might be described
as a "hiding in the crowd" guarantee. A low value of `k` indicates there's a risk
of re-identification using linkage with other data sources.

You can evaluate the k-anonymity factor of a table in 2 steps :

Step 1: First defined the columns that are [indirect idenfiers] ( also known
as "quasi identifers") like this:

    SECURITY LABEL FOR anon ON COLUMN generalized_patient.zipcode
    IS 'INDIRECT IDENTIFIER';

    SECURITY LABEL FOR anon ON COLUMN generalized_patient.birth
    IS 'INDIRECT IDENTIFIER';

Step 2: Once the indirect identifiers are declared :

    SELECT anon.k_anonymity('generalized_patient')

In the example above, the k-anonymity factor of the `generalized_patient`
materialized view is `2`.

Lorem Ipsum
--------------------------------------------------------------------------------

For TEXT and VARCHAR columns, you can now use the classic [Lorem Ipsum]
generator:

* `anon.lorem_ipsum()` returns 5 paragraphs
* `anon.lorem_ipsum(2)` returns 2 paragraphs
* `anon.lorem_ipsum( paragraphs := 4 )` returns 4 paragraphs
* `anon.lorem_ipsum( words := 20 )` returns 20 words
* `anon.lorem_ipsum( characters := 7 )` returns 7 characters

[Lorem Ipsum]: https://lipsum.com

How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and later.

On Red Hat / CentOS systems, you can install it from the
[official PostgreSQL RPM repository]:

    yum install postgresql_anonymizer12

Then add 'anon' in the `shared_preload_libraries` parameter of your
`postgresql.conf` file. And restart your instance.

For other system, check out the [install] documentation :

https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

> **WARNING:** The project is at an early stage of development and should be
> used carefully.

[official PostgreSQL RPM repository]: https://yum.postgresql.org/
[install]: https://postgresql-anonymizer.readthedocs.io/en/latest/INSTALL/

Thanks
--------------------------------------------------------------------------------

This release includes code and ideas from Travis Miller, Jan Birk and Olleg
Samoylov. Many thanks to them !


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas ! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien



--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.4 : Declare Masking Rules With Security Labels
================================================================================

Eymoutiers, October 14, 2019

`Postgresql Anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

This new version introduces a major change of syntax. In the previous versions,
the data masking rules were declared with column comments. They are now defined
by using [security labels]:

[security labels]: https://www.postgresql.org/docs/current/sql-security-label.html

    SECURITY LABEL FOR anon
    ON COLUMN customer.lastname
    IS 'MASKED WITH FUNCTION anon.fake_last_name()'

The previous syntax is still supported and backward compatibility is maintained.


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and later.

It requires extension named [tsm_system_rows] (available in the `contrib`
package) and an extension called [ddlx] (available via [PGXN]) :

    pgxn install ddlx
    pgxn install postgresql_anonymizer

Then add 'anon' in the `shared_preload_libraries` parameter of your
`postgresql.conf` file. And restart your instance.

> **WARNING:** The project is at an early stage of development and should be used
> carefully.

[tsm_system_rows]: https://www.postgresql.org/docs/current/tsm-system-rows.html
[ddlx]: https://github.com/lacanoid/pgddl
[PGXN]: https://pgxn.org/


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas ! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien



--------------------------------------------------------------------------------


PostgreSQL Anonymizer 0.3 : In-Place Masking and Anonymous Dumps
================================================================================

Paris, August 26, 2019

`postgresql_anonymizer` is an extension that hides or replaces personally
identifiable information (PII) or commercially sensitive data from a PostgreSQL
database.

Firts of all, you declare a list of [Masking Rules] directly inside the database
model with SQL comments like this :

    COMMENT ON COLUMN users.name IS 'MASKED WITH FUNCTION md5(name)';

Once the masking rules are declared, anonymization can be acheived in 3
different ways:

* [Anonymous Dumps]: Simply export the masked data into an SQL file
* [In-Place Anonymization]: Remove the sensible data according to the rules
* [Dynamic Masking]: Hide sensible data, only for the masked users

In addition, various [Masking Functions] are available : randomization, faking,
partial scrambling, shuffling, noise, etc... You can also user your own custom
function !

For more detail, please take a look at the documention:
https://postgresql-anonymizer.readthedocs.io/

[Masking Rules]: https://postgresql-anonymizer.readthedocs.io/en/latest/declare_masking_rules/
[Masking Functions]: https://postgresql-anonymizer.readthedocs.io/en/latest/masking_functions/
[Anonymous Dumps]: https://postgresql-anonymizer.readthedocs.io/en/latest/anonymous_dumps/
[In-Place Anonymization]: https://postgresql-anonymizer.readthedocs.io/en/latest/in_place_anonymization/
[Dynamic Masking]: https://postgresql-anonymizer.readthedocs.io/en/latest/dynamic_masking/


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and later.

It requires extension named [tsm_system_rows] (available in the `contrib`
package) and an extension called [ddlx] (available via [PGXN]) :

    pgxn install ddlx
    pgxn install postgresql_anonymizer

> **WARNING:** The project is at an early stage of development and should be used
> carefully.

[tsm_system_rows]: https://www.postgresql.org/docs/current/tsm-system-rows.html
[ddlx]: https://github.com/lacanoid/pgddl
[PGXN]: https://pgxn.org/


How to contribute
--------------------------------------------------------------------------------

PostgreSQL Anonymizer is part of the [Dalibo Labs] initiative. It is mainly
developed by [Damien Clochard].

This is an open project, contributions are welcome. We need your feedback and
ideas ! Let us know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

https://gitlab.com/dalibo/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs


[Dalibo Labs]: https://labs.dalibo.com
[Damien Clochard]: https://www.dalibo.com/en/equipe#daamien



--------------------------------------------------------------------------------

Introducing PostgreSQL Anonymizer 0.2.1 !
================================================================================

Paris, october 29, 2018

`postgresql_anonymizer` is an extension to mask or replace personally identifiable
information (PII) or commercially sensitive data from a PostgreSQL database.

The projet is aiming toward a **declarative approach** of anonymization. This
means we're trying to extend PostgreSQL's Data Definition Language (DDL) in
order to specify the anonymization strategy inside the table definition itself.

The extension can be used to put dynamic masks on certain users or permanently
modify sensitive data. Various masking techniques are available : randomization,
partial scrambling, custom rules, etc.

This tool is distributed under the PostgreSQL licence and the code is here:

https://gitlab.com/daamien/postgresql_anonymizer

Example
--------------------------------------------------------------------------------

Imagine a `people` table

    =# SELECT * FROM people;
      id  |      name      |   phone
    ------+----------------+------------
     T800 | Schwarzenegger | 0609110911

### STEP 1 : Activate the masking engine

    =# CREATE EXTENSION IF NOT EXISTS anon CASCADE;
    =# SELECT anon.mask_init();

### STEP 2 : Declare a masked user

    =# CREATE ROLE skynet;
    =# COMMENT ON ROLE skynet IS 'MASKED';

### STEP 3 : Declare the masking rules

    =# COMMENT ON COLUMN people.name
    -# IS 'MASKED WITH FUNCTION anon.random_last_name()';

    =# COMMENT ON COLUMN people.phone
    -# IS 'MASKED WITH FUNCTION anon.partial(phone,2,$$******$$,2)';

### STEP 4 : Connect with the masked user

    =# \! psql test -U skynet -c 'SELECT * FROM people;'
      id  |   name   |   phone
    ------+----------+------------
     T800 | Nunziata | 06******11


How to Install
--------------------------------------------------------------------------------

This extension is officially supported on PostgreSQL 9.6 and later.
It should also work on PostgreSQL 9.5 with a bit of hacking.

It requires an extension named `tsm_system_rows`, which is delivered by the
postgresql-contrib package of the main linux distributions

You can install it with `pgxn` or build from source it like any other
extenstion.

**WARNING:** The project is at an early stage of development and should be used carefully.


How to contribute
--------------------------------------------------------------------------------

I'd like to thanks all my wonderful colleagues at [Dalibo] for their support
and especially Thibaut Madelaine for the initial ideas.

This is an open project, contributions are welcome. I need your feedback and
ideas ! Let me know what you think of this tool, how it fits your needs and
what features are missing.

If you want to help, you can find a list of `Junior Jobs` here:

<https://gitlab.com/daamien/postgresql_anonymizer/issues?label_name%5B%5D=Junior+Jobs>

[Dalibo]: https://dalibo.com
