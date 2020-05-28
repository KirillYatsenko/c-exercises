#include "test-syntax-analyzer.h"
#include "syntax-analyzer.h"


void runSingleTest(char testName[], bool (*test)());

bool processText_PassCorrectText_ShouldReturnSuccessResult();
bool processText_PassUnclosedBrackets_ShouldReturnErrorUnclosedBracketsStatus();
bool processText_PassUnclosedBrackets2_ShouldReturnErrorUnclosedBracketsStatus();
bool processText_PassUnclosedDoubleQuotes_ErrorOpenedDoubleQuotes();
bool processText_PassUnclosedDoubleQuotes2_ErrorOpenedDoubleQuotes();
bool processText_PassUnterminatedMultilineComment_ErrorUnterminatedComment();
bool processText_PassInconsistentBrackets_ErrorInconsistentBrackets();
bool processText_PassInconsistentBrackets2_ErrorInconsistentBrackets();

void testsRun()
{
    runSingleTest("#1 Happy Path", processText_PassCorrectText_ShouldReturnSuccessResult);
    runSingleTest("#2 Error Unclosed Brackets", processText_PassUnclosedBrackets_ShouldReturnErrorUnclosedBracketsStatus);
    runSingleTest("#3 Error Unclosed Brackets #2", processText_PassUnclosedBrackets2_ShouldReturnErrorUnclosedBracketsStatus);
    runSingleTest("#4 Error Oppened Double Quotes", processText_PassUnclosedDoubleQuotes_ErrorOpenedDoubleQuotes);
    runSingleTest("#5 Error Oppened Double Quotes #2", processText_PassUnclosedDoubleQuotes2_ErrorOpenedDoubleQuotes);
    runSingleTest("#6 Error Unterminated Multiline Comment", processText_PassUnterminatedMultilineComment_ErrorUnterminatedComment);
    runSingleTest("#7 Error Inconsistent Brackets", processText_PassInconsistentBrackets_ErrorInconsistentBrackets);
    runSingleTest("#8 Error Inconsistent Brackets #2", processText_PassInconsistentBrackets_ErrorInconsistentBrackets);
}

void runSingleTest(char testName[], bool (*test)())
{
    bool result = test();
    printf("\n %s - %s", testName, result ? "Passed" : "Failed");
}


bool processText_PassCorrectText_ShouldReturnSuccessResult()
{
    char text[MAXROWS][MAXLINE] =
    {
      "/* comment here */",
      "// another comment",
      "printf(\"text\")",
      "if (true)"
      "{ printf(\"it's true\"); }"
    };

    ProcessResult processResult =  processText(text, 5);

    return processResult.status == Success;
}

bool processText_PassUnclosedBrackets_ShouldReturnErrorUnclosedBracketsStatus()
{
    char text[MAXROWS][MAXLINE] =
    {
      "({",
    };

    ProcessResult processResult = processText(text, 1);

    return processResult.status == ErrorUnclosedBrackets;
}

bool processText_PassUnclosedBrackets2_ShouldReturnErrorUnclosedBracketsStatus()
{
    char text[MAXROWS][MAXLINE] =
    {
      "/* comment here */",
      "// another comment",
      "printf(\"text\")",
      "if (true)"
      "{ printf(\"it's true\"); "
    };

    ProcessResult processResult =  processText(text, 5);

    return processResult.status == ErrorUnclosedBrackets;
}

bool processText_PassUnclosedDoubleQuotes_ErrorOpenedDoubleQuotes()
{
    char text[MAXROWS][MAXLINE] =
    {
      "\"",
    };

    ProcessResult processResult = processText(text, 1);

    return processResult.status == ErrorOpenedDoubleQuotes;
}


bool processText_PassUnclosedDoubleQuotes2_ErrorOpenedDoubleQuotes()
{
    char text[MAXROWS][MAXLINE] =
    {
      "/* comment here */",
      "// another comment",
      "printf(\"text\")",
      "if (true)"
      "{ printf(\"it's true); "
    };

    ProcessResult processResult =  processText(text, 5);

    return processResult.status == ErrorOpenedDoubleQuotes;
}

bool processText_PassUnterminatedMultilineComment_ErrorUnterminatedComment()
{
    char text[MAXROWS][MAXLINE] =
    {
      "/* comment here comment here",
      "multi lines comment contiues",
    };

    ProcessResult processResult = processText(text, 2);

    return processResult.status == ErrorUnterminatedComment;
}

bool processText_PassInconsistentBrackets_ErrorInconsistentBrackets()
{
    char text[MAXROWS][MAXLINE] =
    {
      "([})"
    };

    ProcessResult processResult = processText(text, 1);

    return processResult.status == ErrorInconsistentBracket;
}

bool processText_PassInconsistentBrackets2_ErrorInconsistentBrackets()
{
    char text[MAXROWS][MAXLINE] =
    {
      "/* comment here */",
      "// another comment",
      "printf(\"text\")",
      "if (true)"
      "{ printf(\"it's true\"]}; "
    };

    ProcessResult processResult =  processText(text, 5);

    return processResult.status == ErrorInconsistentBracket;
}
