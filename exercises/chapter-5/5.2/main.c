#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x = 10.0;
    printf("\n origin value = %f ", x);

    getfloat(&x);
    printf("value from console = %f", x);

    return 0;
}
