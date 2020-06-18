#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int, char*);
void reverse(char*);

int main()
{
    int n = -2230;
    char s[20];
    itoa(n, s);

    printf("\n n = %d, s = %s", n, s);

    return 0;
}

void itoa(int n, char* s)
{
    char* t = s;
    size_t un = n;
    int sign = 0;

    if(n < 0)
    {
        un = -n;
        sign = 1;
        *(s++) = '-';
    }

    while(un)
    {
        *(s++) = un % 10 + '0';
        un /= 10;
    }

    *s = '\0';

    return sign == 0 ? reverse(t) : reverse(t+1);
}

void reverse(char* s)
{
    int i = 0;
    int j = strlen(s) - 1;

    for(; i < j ; i++, j--){
        char buf = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = buf;
    }
}
