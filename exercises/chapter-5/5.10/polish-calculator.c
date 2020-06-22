#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "polish-calculator.h"

#define NUMBER 1000

int getop(char *expression);

int evaluate(unsigned int n, char *expression[])
{
    if (n == 0)
    {
        printf("\n error: expression is empty");
        return -1;
    }

    int op1, op2;
    for (; n-- > 0; expression++)
    {
        int op = getop(*expression);
        switch(op)
        {
            case NUMBER:
                push(atoi(*expression));
                break;

            case '+':
                op1 = pop();
                op2 = pop();
                push(op1 + op2);
                break;

            case '-':
                op1 = pop();
                op2 = pop();
                push(op2 - op1);
                break;

            case '/':
                op1 = pop();
                op2 = pop();
                push(op2 / op1);
                break;

            case '*':
                op1 = pop();
                op2 = pop();
                push(op1 * op2);
                break;

            default:
                printf("\n error: operation not found '%s'", *expression);
                return -1;
        }
    }

    return pop();
}

int getop(char *expression)
{
    if(strcmp("+", expression) == 0)
        return '+';

    if(strcmp("-", expression) == 0)
        return '-';

    if(strcmp("/", expression) == 0)
        return '/';

    if(strcmp("*", expression) == 0)
        return '*';

    for(;*expression != '/0' && isdigit(*expression); expression++);

    return strcmp(expression, "") == 0 ? NUMBER : -1;
}

