#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _strncmp(const char*, const char*, int);

int main()
{
    int res = _strncmp("abcd", "abce", 3);
    printf("\n res = %d", res);

    return 0;
}

int _strncmp(const char* s, const char* t, int n)
{
    int i;
    for (i = 0; i < n && *s == *t; s++, t++, i++)
        if (*s == '\0')
            return 0;

    if(i == n)
        return 0;

    return *s - *t;
}
