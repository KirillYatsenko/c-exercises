#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100

int _getline(char*, int);

int main()
{
    char s[MAX_LINE];
    _getline(s, MAX_LINE);

    printf("\n s = %s", s);

    return 0;
}

int _getline(char* s, int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(s + i) = c;

    if (c == '\n') {
        *(s + i) = c;
        ++i;
    }

    *(s + i) = '\0';

    return i;
}
