#include <stdio.h>
#include <stdlib.h>
#include "polish-calculator.h"

int main(int argc, char *argv[])
{
    int res = evaluate(--argc, ++argv);
    printf("%d\n", res);
}

