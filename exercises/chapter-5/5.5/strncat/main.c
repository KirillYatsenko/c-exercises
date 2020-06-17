#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _strncat(char*, const char*, int);

int main()
{
    char s[10] = "123 ";
    char t[] = "456";
    _strncat(s, t, 2);

    printf("\ns = %s", s);

    return 0;
}

void _strncat(char* s, const char* t, int n)
{
    int i;
    s += strlen(s);

    for(i = 0; i < n; i++)
        *(s + i) = *(t + i);

    *(s + i) = '\0';
}
