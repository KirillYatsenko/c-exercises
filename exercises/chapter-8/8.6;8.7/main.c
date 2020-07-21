#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "malloc.h"

int main()
{
    int *x = (int*)_calloc(UINT_MAX/sizeof(4), sizeof(int));
    x[3] = 4;
    printf("%d", x[3]);

    // int size = 10;
    // int *a = (int*)_calloc(size, sizeof(int));
    // a[5] = 6;

    // for (int i = 0; i < size; i++)
    //     printf("\n#%d - %d", i + 1, a[i]);

    // _free(a);

    printf("\n");
    return 0;
}