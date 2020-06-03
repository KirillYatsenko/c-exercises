#include <stdlib.h>
#include "tests-htol.h"
#include "htol.h"

typedef enum {false = 0, true = 1} bool;

void runSingleTest(char testName[], bool (*test)());
bool htol_passEmptyString_return0();
bool htol_passNullPointer_return0();
bool htol_incorrectPrefix_return0();
bool htol_passSmallHex_returnCorrectValue();
bool htol_passHex_returnCorrectValue();


void runTests()
{
    printf("\nRunning tests.... \n\n");

    runSingleTest("pass empty string", htol_passEmptyString_return0);
    runSingleTest("pass null pointer", htol_passNullPointer_return0);
    runSingleTest("incorrect prefix", htol_incorrectPrefix_return0);
    runSingleTest("small hex", htol_passSmallHex_returnCorrectValue);
    runSingleTest("hex", htol_passHex_returnCorrectValue);

    printf("\n\nRunning tests DONE!\n\n\n");
}

void runSingleTest(char testName[], bool (*test)())
{
    bool result = test();
    printf("\n %s - %s", testName, result ? "Passed" : "Failed");
}

bool htol_passEmptyString_return0()
{
    long result = htol("");
    return result == 0;
}

bool htol_passNullPointer_return0()
{
    long result = htol(NULL);
    return result == 0;
}

bool htol_incorrectPrefix_return0()
{
    long result = htol("xAAAA");
    return result == 0;
}

bool htol_passSmallHex_returnCorrectValue()
{
    long result = htol("0x1");
    return result == 1;
}

bool htol_passHex_returnCorrectValue()
{
    long result = htol("0x7DE");
    return result == 2014;
}


