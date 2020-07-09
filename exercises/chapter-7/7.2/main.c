#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char *printable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#%&'()*+,-./:;<=>?[\\]^_{|}~\t\f\v\r\n";

int main(int argc, char *argv[])
{
    char *base;
    if (argc == 1 || (strcmp(argv[1], "%x") != 0 && strcmp(argv[1], "%o") != 0))
    {
        printf("\nprovide '%x' - for hex or '%o' for octal\n");
        return 1;
    }

    base = argv[1];
    int c, i;

    for (i = 1; (c = getchar()) != EOF; i++)
    {
        if (i > MAX_LENGTH)
        {
            putchar('\n');
            i = 0;
        }

        if (strchr(printable, c) != NULL)
        {
            printf("%c", c);
        }
        else
        {
            printf(base, c);
        }
    }

    return 0;
}