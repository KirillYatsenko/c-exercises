#include <stdio.h>
#include <stdlib.h>
#include "getint.h"

int main()
{
    int x = 0;

    getint(&x);

    printf("\n new value = %d", x);

    return 0;
}
