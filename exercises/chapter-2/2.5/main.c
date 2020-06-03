#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

long any(const char s1[], const char s2[]);

int main()
{
    char s1[] = "kirilla";
    char s2[] = "a";
    long position = any(s1, s2);

    printf("\ns1=%s\ns2=%s\nposition=%d", s1, s2, position);

    return 0;
}

long any(const char s1[], const char s2[])
{
    for(uint32_t i = 0; s1[i] != '\0'; ++i)
    {
        for(uint32_t z = 0; s2[z] != '\0'; ++z)
            if(s1[i] == s2[z])
                return i;
    }

    return -1;
}
