#include <stdbool.h>
#include <string.h>
#include "tests.h"
#include "tests-detab.h"

bool detab_happypath_return_detabed_string(void);
bool detab_notabs(void);

void run_detab_tests(void)
{
    run_test("detab_happypath_return_detabed_string", detab_happypath_return_detabed_string);
    run_test("detab_notabs", detab_notabs);
}

bool detab_happypath_return_detabed_string(void)
{
    char inputline[] = "kirill\tmy\tname";
    char actual[200];

    char *tabs[] = {
        "8",
        "16",
        "24"
        "32"
    };

    char expected[] = "kirill  my      name";
    detab(inputline, actual, strlen(inputline), 4, tabs);

    bool result = strcmp(actual, expected) == 0;
    return result;
}


bool detab_notabs(void)
{
    char inputline[] = "kirill my name";
    char actual[200];

    char *tabs[] = {
        "8",
        "16",
        "24"
        "32"
    };

    detab(inputline, actual, strlen(inputline), 4, tabs);

    bool result = strcmp(actual, inputline) == 0;
    return result;
}
