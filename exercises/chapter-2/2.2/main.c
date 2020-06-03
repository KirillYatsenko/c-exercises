#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t lim = 5;
    char s[lim];
    char c;
    size_t i = 5;

    for (i = 0; (i < lim) * ((c=getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;

    s[i] = '\0';

    printf("%s", s);

    return 0;
}
