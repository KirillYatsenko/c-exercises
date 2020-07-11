#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "itoa.h"

void minprintf(char *fmt, ...);
int getnumber(char **p);

int main()
{
    minprintf("%30.3f sdf\n", 10.234234);
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmtarg, ...)
{
    char *fmt = malloc(strlen(fmtarg));
    strcpy(fmt, fmtarg);

    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmtarg); /* make ap point to 1st unnamed arg */
    int width = -1;
    int precision = -1;

    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        width = -1;
        precision = -1;

        if (isdigit(*(++p)))
        {
            width = 0;
            width += *p - '0';
            while (isdigit(*++p))
                width = width * 10 + (*p - '0');
        }

        if (*p == '.')
        {
            precision = 0;
            precision += *(++p) - '0';
            while (isdigit(*++p))
                precision = precision * 10 + (*p - '0');
        }

        switch (*p)
        {
        case 'd':
            ival = va_arg(ap, int);
            char format[100] = "%";
            strcat(format, width > 0 ? itoa(width) : "");
            strcat(format, "d");
            printf(format, ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            char formatf[100] = "%";
            strcat(formatf, width > 0 ? itoa(width) : "");

            if (precision > 0)
            {
                strcat(formatf, ".");
                strcat(formatf, itoa(precision));
            }
            strcat(formatf, "f");
            printf(formatf, dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); /* clean up when done */
}

void _printfint(char *format, va_list *ap)
{
    int ival = va_arg(*ap, int);

    if (!ival)
        printf("\nerror: mismatched number of args\n");
    else
        printf(format, ival);
}