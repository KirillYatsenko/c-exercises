#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define MAXLINE 1000
#define MAXROWS 500

int getLine(char line[], uint32_t maxline);
void processText(char text[][MAXLINE], uint32_t size);

// return value is the status
uint8_t processLine(char line[], bool comment, Stack* stack);
uint32_t linesize(char line[]);

int main()
{
    char text[MAXROWS][MAXLINE];
    char line[MAXLINE];
    uint32_t length;
    uint32_t rows;

    for (rows = 0; rows < MAXROWS && (length = getLine(line, MAXLINE)) > 0; ++rows)
        strncpy(text[rows], line, length);

    processText(text, rows);

    return 0;
}


int getLine(char line[], uint32_t maxline){
    int c, i;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}

void processText(char text[][MAXLINE], uint32_t size)
{

    Stack stack = stackInit(MAXLINE * MAXROWS);

    bool comment = false;

    for(uint32_t i = 0; i < size; i++)
        comment = processLine(text[i], comment, &stack);

 //   printf("%d", stackCount(stackBase, stackHead));
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