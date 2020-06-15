#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "polish-calculator.h"
#include "stack.h"
#include "console-reader.h"

#define MAXOP 100
#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VAR '20'
#define MAXLINE 1000


double variables[25];
int varp = -1;

char line[MAXLINE];
int linep = 0;
int linelength;

int getop (char []);
int getch(void);
void ungetch(void);
void ungets(char s[]);


void calculate()
{
    linelength = readline(line, MAXLINE);

    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();

                if (op1 + 0.1 != (int)op1 + 0.1  || op2 + 0.1 != (int)op2 + 0.1)
                    printf("error: Modulus division is only defined for integers");
                else if (op2 != 0.0)
                    push((int)op1 % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case SIN:
                op1  = pop();
                double sinus = sin(op1);
                push(sinus);

                break;

            case EXP:
                op1 = pop();
                double exponent = exp(op1);
                push(exponent);

                break;
            case POW:
                op1 = pop();
                op2 = pop();
                double power = pow(op2, op1);
                push(power);

                break;

            case '=':
                op1 = pop();
                variables[varp] = op1;

                break;
            case VAR:
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    printf("\t%.8g\n", pop());
}

int getop(char s[])
{
    int i,c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c!= '.')
    {
        char function[10];
        function[0] = c;

        if(c == '!')
        {
            if((c = getch()) < 'a'|| c > 'z')
                printf("error: after ! sign should be single-symbol variable name");

            int pos = c - 'a';
            push(variables[c - 'a']);
            return VAR;
        }

        int j = 1;
        while((c = getch()) >= 'a' && c <= 'z')
            function[j++] = c;

        if(c != EOF)
           ungetch();

        function[j] = '\0';

        if(strcmp(function, "sin") == 0)
            return SIN;
        else if (strcmp(function, "exp") == 0)
            return EXP;
        else if (strcmp(function, "pow") == 0)
            return POW;
        else if (function[0] >= 'a' && function[0] <= 'z')
        {
            varp = function[0] - 'a';
            return VAR;
        }
        else
            return function[0];
    }


    i = 0;
    if(s[i] == '-')
        s[i++] = '-';

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
        ungetch();

    return NUMBER;
}

int getch(void)
{
    if(linep == linelength)
        return EOF;

    return line[linep++];
}

void ungetch(void)
{
    if(linep == 0)
        printf("\n error: index of the line is equal to zero");

    linep--;
}

void ungets(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        ungetch();
}
