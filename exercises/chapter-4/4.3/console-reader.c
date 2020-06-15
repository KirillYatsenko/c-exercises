#include <stdio.h>
#include "console-reader.h"

int readline(char line[], int maxlength){
    int c, length;
    for(length = 0; length < maxlength - 1 && (c = getchar()) != EOF && c!= '\n'; ++length)
        line[length] = c;

    line[length] = '\0';
    return length;
}
