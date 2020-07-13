#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int find(FILE *fp, char *filename, char *pattern, int except, int number);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    int c, except = 0, number = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                exit(1);
                break;
            }

    if (argc == 0)
        printf("Usage: find -x -n pattern\n");
    else if (argc == 1)
        found = find(stdin, "stdin", *argv, except, number);
    else
    {
        FILE *fp;
        char *pattern = *(argv);

        while (*(++argv))
        {
            if ((fp = fopen(*argv, "r")) == NULL){
                fprintf(stderr, "\nerror: can't open '%s' file\n", *argv);
                exit(1);
            }

            found += find(fp, *argv, pattern, except, number);
        }
    }

    return found;
}

int find(FILE *fp, char *filename, char *pattern, int except, int number)
{
    int found = 0, lineno = 0;
    char line[MAXLINE];

    while (fgets(line, MAXLINE, fp) != NULL)
    {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except)
        {
            if (number)
                printf("%d - ", lineno);

            printf("'%s' - %s", filename, line);
            found++;
        }
    }

    return found;
}