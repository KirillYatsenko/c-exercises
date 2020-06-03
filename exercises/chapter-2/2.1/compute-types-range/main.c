#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <inttypes.h>

int main()
{
    long x = 0;

    uint8_t byteCount = 0;
    unsigned long maxRange = 0, minRange = 0;

    if((x = x - 1) < 0)
    {
        for(x = 0, byteCount = 1; (x = pow(2, 8 * byteCount - 1) - 1) == (pow(2, 8 * byteCount - 1) - 1); ++byteCount);
        maxRange = pow(2, 8 * (byteCount - 1) - 1) - 1;
        minRange = maxRange + 1;

        if(byteCount > 4)
            printf("\nrange from -%u to %u", minRange, maxRange);
        else
            printf("\nrange from -%u to %u", minRange, maxRange);
    }
    else
    {
        for(x = 0, byteCount = 1; x != x + pow(2, 8 * byteCount) - 1; ++byteCount);

        maxRange = pow(2, 8 * byteCount) - 1;

        printf("\nrange from %d to %d", 0, maxRange);
    }

    return 0;
}

