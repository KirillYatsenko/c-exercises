#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define MAXLINE 1000


/*
    Note:
        I know this code can be improved by using structures, enums
        But I was trying to use only information covered by the first chapter

*/


int getLine(char line[], uint32_t maxline);

// return value is the status
uint8_t process(char line[], uint32_t length, bool comment, uint32_t stackSize, uint8_t* stackBase, uint8_t* stackHead);


int main()
{
    char line[MAXLINE];
    uint32_t length;
    bool comment = false;

    uint8_t* stackBase;
    uint8_t* stackHead;
    stackInit(MAXLINE, &stackBase, &stackHead);

    while((length = getLine(line, MAXLINE)) > 0){
        comment = process(line, length, comment, MAXLINE, stackBase, stackHead);
    }

    if(comment || stackCount(stackBase, stackHead) > 0){
        printf("\nERROR");
    }

    return 0;
}

int getLine(char line[], uint32_t maxline){
    int c, i;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}

uint8_t process(char line[], uint32_t length, bool comment, uint32_t stackSize, uint8_t* stackBase, uint8_t* stackHead)
{
    bool quotes = false;

    for(uint32_t i = 0; i < length; ++i)
    {
        if(comment && i < length - 1 && line[i] == '*' && line[i + 1] == '/')
        {
            comment = false;
            ++i;
        }
        else if(!comment && !quotes && i < length - 1 && line[i] == '/' && line[i + 1] == '/')
        {
            return false;
        }
        else if(!comment && !quotes && line[i] == '"')
        {
            quotes = true;
        }
        else if(!comment && quotes && line[i-1] != '\\' && line[i] == '"')
        {
            quotes = false;
        }
        else if(!comment && !quotes && (line[i] == '(' || line[i] == '[' || line[i] == '{'))
        {
            stackPush(stackBase, &stackHead, line[i], stackSize);
        }
        else if(!comment && !quotes && line[i] == ')')
        {
            if(stackCount(stackBase, stackHead) == 0 || stackPop(stackBase, &stackHead) != '(')
            {
                printf("\nERROR: inconsistent brackets");
                return -1;
            }
        }
        else if(!comment && !quotes && line[i] == ']')
        {
            if(stackCount(stackBase, stackHead) == 0 || stackPop(stackBase, &stackHead) != '[')
            {
                printf("\nERROR: inconsistent brackets");
                return -1;
            }
        }
        else if(!comment && !quotes && line[i] == '}')
        {
            if(stackCount(stackBase, stackHead) == 0 || stackPop(stackBase, &stackHead) != '{')
            {
                printf("\nERROR: inconsistent brackets");
                return -1;
            }
        }

    }

    if(quotes)
    {
        printf("\nERROR: no closing double quotes");
        return -1;
    }

    return comment;
}
