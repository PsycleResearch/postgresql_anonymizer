--
-- This test requires to modify`anon.masking_policies` AND restart the instance
-- It is hard to achieve with pg_regress
-- So we keep this test out of the `installcheck` target
--
-- To test it manually, run the command
-- make installcheck REGRESS=multiple_masking_policies
--

ALTER SYSTEM SET anon.masking_policies = 'foo, bar';

BEGIN;

CREATE EXTENSION anon CASCADE;

SECURITY LABEL FOR foo ON ROLE postgres IS NULL;
SECURITY LABEL FOR bar ON ROLE postgres IS NULL;

ROLLBACK;

ALTER SYSTEM RESET anon.masking_policies;
