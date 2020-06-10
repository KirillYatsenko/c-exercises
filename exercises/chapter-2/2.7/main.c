#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned res = invert(15, 8, 4);
    printf("\n should = %d res = %d",255, res);

    res = invert(243, 4, 1);
    printf("\n should = %d res = %d",251, res);

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned a = ~(~0 << p);
    unsigned prepareXOR = (~(~0 << p)) & (~0 << (p - n));

    return prepareXOR ^ x;
}

