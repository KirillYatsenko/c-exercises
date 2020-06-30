#include <stdio.h>
#include <string.h>
#include "tests-dcl.h"
#include "dcl.h"

void _run(char *name, int (*test)(void));
int test_1();
int test_2();
int test_3();
int test_4();
int test_5();
int test_6();
int test_7();

void runtests(void)
{
    _run("test #1", test_1);
    _run("test #2", test_2);
    _run("test #3", test_3);
    _run("test #4", test_4);
    _run("test #5", test_5);
    _run("test #6", test_6);
    _run("test #7", test_7);

    printf("\n");
}

void _run(char *name, int (*test)(void))
{
    int res = test();
    printf("\n%s - %s", name, res ? "Passed" : "Failed");
}

int test_1()
{
    char res[1000];
    dcl("char **argv", res);

    return strcmp(res, "argv:  pointer to pointer to char\n") == 0;
}

int test_2()
{
    char res[1000];
    dcl("int (*daytab)[13]", res);

    return strcmp(res, "daytab:  pointer to array[13] of int\n") == 0;
}

int test_3()
{
    char res[1000];
    dcl("int *daytab[13]", res);

    return strcmp(res, "daytab:  array[13] of pointer to int\n") == 0;
}

int test_4()
{
    char res[1000];
    dcl("void *comp()", res);

    return strcmp(res, "comp:  function returning pointer to void\n") == 0;
}

int test_5()
{
    char res[1000];
    dcl("void (*comp)()", res);

    return strcmp(res, "comp:  pointer to function returning void\n") == 0;
}

int test_6()
{
    char res[1000];
    dcl("char (*(*x())[])()", res);

    return strcmp(res, "x:  function returning pointer to array[] of pointer to function returning char\n") == 0;
}

int test_7()
{
    char res[1000];
    dcl("char (*(*x[3])())[5]", res);

    return strcmp(res, "x:  array[3] of pointer to function returning pointer to array[5] of char\n") == 0;
}