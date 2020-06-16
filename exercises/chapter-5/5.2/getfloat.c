#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "getfloat.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch (void);
void ungetch (int);

int getfloat(float *pn)
{
    int c, sign;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch (c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        char temp = c;
        c = getch();

        if(!isdigit(c))
        {
            ungetch(c);
            ungetch(temp);

            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c -'0');

    int power = 1;

    if (c == '.')
    {
        float ab = *pn;

        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
    }

    *pn = *pn/power * sign;

    if (c != EOF)
        ungetch(c);

    return c;
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

