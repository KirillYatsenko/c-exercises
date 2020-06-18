#include <stdio.h>
#include <string.h>
#include "getline.h"
#include "alloc.h"
#include "strcpy.h"


#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char lines[MAXLINES][MAXLEN]);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

main()
{
    char lines[MAXLINES][MAXLEN];

    int nlines;
    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, lines)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char lines[MAXLINES][MAXLEN])
{
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
    {
         if ((nlines >= maxlines))
            return -1;
        else
        {
            line[len-1] = '\0'; /* delete newline */
            _strcpy(line, lines[nlines]);
            lineptr[nlines++] = lines[nlines];
        }
    }

    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;
    /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
