#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

typedef enum {false = 0, true = 1} bool;

long htol(const char hex[])
{
    if(hex == NULL)
        return 0;

    bool isSinged = hex[0] == '-';

    if(hex[isSinged] != '0' || !(hex[isSinged + 1] == 'x' || hex[isSinged + 1] == 'X'))
        return 0;

    long result = 0;
    uint8_t length = strlen(hex);
    uint8_t i;

    for(i = isSinged + 2; i < length; ++i)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
            result += (hex[i] - '0') * pow(16, length - 1 - i);
        else
            result += (hex[i] - 'A' + 10) * pow(16, length - 1 - i);
    }

    return isSinged? (-1) * result: result;
}
