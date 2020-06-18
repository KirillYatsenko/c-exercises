#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strindex(const char*, const char*);

int main()
{
    char s[] = "abc";
    char t[] = "ab";
    int indx = strindex(s, t);
    printf("\n indx = %d", indx);

    return 0;
}

int strindex(const char* s, const char* t)
{
    int i, j;

    for(i = 0; i < strlen(s); i++){

        for(j = 0; j < strlen(t) && i + j < strlen(s) && *(s + i + j) == *(t + j); j++);

        if(j == strlen(t))
            return i;
    }

    return -1;
}
