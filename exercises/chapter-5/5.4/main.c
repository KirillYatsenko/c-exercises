#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(const char*, const char*);

int main()
{
    int val = strend("12345 111", "111");
    printf("\n res = %d", val);

    return 0;
}

int strend(const char* s, const char* t)
{
    s += strlen(s) - strlen(t);

    while(*s && *s++ == *t++);

    return !*s;
}
