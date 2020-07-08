#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getline.h"

int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int getword(char *line, char *word, int lim, int indx)
{
    int c, getch(char *line, int *indx);
    void ungetch(int *);
    char *w = word;

    if (isspace(c = getch(line, &indx)))
    {
        *w++ = c;
        while (isspace(c = getch(line, &indx)))
            *w++ = c;

        ungetch(&indx);
        *w = '\0';
        return indx;
    }

    if (c != EOF)
        *w++ = c;

    if (!isalnum(c) && c != '#')
    {
        *w = '\0';
        return indx;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch(line, &indx)))
        {
            ungetch(&indx);
            break;
        }
    *w = '\0';
    return indx;
}

int getch(char *line, int *indx)
{
    if (*indx == strlen(line))
    {
        (*indx)++;
        return EOF;
    }

    return line[(*indx)++];
}

void ungetch(int *indx)
{
    if (*indx == 0)
        printf("error: cant ungetch 0 index");
    else
        (*indx)--;
}