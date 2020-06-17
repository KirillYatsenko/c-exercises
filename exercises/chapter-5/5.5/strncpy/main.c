#include <stdio.h>
#include <stdlib.h>

void _strncpy(const char*, char*, int);

int main()
{
    char s[10];
    char t[] = "1234";
    _strncpy(t, s, 3);

    printf("\ns = %s", s);

    return 0;
}

void _strncpy(const char* t, char* s, int n)
{
    int i;
    for(i = 0; i < n; i++)
        *(s + i) = *(t + i);

    *(s + i) = '\0';
}
