#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAXLINE 1000
#define TAB_LENGTH 8

int main()
{
    char inputLine[MAXLINE];
    char outputLine[MAXLINE * 2];
    uint16_t length;

    while((length = getLine(inputLine, MAXLINE)) > 0){
        detab(inputLine, outputLine, length);
        printf("%s\n", outputLine);
    }
}

void detab(char inputLine[], char outputLine[], uint16_t length)
{
    uint16_t outputLineIndex = 0;
    for(uint16_t inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        uint16_t nextTabPosition = (outputLineIndex / TAB_LENGTH + 1)* TAB_LENGTH - outputLineIndex;

        if(inputLine[inputLineIndex ] == '\t')
        {
            for(uint8_t z = 0; z < nextTabPosition; ++z, ++outputLineIndex)
                outputLine[outputLineIndex]= ' ';
        }
        else
        {
            outputLine[outputLineIndex] = inputLine[inputLineIndex];
            ++outputLineIndex;
        }
    }

    outputLine[outputLineIndex] = '\0';
}

int getLine(char line[], int maxLine){
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}
