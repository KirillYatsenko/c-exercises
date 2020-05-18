#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAXLINE 1000
#define TAB_LENGTH 8

int main()
{
    char inputLine[MAXLINE * 2];
    char outputLine[MAXLINE];
    uint16_t length;

    while((length = getLine(inputLine, MAXLINE)) > 0){
        entab(inputLine, outputLine, length);
        printf("%s\n", outputLine);
    }
}

void entab(char inputLine[], char outputLine[], uint16_t length)
{
    uint16_t outputLineIndex = 0;
    for(uint16_t inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        if(inputLine[inputLineIndex] != ' '){
                outputLine[outputLineIndex] = inputLine[inputLineIndex];
                ++outputLineIndex;
                continue;
        }

        uint16_t nextTabPosition = (inputLineIndex / TAB_LENGTH + 1)* TAB_LENGTH;
        uint8_t countSpaces = 0;

        for(; inputLine[inputLineIndex] == ' ' && inputLineIndex < nextTabPosition;  ++countSpaces ,++inputLineIndex);

        if(inputLineIndex == nextTabPosition)
        {
            outputLine[outputLineIndex] = '\t';
            ++outputLineIndex;
        }
        else
        {
            for(uint8_t j = 0; j < countSpaces; ++j,++outputLineIndex)
                outputLine[outputLineIndex] = ' ';
        }

        --inputLineIndex;
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
