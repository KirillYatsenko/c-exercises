#include "dcl.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

int validatetype(char *type);
int gettoken(void);
void _dcl(void);
void dirdcl(void);

enum
{
    NAME,
    PARENS,
    BRACKETS,
};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

char* line;
int linep = 0;

int iserror = 0;
char *supportedtypes[] = {"int", "char", "double", "void"};

void dcl(char *linearg, char *res)
{
    line = linearg;
    linep = 0;

    if (gettoken() == EOF)
        return;

    if (!validatetype(token))
    {
        printf("error: '%s' type is not recognized\n", token);
        return;
    }

    /* 1st token on line */
    strcpy(datatype, token); /* is the datatype */
    out[0] = '\0';
    _dcl();

    if (!iserror)
        sprintf(res, "%s: %s %s\n", name, out, datatype);
}

int validatetype(char *type)
{
    for (int i = 0; *(supportedtypes + i); i++)
        if (strcmp(*(supportedtypes + i), type) == 0)
            return 1;

    return 0;
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(void);
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch();
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';

        for (int i = 1; i < strlen(token) - 1; i++)
            if (!isdigit(*(token + i)))
            {
                printf("\nerror: '%s' - value inside the '[]' should be an integer\n", token);
                iserror = 1;
            }

        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch();

        int iserror = 0;
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

void _dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype == '(')
    {
        /* ( dcl ) */
        _dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int getch(void)
{
    if(linep == strlen(line))
        return EOF;
    
    return line[linep++];
}

void ungetch()
{
    if(linep == 0)
        printf("\nerror: can't ungetch");

    linep--;
}
