#include <stdio.h>
#include <stdlib.h>

int atoi(const char*);

int main()
{
    char s[] = "-123";
    int converted = atoi(s);
    printf("\n string = %s, converted = %d", s, converted);

    return 0;
}

int atoi(const char* s)
{
    int res = 0;
    int sign = *s == '-'? -1 : 1;

    if(sign < 0)
        s++;

    while(*s != '\0')
        res = res * 10 + *(s++) - '0';

    return res * sign;
}
