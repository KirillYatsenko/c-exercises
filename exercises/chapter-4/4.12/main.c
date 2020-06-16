#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void itoa(int, char[]);
void helper(int, int, int*, char[]);

int main()
{
    char s[100];
    int value = INT_MIN;

    itoa(value, s);
    printf("\nvalue = %d converted = %s", value, s);

    return 0;
}

void itoa(int n, char s[])
{
    int i = 0;
    helper(n, n, &i, s);
}

void helper(int n, int origin, int* i, char s[])
{
    unsigned int un = n;

    if (n < 0) {
        s[(*i)++] = '-';
        un = -n;
    }

    if (un / 10)
        helper(un / 10, origin, i, s);

    s[(*i)++] = un % 10 + '0';

    if (n == origin)
        s[*i] = '\0';
}
