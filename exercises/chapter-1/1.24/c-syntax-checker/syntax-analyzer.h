#ifndef SYNTAX-ANALYZER_INCLUDED
#define SYNTAX-ANALYZER_INCLUDED

#include <inttypes.h>

#define MAXLINE 1000
#define MAXROWS 500

void processText(char text[][MAXLINE], uint32_t rowsCount);

#endif // SYNTAX-ANALYZER_INCLUDED
