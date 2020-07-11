
#include <stdlib.h>
#include <string.h>
#include "itoa.h"

#define MAX_NUMBER_LENGTH 20

void reverse(char *s);

char *itoa(int n)
{
    char *s = malloc(MAX_NUMBER_LENGTH);
    char *t = s;
    size_t un = n;
    int sign = 0;

    if (n < 0)
    {
        un = -n;
        sign = 1;
        *(s++) = '-';
    }

    while (un)
    {
        *(s++) = un % 10 + '0';
        un /= 10;
    }

    *s = '\0';

    sign == 0 ? reverse(t) : reverse(t + 1);

    return t;
}

void reverse(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;

    for (; i < j; i++, j--)
    {
        char buf = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = buf;
    }
}