#include "detab.h"

void detab(char inputLine[], char outputLine[], int length, int startindx, int tablength)
{
    int outputLineIndex = 0;
    for(int inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        if(inputLine[inputLineIndex ] == '\t' && inputLineIndex >= startindx)
        {
            int nextTabPosition = (inputLineIndex / tablength + 1)* tablength;

            for(int z = outputLineIndex; z < nextTabPosition; ++z, ++outputLineIndex)
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
