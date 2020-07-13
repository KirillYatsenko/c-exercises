#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1000

int compare(char *file1, char *file2, char *line);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "\nplease provide two files' paths\n");
        exit(1);
    }

    char line[MAX_LINE];
    int cmpr = compare(*(++argv), *(++argv), line);

    if (cmpr == -1)
        printf("\nfiles are equal\n");
    else
        printf("\nline: #%d - %s", cmpr + 1, line);
}

int compare(char *file1, char *file2, char *line)
{
    int index;
    FILE *fp1, *fp2;
    char s1[MAX_LINE], s2[MAX_LINE];
    char *s1p, *s2p;

    if ((fp1 = fopen(file1, "r")) == NULL)
    {
        fprintf(stderr, "\nerror: file '%s' can't be opened\n", file1);
        exit(1);
    }

    if ((fp2 = fopen(file2, "r")) == NULL)
    {
        fprintf(stderr, "\nerror: file '%s' can't be opened\n", file2);
        exit(1);
    }

    for (index = 0; (s1p = fgets(s1, MAX_LINE, fp1)) != NULL && (s2p = fgets(s2, MAX_LINE, fp2)) != NULL; index++)
    {
        if (strcmp(s1, s2) != 0)
        {
            strcpy(line, s1);
            return index;
        }
    }

    if (s1p != s2p)
    {
        if (s1p != NULL)
            strcpy(line, s1p);
        else
            strcpy(line, s2p);

        strcpy(line, "one file has more lines than another");
        return index;
    }

    return -1;
}