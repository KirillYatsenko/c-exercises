#include <stdio.h>
#include <stdlib.h>

char lower(char c);

int main()
{
    printf("\nlower %c = %c", 'Z', lower('Z'));
    return 0;
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
