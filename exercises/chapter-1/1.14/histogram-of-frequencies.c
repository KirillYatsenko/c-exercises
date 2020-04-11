#include <stdio.h>

#define SIZE 94

int main() {
    int frequencies[SIZE];
    for (int i = 0; i < SIZE; i++)
        frequencies[i] = 0;

    int c;
    while ((c = getchar()) != EOF)
        if(c >= 32)
            ++frequencies[c - 32];

    for (int i = 0; i < SIZE; i++)
    {
        if(frequencies[i] == 0)
            continue;

        if(i == 0)
            printf("\nSP ");
        else
            printf("\n%2c ", i + 32);

        for (int j = 0; j < frequencies[i]; j++)
        {
            printf("=");
        }
    }

    printf("\n");
}