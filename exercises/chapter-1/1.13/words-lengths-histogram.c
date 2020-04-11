#include <stdio.h>

#define SIZE 10
#define IN 1
#define OUT 0

int main()
{
    int histogram[SIZE];
    for (int i = 0; i < SIZE; i++)
        histogram[i] = 0;

    int status = OUT;
    int counter = -1;
    int c;
    while ((c = getchar()) != EOF && counter < SIZE)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            status = OUT;
        }
        else if (status == OUT)
        {
            ++counter;
            ++histogram[counter];
            status = IN;
        }
        else if (status == IN)
        {
            ++histogram[counter];
        }
    }

    // print histogram - vertical orientation
    int max = 0;
    for (int i = 0; i <= counter; i++)
    {
        if(histogram[i] > max)
            max = histogram[i];
    }
    
    for (int i = max; i > 0; i--)
    {
        printf("\n");
        for (int j = 0; j <= counter; j++)
        {
            printf(" ");
            if(histogram[j] >= i)
                printf("||");
            else
                printf("  ");            
        }
    }

    // print histogram - horizontal orientation
    // for (int i = 0; i <= counter; i++)
    // {
    //     printf("\n length = %d\t", histogram[i]);
    //     for (int j = 0; j < histogram[i]; j++)
    //     {
    //         printf("=");
    //     }
    // }

    printf("\n");
}