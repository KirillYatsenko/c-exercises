#include <stdbool.h>
#include <stdio.h>
#include "stack.h"
#include "syntax-analyzer.h"


bool processLine(char line[], bool isComment, Stack* stack);
uint32_t lineSize(char line[]);

bool isOpeningBracket(char bracket);
bool isClosingBracket(char bracket);
char correspondingOpenBracket(char closingBracket);

void processText(char text[][MAXLINE], uint32_t rowsCount)
{
    Stack stack = stackInit(MAXLINE * MAXROWS);

    bool isComment = false;

    for(uint32_t i = 0; i < rowsCount; i++)
        isComment = processLine(text[i], isComment, &stack);

    if(isComment || stackCount(stack) > 0){
        printf("\nERROR");
    }
}

bool processLine(char line[], bool isComment, Stack* stack)
{
    bool quotes = false;
    uint32_t length = lineSize(line);

    for(uint32_t i = 0; i < length; ++i)
    {
        if(isComment && i < length - 1 && line[i] == '*' && line[i + 1] == '/')
        {
            isComment = false;
            ++i;
        }
        else if(!isComment && !quotes)
        {
            if(line[i] == '"')
                quotes = true;

            else if(i < length - 1 && line[i] == '/' && line[i + 1] == '/')
                return false;

            else if(isOpeningBracket(line[i]))
                stackPush(stack, line[i]);

            else if(isClosingBracket(line[i]))
            {
                if(stackCount(*stack) == 0 || stackPop(stack) != correspondingOpenBracket(line[i]))
                {
                    printf("\nERROR: inconsistent brackets");
                    return -1;
                }
            }
        }
        else if(!isComment && quotes && line[i-1] != '\\' && line[i] == '"')
        {
            quotes = false;
        }
    }

    if(quotes)
    {
        printf("\nERROR: no closing double quotes");
        return -1;
    }

    return isComment;
}

uint32_t lineSize(char line[])
{
    uint32_t length;
    for(length = 0; line[length] != '\0'; ++length);

    return length;
}

bool isOpeningBracket(char bracket)
{
    return bracket == '(' || bracket == '[' || bracket == '{';
}

bool isClosingBracket(char bracket)
{
    return bracket == ')' || bracket == ']' || bracket == '}';
}

char correspondingOpenBracket(char closingBracket)
{
   switch (closingBracket)
   {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        default:
            return ' ';
   }
}
