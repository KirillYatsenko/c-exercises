#include "entab.h"

void entab(char inputLine[], char outputLine[], int length, int tabscount, char *tabs[])
{
    int tabindx = 0;
    int outputLineIndex = 0;
    for(int inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        if(inputLine[inputLineIndex] != ' '){
                outputLine[outputLineIndex] = inputLine[inputLineIndex];
                ++outputLineIndex;
                continue;
        }

        int nextTabPosition;
        for(;tabindx < tabscount &&  inputLineIndex >= (nextTabPosition = atoi(*(tabs + tabindx))); tabindx++);

        if(nextTabPosition <= inputLineIndex)
        {
            printf("\nerror: there is not next tab in the tab list\n");
            return;
        }

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
