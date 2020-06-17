#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _strcat(char*, const char*);

int main()
{
    char s[10] = "123 ";
    char t[] = "456";
    _strcat(s,t);

    printf("\nconcated = %s", s);

    return 0;
}

void _strcat(char* s, const char* t)
{
    s += strlen(s);

    while(*s++ = *t++);

    *s = '\0';
}
