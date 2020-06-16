#include <stdio.h>
#include <stdlib.h>

#define swap(t, x, y) \
{                     \
  t buff = x;         \
  x = y;              \
  y = buff;           \
}                     \

int main()
{
    int a = 3;
    int b = 4;
    swap(int, a, b);

    printf("\n a = %d, b = %d", a, b);

    return 0;
}
