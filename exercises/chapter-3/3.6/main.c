#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b, int fieldsize);
void reverse(char s[]);

int main()
{
    char s[20];
    itob(-254, s, 16, 4);
    printf("\n parsed =%s", s);

    return 0;
}

void itob(int n, char s[], int b, int fieldsize)
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
        s[i++] =  x % b <= 9 ? x % b + '0' : x % b - 10 + 'A';
    } while ((x /= b) > 0);

    if (sign)
        s[i++] = '-';

    while(i < fieldsize)
        s[i++] = ' ';

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
