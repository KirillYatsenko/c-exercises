#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    char s[20];
    itoa(INT_MIN, s);
    printf("\n parsed = %s", s);

    return 0;
}

void itoa(int n, char s[])
{
    unsigned int x;

    int i = 0, sign = 0;
    if (n < 0)
    {
       sign = 1;
       x = -n;
    }
    else
    {
        x = n;
    }

    do {
        s[i++] = x %10 + '0';
    } while ((x /= 10) > 0);

    if (sign)
        s[i++] = '-';
        s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int c,i,j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
