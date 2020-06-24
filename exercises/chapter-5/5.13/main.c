#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define LINES_COUNT 30

void tail(int n, int lines_count, char* lines[]);
int getLine(char line[], int maxLine);
void parseArguments(int argc, char *argv[], int* n);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int length;

    int n = 10;
    int lines_count = 0;
    char *lines[LINES_COUNT];

    parseArguments(argc, argv, &n);

    while((length = getLine(line, MAXLINE)) > 0 && lines_count < LINES_COUNT){
        *(lines + lines_count) = (char*)malloc(length);
        strcpy(*(lines + lines_count++), line);
    }

    tail(n, lines_count, lines);

    return 0;
}

void parseArguments(int argc, char *argv[], int* n)
{
    for (int i = 1; i < argc; i++)
    {
        char *arg = *(argv + i);
        if(*arg == '-')
        {
            *n = atoi(arg + 1);
            return;
        }
    }
}

int getLine(char line[], int maxLine)
{
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}

void tail(int n, int lines_count, char* lines[])
{
    int indx = lines_count > n ? lines_count - n : 0;
    for(int i = 1; indx < lines_count; indx++, i++)
    {
        printf("\n#%d - %s", i, *(lines + indx));
    }
}
