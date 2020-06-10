#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned a = getbits(7,3,1);

    unsigned int rightPart = getbits(15, 3, 3);
    unsigned res = setbits(154, 4, 2, 3);
    printf("\n should = %d res = %d",158, res);

    res = setbits(15, 8, 4 , 15);
    printf("\n should = %d res = %d",255, res);

    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned rightPartX = getbits(x, p, p);
    unsigned prepareX = (~(~0 << (p - n))) & rightPartX;
    unsigned prepareY = y << (p - n);
    unsigned rightPartComplete = prepareX | prepareY;

    return (~0 << p & x) | rightPartComplete;
}
