#include "detab.h"

void detab(char inputLine[], char outputLine[], int length, int tabscount, char *tabs[])
{
    if(tabscount == 0)
    {
        printf("error: tabs list can't be empty");
        return;
    }

    int tabindx = 0;
    int outputLineIndex = 0;
    for(int inputLineIndex = 0; inputLineIndex < length; ++inputLineIndex)
    {
        if(inputLine[inputLineIndex ] == '\t')
        {
            int nextTabPosition;
            for(; tabindx < tabscount &&  outputLineIndex > (nextTabPosition = atoi(*(tabs + tabindx))); tabindx++);

            if(nextTabPosition <= outputLineIndex)
            {
                printf("\nerror: there is not next tab in the tab list\n");
                return;
            }

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
