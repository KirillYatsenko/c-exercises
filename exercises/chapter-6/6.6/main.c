#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getline.h"
#include "table.h"

int processline(char *newline, char *word, char *line, int indx);

int main()
{
    char line[MAX_LINE];
    int length;

    while ((length = _getline(line, MAX_LINE)) > 0)
    {
        int indx = 0;
        char word[MAX_WORD] = "\0";
        char newline[MAX_LINE] = "\0";
        while ((indx = getword(line, word, MAX_LINE, indx)) < length)
        {
            indx = processline(newline, word, line, indx);
        }
        
        printf("%s\n", newline);
    }

    return 0;
}

int processline(char *newline, char *word, char *line, int indx)
{
    char name[MAX_WORD];
    char def[MAX_WORD];

    if (strcmp(word, "#define") == 0)
    {
        // copy definition
        indx = getword(line, word, MAX_LINE, indx); // empty space
        indx = getword(line, word, MAX_LINE, indx);
        strcpy(name, word);

        // copy value
        indx = getword(line, word, MAX_LINE, indx); // empty space
        indx = getword(line, word, MAX_LINE, indx);
        strcpy(def, word);

        install(name, def);

        *newline = '\0';
    }
    else
    {
        struct nlist *prev, *tp = lookup(word, &prev);
        if (tp != NULL)
        {
            strcat(newline, tp->defn);
        }
        else
        {
            strcat(newline, word);
        }
    }

    return indx;
}