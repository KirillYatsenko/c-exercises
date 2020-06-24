#include "entab.h"

void entab(char inputLine[], char outputLine[], int length, int startindx, int tablength)
{
    int outputLineIndex = 0;
    for(int inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        if(inputLine[inputLineIndex] != ' ' || inputLineIndex < startindx ){
                outputLine[outputLineIndex++] = inputLine[inputLineIndex];
                continue;
        }

        int nextTabPosition = (inputLineIndex / tablength + 1)* tablength;
        int countSpaces = 0;

        for(; inputLine[inputLineIndex] == ' ' && inputLineIndex < nextTabPosition;  ++countSpaces ,++inputLineIndex);

        if(inputLineIndex == nextTabPosition)
        {
            outputLine[outputLineIndex] = '\t';
            ++outputLineIndex;
        }
        else
        {
            for(int j = 0; j < countSpaces; ++j,++outputLineIndex)
                outputLine[outputLineIndex] = ' ';
        }

        --inputLineIndex;
    }

    outputLine[outputLineIndex] = '\0';
}
