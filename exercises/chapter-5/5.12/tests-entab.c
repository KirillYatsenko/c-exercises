#include <string.h>
#include <stdbool.h>
#include "entab.h"
#include "tests.h"
#include "tests-entab.h"

bool entab_happypath_should_return_entabed(void);
bool entab_shortstring_notabs(void);

void run_entab_tests(void)
{
    run_test("entab_happypath_should_return_entabed", entab_happypath_should_return_entabed);
    run_test("entab_shortstring_notabs", entab_shortstring_notabs);
}

bool entab_happypath_should_return_entabed(void)
{
    char inputline[200] = "kiri    	lada	nastia";
    char actual[200];
    char *tabs[] = {
        "8",
        "16",
        "24"
        "32"
    };

    char* expected = "kiri\t\tlada\tnastia";
    entab(inputline, actual, strlen(inputline), 4, tabs);

    bool result = strcmp(expected, actual) == 0;

    return result;
}

bool entab_shortstring_notabs(void)
{
    char inputline[] = "kiri";
    char actual[200];
    char *tabs[] = {
        "8",
        "16",
        "24"
        "32"
    };

    char* expected = "kiri";
    entab(inputline, actual, strlen(inputline), 4, tabs);

    bool result = strcmp(expected, actual) == 0;

    return result;
}

