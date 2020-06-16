#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch (void);
void ungetch (int);

int getint(int *pn)
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

    *pn *= sign;

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
