#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <stdio.h>

int (*getfunction(char *name))(int);

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("\nerror: provide 'u' or 'l' arguments\n");
        return -1;
    }

    int (*fun)(int) = getfunction(argv[1]);
    if(fun == NULL)
    {
        printf("\nerror: provide 'u' or 'l' arguments\n");
        return -1;
    } 

    int c;
    while ((c = getchar()) != EOF)
        putchar(fun(c));

    return 0;
}

int (*getfunction(char *name))(int)
{
    if(strcmp(name, "u") == 0)
        return toupper;
    else if(strcmp(name, "l") == 0)
        return tolower;

    return NULL;
}