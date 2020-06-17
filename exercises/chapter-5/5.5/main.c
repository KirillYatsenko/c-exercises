#include <stdio.h>
#include <stdlib.h>

void strcpy(const char*, char*, int);

int main()
{
    char s[10];
    char t[] = "1234";
    strcpy(t, s, 3);

    printf("\ns = %s", s);

    return 0;
}

void strcpy(const char* t, char* s, int n)
{
    int i;
    for(i = 0; i < n; i++)
        *(s + i) = *(t + i);

    *(s + i) = '\0';
}
