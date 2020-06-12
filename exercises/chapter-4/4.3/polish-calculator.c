#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "polish-calculator.h"
#include "stack.h"

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100

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
        return c;

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
