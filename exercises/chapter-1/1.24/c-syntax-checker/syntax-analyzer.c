#include <stdbool.h>
#include "stack.h"
#include "syntax-analyzer.h"


uint8_t processLine(char line[], bool comment, Stack* stack);
uint32_t linesize(char line[]);


void processText(char text[][MAXLINE], uint32_t rowsCount)
{
    Stack stack = stackInit(MAXLINE * MAXROWS);

    bool comment = false;

    for(uint32_t i = 0; i < rowsCount; i++)
        comment = processLine(text[i], comment, &stack);

    if(comment || stackCount(stack) > 0){
        printf("\nERROR");
    }
}

uint8_t processLine(char line[], bool comment, Stack* stack)
{
    bool quotes = false;
    uint32_t length = linesize(line);

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
            stackPush(stack, line[i]);
        }
        else if(!comment && !quotes && line[i] == ')')
        {
            if(stackCount(*stack) == 0 || stackPop(stack) != '(')
            {
                printf("\nERROR: inconsistent brackets");
                return -1;
            }
        }
        else if(!comment && !quotes && line[i] == ']')
        {
               if(stackCount(*stack) == 0 || stackPop(stack) != '[')
            {
                printf("\nERROR: inconsistent brackets");
                return -1;
            }
        }
        else if(!comment && !quotes && line[i] == '}')
        {
            if(stackCount(*stack) == 0 || stackPop(stack) != '{')
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

uint32_t linesize(char line[])
{
    uint32_t length;
    for(length = 0; line[length] != '\0'; ++length);

    return length;
}
