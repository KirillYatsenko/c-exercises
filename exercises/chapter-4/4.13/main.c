#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char[]);
void _reverse(char[], unsigned int, unsigned int);

int main()
{
    char s[] = "nos";
    printf("\n origin = %s ", s);
    reverse(s);
    printf("reversed = %s", s);

    return 0;
}

void reverse(char s[])
{
    _reverse(s, 0, strlen(s) - 1);
}

void _reverse(char s[], unsigned int l, unsigned int r)
{
    if(l >= r)
        return;

    char buff = s[l];
    s[l] = s[r];
    s[r] = buff;

    _reverse(s, ++l, --r);
}
