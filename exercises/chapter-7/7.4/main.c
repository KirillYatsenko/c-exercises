#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void minscanf(char *fmtarg, ...);

int main()
{
    int i;
    double d;
    char s[200];

    minscanf("%d %f %s", &i, &d, s);

    printf("\n\ni:%d d:%f s:%s\n\n", i, d, s);
}

void minscanf(char *fmtarg, ...)
{
    char *fmt = malloc(strlen(fmtarg));
    strcpy(fmt, fmtarg);

    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int *ival;
    double *dval;
    va_start(ap, fmtarg); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*(++p))
        {
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double *);
            scanf("%lf", dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s", sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}
