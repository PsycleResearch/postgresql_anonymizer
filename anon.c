/*
 * This comes directly from the dummy_seclabel example
 * see https://github.com/postgres/postgres/blob/master/src/test/modules/dummy_seclabel/dummy_seclabel.c
 *
 */

#include "postgres.h"
#include "commands/seclabel.h"
#include "parser/parser.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

/*
 * Declarations
 */
void    _PG_init(void);

PG_FUNCTION_INFO_V1(anon_seclabel_anon);

/*
 * Checking the syntax of the masking rules
 */
static void
anon_object_relabel(const ObjectAddress *object, const char *seclabel)
{
  if (seclabel == NULL
    || pg_strcasecmp(seclabel,"MASKED") == 0
    || pg_strncasecmp(seclabel, "MASKED WITH FUNCTION", 20) == 0
    || pg_strncasecmp(seclabel, "MASKED WITH VALUE", 17) == 0
    || pg_strncasecmp(seclabel, "QUASI IDENTIFIER",17) == 0
    || pg_strncasecmp(seclabel, "INDIRECT IDENTIFIER",19) == 0
  )
  return;

  ereport(ERROR,
      (errcode(ERRCODE_INVALID_NAME),
       errmsg("'%s' is not a valid masking rule", seclabel)));
}


void
_PG_init(void)
{
  /* Security label provider hook */
  register_label_provider("anon",anon_object_relabel);
}

/*
 * This function is here just so that the extension is not completely empty
 * and the dynamic library is loaded when CREATE EXTENSION runs.
 */
Datum
anon_seclabel_anon(PG_FUNCTION_ARGS)
{
  PG_RETURN_VOID();
}


/*
 * get_function_schema
 *   Given a function call, e.g. 'anon.fake_city()', returns the namespace of
 *   the function (if possible)
 *
 * returns the schema name if the function is properly schema-qualified
 * returns an empty string if we can't find the schema name
 *
 * We're calling the parser to split the function call into a "raw parse tree".
 * At this stage, there's no way to know if the schema does really exists. We
 * simply deduce the schema name as it is provided.
 *
 */
PG_FUNCTION_INFO_V1(get_function_schema);

Datum
get_function_schema(PG_FUNCTION_ARGS)
{
    bool input_is_null = PG_ARGISNULL(0);
    char* function_call= text_to_cstring(PG_GETARG_TEXT_PP(0));
    char query_string[1024];
    List  *raw_parsetree_list;
    SelectStmt *stmt;
    ResTarget  *restarget;
    FuncCall   *fc;

    if (input_is_null) PG_RETURN_NULL();

    /* build a simple SELECT statement and parse it */
    query_string[0] = '\0';
    strlcat(query_string, "SELECT ", sizeof(query_string));
    strlcat(query_string, function_call, sizeof(query_string));
    raw_parsetree_list = raw_parser(query_string);

    /* walk throught the parse tree, down to the FuncCall node (if present) */
    #if PG_VERSION_NUM >= 100000
    stmt = (SelectStmt *) linitial_node(RawStmt, raw_parsetree_list)->stmt;
    #else
    stmt = (SelectStmt *) linitial(raw_parsetree_list);
    #endif
    restarget = (ResTarget *) linitial(stmt->targetList);
    if (! IsA(restarget->val, FuncCall))
    {
      ereport(ERROR,
        (errcode(ERRCODE_INVALID_NAME),
        errmsg("'%s' is not a valid function call", function_call)));
    }

    /* if the function name is qualified, extract and return the schema name */
    fc = (FuncCall *) restarget->val;
    if ( list_length(fc->funcname) == 2 )
    {
      PG_RETURN_TEXT_P(cstring_to_text(strVal(linitial(fc->funcname))));
    }

    PG_RETURN_TEXT_P(cstring_to_text(""));
}
