#include <stdio.h>
#include <stdlib.h>
#include "atof.h"

int main()
{
    char doubleString[] = "120.5e1";

    printf("\norigin string = %s parsed double = %f", doubleString, myatof(doubleString));

    return 0;
}
