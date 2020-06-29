#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

int gettoken(void);
void ungetoken();
int needparenthesis(void);

enum
{
    NAME,
    PARENS,
    BRACKETS,
    ASTERISK
};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

int tokentypebuf[BUFSIZE];
char *tokenbuf[BUFSIZE];
int tokenbufp = 0;

int main()
{
    int type;
    char temp[MAXTOKEN];
    if (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == ASTERISK)
            {
                if (needparenthesis())
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);

                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
    }

    printf("\n%s\n\n", out);

    return 0;
}

int needparenthesis(void)
{
    int tkntype = gettoken();
    ungetoken();

    if (tkntype == PARENS || tkntype == BRACKETS)
    {
        return 1;
    }

    return 0;
}

void ungetoken()
{
    tokentypebuf[tokenbufp] = tokentype;

    if(tokentype == PARENS  || tokentype == BRACKETS )
    {
        tokenbuf[tokenbufp] = malloc(strlen(token));
        strcpy(tokenbuf[tokenbufp], token);
    }

    tokenbufp++;
}

int gettoken(void) /* return next token */
{
    if (tokenbufp > 0)
    {
        if(tokentypebuf[tokenbufp] == PARENS || tokentypebuf[tokenbufp] == BRACKETS)
            strcpy(token, tokenbuf[tokenbufp]);

        return tokentypebuf[--tokenbufp];
    }

    int c, getch(void);
    void ungetch(int);
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
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else if (c == '*')
        return tokentype = ASTERISK;
    else
        return tokentype = c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}