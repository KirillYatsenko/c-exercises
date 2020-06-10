#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main()
{
    printf("\n number of bits in %d is %d", 3, bitcount(3));
    printf("\n number of bits in %d is %d", 4, bitcount(4));
    printf("\n number of bits in %d is %d", 255, bitcount(255));
    printf("\n number of bits in %d is %d", 256, bitcount(256));

    return 0;
}


int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1), ++b);

    return b;
}
