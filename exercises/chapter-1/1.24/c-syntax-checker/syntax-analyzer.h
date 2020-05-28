#ifndef SYNTAX-ANALYZER_INCLUDED
#define SYNTAX-ANALYZER_INCLUDED

#include <stdbool.h>
#include <inttypes.h>


#define MAXLINE 1000
#define MAXROWS 500

typedef enum
{
    Success,
    ErrorOpenedDoubleQuotes,
    ErrorUnterminatedComment,
    ErrorUnclosedBrackets,
    ErrorInconsistentBracket
} Status;

typedef struct
{
    Status status;
    uint32_t errorRow;
    uint32_t errorColumn;
} ProcessResult;

ProcessResult processText(char text[][MAXLINE], uint32_t rowsCount);

#endif // SYNTAX-ANALYZER_INCLUDED
