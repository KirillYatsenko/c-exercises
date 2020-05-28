#include <stdbool.h>
#include <stdio.h>
#include "stack.h"
#include "syntax-analyzer.h"


bool processLine(char line[], uint32_t rowNumber, bool isComment, Stack* stack, ProcessResult* result);
uint32_t lineSize(char line[]);

bool isOpeningBracket(char bracket);
bool isClosingBracket(char bracket);
char correspondingOpenBracket(char closingBracket);

ProcessResult processText(char text[][MAXLINE], uint32_t rowsCount)
{
    ProcessResult result;
    result.status = Success;

    Stack stack = stackInit(MAXLINE * MAXROWS);

    bool isComment = false;

    uint32_t rowNumber;
    for(rowNumber = 0; result.status == Success && rowNumber < rowsCount; ++rowNumber)
        isComment = processLine(text[rowNumber], rowNumber, isComment, &stack, &result);

    if(result.status != Success)
        return result;

    if(isComment)
    {
        result.status = ErrorUnterminatedComment;
        result.errorRow = rowNumber;
        result.errorColumn = 0;
    }
    else if(stackCount(stack) > 0){
        result.status = ErrorUnclosedBrackets;
        result.errorRow = rowNumber;
        result.errorColumn = 0;
    }

    return result;
}

bool processLine(char line[], uint32_t rowNumber, bool isComment, Stack* stack, ProcessResult* result)
{
    bool quotes = false;
    uint32_t length = lineSize(line);
    uint32_t i;

    for(i = 0; i < length; ++i)
    {
        // closing multiline comment
        if(isComment && i < length - 1 && line[i] == '*' && line[i + 1] == '/')
        {
            isComment = false;
        }
        else if(!isComment && !quotes) // not ignoring
        {
            if(line[i] == '"') // dobule quotes start
                quotes = true;

            else if(i < length - 1 && line[i] == '/' && line[i + 1] == '*') // multiline comment
                isComment = true;

            else if(i < length - 1 && line[i] == '/' && line[i + 1] == '/') // single line comment
                return false;

            else if(isOpeningBracket(line[i]))
                stackPush(stack, line[i]);

            else if(isClosingBracket(line[i]))
            {
                if(stackCount(*stack) == 0 || stackPop(stack) != correspondingOpenBracket(line[i]))
                {
                    result->status = ErrorInconsistentBracket;
                    result->errorRow = rowNumber;
                    result->errorColumn = i;
                    break;
                }
            }
        }
        // closing double quotes
        else if(!isComment && quotes && line[i-1] != '\\' && line[i] == '"')
        {
            quotes = false;
        }
    }

    if(quotes)
    {
        result->status = ErrorOpenedDoubleQuotes;
        result->errorRow = rowNumber;
        result->errorColumn = i;
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
