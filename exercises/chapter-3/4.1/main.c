#include <stdio.h>
#include <stdlib.h>

int strindex (char s[], char t[]);

int main()
{
    printf("\nindex = %d\n", strindex("found not this but this found", "found"));
    printf("\nindex = %d\n", strindex("not found", "a"));

    return 0;
}

int strindex (char s[], char t[])
{
    int i, j, k;
    int rightmost = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        if (k > 0 && t[k] == '\0')
            rightmost = i;
    }

    return rightmost;
}
