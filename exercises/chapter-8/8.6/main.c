#include <string.h>
#include <stdio.h>
#include "malloc.h"

int main()
{
    char *s = malloc(20);
    strcpy(s, "kirill");
    printf("\n%s\n", s);

    return 0;
}