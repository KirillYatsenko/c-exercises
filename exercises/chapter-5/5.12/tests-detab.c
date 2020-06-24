#include <stdbool.h>
#include <string.h>
#include "tests.h"
#include "tests-detab.h"

bool detab_pass_startindx_tablength_notalldetabed(void);
bool detab_notabs(void);

void run_detab_tests(void)
{
    run_test("detab_pass_startindx_tablength_notalldetabed", detab_pass_startindx_tablength_notalldetabed);
    run_test("detab_notabs", detab_notabs);
}

bool detab_pass_startindx_tablength_notalldetabed(void)
{
    char inputline[] = "k\t\ttmy";
    char actual[200];

    char expected[] = "k\t       tmy";
    detab(inputline, actual, strlen(inputline), 2, 9);

    bool result = strcmp(actual, expected) == 0;
    return result;
}


bool detab_notabs(void)
{
    char inputline[] = "kirill my name";
    char actual[200];

    detab(inputline, actual, strlen(inputline), 0, 8);

    bool result = strcmp(actual, inputline) == 0;
    return result;
}
