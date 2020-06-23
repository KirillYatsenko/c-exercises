#include <stdio.h>
#include "getline.h"

int getLine(char line[], int maxLine)
{
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}
