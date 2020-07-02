#include <stdio.h>
#include <string.h>
#include "tests-dcl.h"
#include "dcl.h"

void _run(char *name, int (*test)(void));
int test_1_frombook();
int test_2_frombook();
int test_3_frombook();
int test_4_frombook();
int test_5_frombook();
int test_6_frombook();
int test_7_frombook();
int dcl_pass_function_arguments_types_1();
int dcl_pass_function_arguments_types_2();
int dcl_pass_function_arguments_types_static();
int dcl_pass_function_arguments_types_const();
int dcl_pass_function_arguments_types_const_and_returing_static_char();

void runtests(void)
{
    _run("From book test #1", test_1_frombook);
    _run("From book test #2", test_2_frombook);
    _run("From book test #3", test_3_frombook);
    _run("From book test #4", test_4_frombook);
    _run("From book test #5", test_5_frombook);
    _run("From book test #6", test_6_frombook);
    _run("From book test #7", test_7_frombook);
    _run("Pass arguments types to function #1", dcl_pass_function_arguments_types_1);
    _run("Pass arguments types to function #2", dcl_pass_function_arguments_types_2);
    _run("Pass arguments types with static to function", dcl_pass_function_arguments_types_static);
    _run("Pass arguments types with const to function", dcl_pass_function_arguments_types_const);
    _run("Pass arguments types with const to function and return static char", dcl_pass_function_arguments_types_const_and_returing_static_char);

    printf("\n");
}

void _run(char *name, int (*test)(void))
{
    int res = test();
    printf("\n%s - %s", name, res ? "Passed" : "Failed");
}

int test_1_frombook()
{
    char res[1000];
    dcl("char **argv", res);

    return strcmp(res, "argv:  pointer to pointer to char\n") == 0;
}

int test_2_frombook()
{
    char res[1000];
    dcl("int (*daytab)[13]", res);

    return strcmp(res, "daytab:  pointer to array[13] of int\n") == 0;
}

int test_3_frombook()
{
    char res[1000];
    dcl("int *daytab[13]", res);

    return strcmp(res, "daytab:  array[13] of pointer to int\n") == 0;
}

int test_4_frombook()
{
    char res[1000];
    dcl("void *comp()", res);

    return strcmp(res, "comp:  function returning pointer to void\n") == 0;
}

int test_5_frombook()
{
    char res[1000];
    dcl("void (*comp)()", res);

    return strcmp(res, "comp:  pointer to function returning void\n") == 0;
}

int test_6_frombook()
{
    char res[1000];
    dcl("char (*(*comp())[])()", res);

    return strcmp(res, "comp:  function returning pointer to array[] of pointer to function returning char\n") == 0;
}

int test_7_frombook()
{
    char res[1000];
    dcl("char (*(*x[3])())[5]", res);

    return strcmp(res, "x:  array[3] of pointer to function returning pointer to array[5] of char\n") == 0;
}

int dcl_pass_function_arguments_types_1()
{
    char res[1000];
    dcl("char (*detab)(int)", res);

    return strcmp(res, "detab:  pointer to function accepting int and returning char\n") == 0;
}

int dcl_pass_function_arguments_types_2()
{
    char res[1000];
    dcl("char (*detab)(int, char)", res);

    return strcmp(res, "detab:  pointer to function accepting int, char and returning char\n") == 0;
}

int dcl_pass_function_arguments_types_static()
{
    char res[1000];
    dcl("char (*detab)(static int, char)", res);

    return strcmp(res, "detab:  pointer to function accepting static int, char and returning char\n") == 0;
}

int dcl_pass_function_arguments_types_const()
{
    char res[1000];
    dcl("char (*detab)(const int, char)", res);

    return strcmp(res, "detab:  pointer to function accepting const int, char and returning char\n") == 0;
}

int dcl_pass_function_arguments_types_const_and_returing_static_char()
{
    char res[1000];
    dcl("static char (*detab)(const int, char)", res);

    return strcmp(res, "detab:  pointer to function accepting const int, char and returning static char\n") == 0;
}