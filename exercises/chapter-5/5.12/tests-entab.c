#include <string.h>
#include <stdbool.h>
#include "entab.h"
#include "tests.h"
#include "tests-entab.h"

bool entab_happypath_should_return_entabed(void);
bool entab_shortstring_notabs(void);
bool entab_passed_startindx_tablength_should_avoid_firstab(void);


void run_entab_tests(void)
{
    run_test("entab_happypath_should_return_entabed", entab_happypath_should_return_entabed);
    run_test("entab_shortstring_notabs", entab_shortstring_notabs);
    run_test("entab_passed_startindx_tablength_should_avoid_firstab", entab_passed_startindx_tablength_should_avoid_firstab);
}

bool entab_happypath_should_return_entabed(void)
{
    char inputline[200] = "kiri    	lada	nastia";
    char actual[200];

    char* expected = "kiri\t\tlada\tnastia";
    entab(inputline, actual, strlen(inputline), 0, 8);

    bool result = strcmp(expected, actual) == 0;
    return result;
}

bool entab_shortstring_notabs(void)
{
    char inputline[] = "kiri";
    char actual[200];

    char* expected = "kiri";
    entab(inputline, actual, strlen(inputline), 0, 8);

    bool result = strcmp(expected, actual) == 0;
    return result;
}

bool entab_passed_startindx_tablength_should_avoid_firstab(void)
{
    char inputline[200] = "kiri    	lada	nastia";
    char actual[200];

    char* expected = "kiri    	lada\tnastia";
    entab(inputline, actual, strlen(inputline), 10, 8);

    bool result = strcmp(expected, actual) == 0;
    return result;
}


