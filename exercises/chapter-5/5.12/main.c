#include <stdio.h>
#include <stdlib.h>
#include "getline.h"
#include "entab.h"
#include "detab.h"
#include "tests-detab.h"
#include "tests-entab.h"

#define START_INDX 0
#define TAB_LENGTH 8

#define MAXLINE 1000

void parse_arguments(int argc, char* argv[], int*  starindx, int* tablength);

int main(int argc, char *argv[])
{
    run_entab_tests();
    run_detab_tests();

    char inputLine[MAXLINE * 2];
    char outputLine[MAXLINE];
    int length;

    int startindx = START_INDX;
    int tablength = TAB_LENGTH;
    parse_arguments(argc, argv, &startindx, &tablength);

    while((length = getLine(inputLine, MAXLINE)) > 0){
        detab(inputLine, outputLine, length, startindx, tablength);
        printf("\n%s\n", outputLine);
    }

    return 0;
}

void parse_arguments(int argc, char* argv[], int*  starindx, int* tablength)
{
    for(int i = 1; i < argc; i++)
    {
        char* arg = *(argv + i);

        if(*arg == '-')
            *starindx = atoi(++arg);
        else if (*arg == '+')
            *tablength = atoi(++arg);
        else
            printf("\n error: uknown param - '%s'", arg);
    }
}
