#include <string.h>
#include <stdio.h>
#include "malloc.h"

int main()
{
    int size = 10;
    int *a = calloc(size, sizeof(int));
    a[4] = 5;

    for (int i = 0; i < size; i++)
        printf("\n#%d - %d", i + 1, a[i]);

    printf("\n");
    return 0;
}