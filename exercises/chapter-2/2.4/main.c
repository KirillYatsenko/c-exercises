#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

char* squeeze(const char s1[], const char s2[]);

int main()
{
    char s1[] = "kirill";
    char s2[] = "kiri";
    char* squeezed = squeeze(s1, s2);

    printf("\ns1 = %s\ns2 = %s\nsqueezed = %s\n", s1, s2, squeezed);

    free(squeezed);

    return 0;
}

char* squeeze(const char s1[], const char s2[])
{
    char* result = (char*)malloc(strlen(s1));

    uint8_t i = 0;
    for(uint8_t j = 0; s1[i] != '\0'; ++j)
    {
        bool found = false;
        for(uint8_t z = 0; s2[z] != '\0'; ++z)
        {
            if(s2[z] == s1[j]){
                found = true;
                break;
            }
        }

        if(!found)
            result[i++] = s1[j];
    }

    result[i] = '\0';
    return result;
}
