#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAXLINE 1000
#define N 10

int main()
{
    char inputLine[MAXLINE];
    uint16_t length;

    while((length = getLine(inputLine, MAXLINE)) > 0){
        newline(inputLine, 0, length);
        printf("%s\n", inputLine);
    }
}

void newline(char input[], uint16_t index, uint16_t length)
{
    if(length - index <= N)
        return;

    uint16_t nextStop = (index / N + 1) * N + 1;
    int32_t delimeter;

    for(delimeter = nextStop; delimeter >= index && input[delimeter] != ' ' && input[delimeter] != '\t'; --delimeter);

    if(delimeter != index - 1 && delimeter > 0)
        input[delimeter] = '\n';

    newline(input, nextStop, length);
}

int getLine(char line[], int maxLine){
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}
