#include <stdbool.h>
#include "tests.h"

void run_test(char* testname, bool (*test)(void))
{
    bool result = test();
    printf("%s - %s\n", testname, result ? "Passed" : "Failed");
}
