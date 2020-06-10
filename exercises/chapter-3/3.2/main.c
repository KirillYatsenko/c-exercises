#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void escape(char from[], char to[]);
void unescape(char from[], char to[]);

int main()
{
    char from[100] = "hello \n  my dear \t friend";
    char to[100] = "";

    escape(from, to);
    printf("\nescaped = %s", to);

    unescape(to, from);
    printf("\nunescaped = %s", from);

    return 0;
}


void escape(char from[], char to[])
{

    int i = 0;
    int j = 0;

    for (;from[i] != '\0'; i++, j++)
    {
        switch (from[i])
        {
            case '\n':
                to[j++]= '\\';
                to[j] ='n';
                break;

            case '\t':
                to[j++] = '\\';
                to[j] = 't';
                break;

            default:
                to[j] = from[i];
                break;
        }
    }

    to[j] = from[i];
}

void unescape(char from[], char to[])
{
    int i = 0;
    int j = 0;

    for(; from[i] != '\0'; i++, j++)
    {
        if(from[i] == '\\')
        {
            switch (from[++i])
            {
                case 'n':
                    to[j] = '\n';
                    break;

                case 't':
                    to[j] = '\t';
                    break;

            }

        }
        else
        {
            to[j] = from[i];
        }
    }
}
