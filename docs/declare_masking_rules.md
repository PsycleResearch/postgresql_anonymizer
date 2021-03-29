Put on your Masks !
===============================================================================

The main idea of this extension is to offer **anonymization by design**.

The data masking rules should be written by the people who develop the
application because they have the best knowledge of how the data model works.
Therefore masking rules must be implemented directly inside the database schema.

This allows to mask the data directly inside the PostgreSQL instance without
using an external tool and thus limiting the exposure and the risks of data leak.

The data masking rules are declared simply by using [security labels]:

[security labels]: https://www.postgresql.org/docs/current/sql-security-label.html

<!-- demo/declare_masking_rules.sql -->

```sql
CREATE TABLE player( id SERIAL, name TEXT, points INT);

INSERT INTO player VALUES
  ( 1, 'Kareem Abdul-Jabbar', 38387),
  ( 5, 'Michael Jordan', 32292 );

SECURITY LABEL FOR anon ON COLUMN player.name
  IS 'MASKED WITH FUNCTION anon.fake_last_name()';

SECURITY LABEL FOR anon ON COLUMN player.id
  IS 'MASKED WITH VALUE NULL';
```

Removing a masking rule
------------------------------------------------------------------------------

You can simply erase a masking rule like this:

```sql
SECURITY LABEL FOR anon ON COLUMN player.name IS NULL
```

Limitations
------------------------------------------------------------------------------

* The masking rules are **NOT INHERITED** ! If you have split a table into
  multiple partitions, you need to declare the masking rules for each partition.


Declaring Rules with COMMENTs
------------------------------------------------------------------------------

> **WARNING** : This method is not supported anymore and will be fully
> deprecated in future versions.

There is an alternative way for declaring masking rules, using the
COMMENT syntax:

```sql
COMMENT ON COLUMN player.name
IS 'MASKED WITH FUNCTION anon.fake_last_name()'
```




