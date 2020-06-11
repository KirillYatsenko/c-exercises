#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#define MAX_SIZE 200

char* expand(const char s1[]);
bool sametype(char c1, char c2);

int main()
{
    printf("\n origin = %s \t expanded = %s", "A-Y", expand("A-Y"));
    printf("\n origin = %s \t expanded = %s", "K-Y", expand("K-Y"));
    printf("\n origin = %s \t expanded = %s", "B-G 1-9", expand("B-G 1-9"));
    printf("\n origin = %s \t expanded = %s", "a-z0-9", expand("a-z0-9"));
    printf("\n origin = %s \t expanded = %s", "-a-b", expand("-a-g"));
    printf("\n origin = %s \t expanded = %s", "a-k-", expand("a-k-"));

    return 0;
}

char* expand(const char s1[])
{
    char* s2 = (char*)malloc(MAX_SIZE);

    int i, j;
    for (i = 0, j = 0; s1[i] != '\0'; i++, j++)
    {
        if(s1[i + 1] == '-' && sametype(s1[i], s1[i+2]))
        {
            for(int k = s1[i]; k <= s1[i+2]; ++k, ++j)
                s2[j] = k;

            --j;
            i+=2;
        }
        else
        {
            s2[j] = s1[i];
        }
    }

    s2[j] = '\0';
    return s2;
}

bool sametype(char c1, char c2)
{
    if(c1 >= 'a' && c1 <= 'z')
        return c2 >= 'a' && c2 <= 'z';

    if(c1 >= 'A' && c1 <= 'Z')
        return c2 >= 'A' && c2 <= 'Z';

     if(c2 >= '0' && c2 <= '9')
        return c2 >= '0' && c2 <= '9';

    return false;
}
