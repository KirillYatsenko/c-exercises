#include "open.h"

int main()
{
    FILE *fp = fopen("file.txt", "r");
    if(fp == NULL)
        return 1;

    int c;
    while((c = getc(fp)) != EOF)
        putc(c, stdout);

    fclose(stdout);
    return 0;
}
