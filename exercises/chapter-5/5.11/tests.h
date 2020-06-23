#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include <stdbool.h>

void run_test(char* testname, bool (*test)(void));

#endif // TESTS_H_INCLUDED
