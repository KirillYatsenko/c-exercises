#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "malloc.h"

char x[100];

int main()
{
    _bfree(x, 100);
    char *x = _malloc(200);
    strcpy(x, "lalala");
    printf("\ns:%s", x);

    return 0;
}