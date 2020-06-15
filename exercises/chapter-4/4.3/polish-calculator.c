#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "polish-calculator.h"
#include "stack.h"

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define SIN '1'
#define EXP '2'
#define POW '3'

char buf[BUFSIZE];
int bufp = 0;

int getop (char []);
int getch(void);
void ungetch(int c);

void calculate()
{
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
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

        int j = 1;
        while((c = getch()) >= 'a' && c <= 'z')
            function[j++] = c;

        ungetch(c);
        function[j] = '\0';

        if(strcmp(function, "sin") == 0)
            return SIN;
        else if (strcmp(function, "exp") == 0)
            return EXP;
        else if (strcmp(function, "pow") == 0)
            return POW;
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
        ungetch(c);

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: buffer is full\n");
    else
        buf[bufp++] = c;
}
