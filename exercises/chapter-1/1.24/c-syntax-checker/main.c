#include <stdio.h>
#include <stdlib.h>
#include "syntax-analyzer.h"


int getLine(char line[], uint32_t maxline);


int main()
{
    char text[MAXROWS][MAXLINE];
    char line[MAXLINE];
    uint32_t lineLength;
    uint32_t rowsCount;

    for (rowsCount = 0; rowsCount < MAXROWS && (lineLength = getLine(line, MAXLINE)) > 0; ++rowsCount)
        strncpy(text[rowsCount], line, lineLength);

    processText(text, rowsCount);

    return 0;
}

int getLine(char line[], uint32_t maxlineLength){
    int c, length;
    for(length = 0; length < maxlineLength - 1 && (c = getchar()) != EOF && c!= '\n'; ++length)
        line[length] = c;

    line[length] = '\0';
    return length;
}
