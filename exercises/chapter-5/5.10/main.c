#include <stdio.h>
#include <stdlib.h>
#include "polish-calculator.h"
#include "tests-polish-calculator.h"

int main(int argc, char *argv[])
{
    check();

    int res = evaluate(--argc, ++argv);
    printf("\nresult = %d\n", res);

    return 0;
}

