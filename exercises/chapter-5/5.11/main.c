#include <stdio.h>
#include <stdlib.h>
#include "getline.h"
#include "entab.h"
#include "detab.h"
#include "tests-detab.h"
#include "tests-entab.h"

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    run_entab_tests();
    run_detab_tests();

    char inputLine[MAXLINE * 2];
    char outputLine[MAXLINE];
    int length;

    --argc;
    ++argv;

    while((length = getLine(inputLine, MAXLINE)) > 0){
        detab(inputLine, outputLine, length, argc, argv);
        printf("\n%s\n", outputLine);
    }

    return 0;
}

