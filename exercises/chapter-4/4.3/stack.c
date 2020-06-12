#include "stack.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peak(void)
{
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicatehead(void)
{
    if (sp == 0)
        printf("error: stack empty\n");
    else if (sp == MAXVAL)
         printf("error: stack full, can't duplicate head\n");
    else
        val[sp++] = val[sp - 1];
}

void swaphead(void)
{
    if(sp < 2)
        printf("error: not enough elements for swapping\n");
    else
    {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
}

void clear(void)
{
    sp = 0;
}
