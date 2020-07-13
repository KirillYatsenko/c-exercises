#include <stdio.h>
#include <stdlib.h>

#define PAGE_LENGTH 5
#define MAX_LINE 1000

void print(char *files[]);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "\nusage: filenames[]");
        exit(1);
    }

    print(++argv);
}

void print(char *files[])
{
    FILE *fp;
    char line[MAX_LINE];
    int linnum;

    for (int page = 1; *files; files++, page++)
    {
        if ((fp = fopen(*files, "r")) == NULL)
            fprintf(stderr, "\nerror: can't open file '%s'", *files);
        else
        {
            for (linnum = 1; fgets(line, MAX_LINE, fp) != NULL; linnum++)
            {
                if (linnum == 1)
                {
                    printf("\n============= %s ==============", *files);
                    printf("\nPage #%d\n\n", page);
                }

                printf("%s", line);

                if (linnum == PAGE_LENGTH)
                {
                    page++;
                    linnum = 0;
                }
            }

            while(linnum++ <= PAGE_LENGTH)
                printf("\n");
        }
    }
}
