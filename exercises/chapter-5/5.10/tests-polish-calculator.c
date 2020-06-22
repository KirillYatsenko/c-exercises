#include "polish-calculator.h"

void run(char* testname, int (*test)());
int evaluate_complexexpression_returncorrect(void);

void check(void)
{
    run("evaluate_complexexpression_returncorrect", evaluate_complexexpression_returncorrect);
}

void run(char* testname, int (*test)())
{
    char* res = test() ? "passed" : "failed";
    printf("%s - %s", testname, res);
}

int evaluate_complexexpression_returncorrect(void)
{
    int n = 7;
    char *expression[] = {
        "10", "3", "+",
        "3", "4", "*",
        "-"
    };

    return evaluate(n, expression) == 1;
}
