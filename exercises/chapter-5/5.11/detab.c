#include "detab.h"

void detab(char inputLine[], char outputLine[], int length)
{
    int outputLineIndex = 0;
    for(int inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        int nextTabPosition = (outputLineIndex / TAB_LENGTH + 1)* TAB_LENGTH - outputLineIndex;

        if(inputLine[inputLineIndex ] == '\t')
        {
            for(int z = 0; z < nextTabPosition; ++z, ++outputLineIndex)
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
