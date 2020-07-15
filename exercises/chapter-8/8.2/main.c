#include "open.h"

int main()
{

    FILE *fp = _fopen("file.txt", "r");
    if(fp == NULL)
        return 1;

    char buf[100];
    int c, i = 0;
    while((c = getc(fp)) != EOF)
        buf[i++] = c;

    buf[i] = '\0';
    return 0;
}
