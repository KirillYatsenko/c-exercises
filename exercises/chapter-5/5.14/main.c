#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int (*ord)(int));
int numcmp(char *, char *);
int _getline(char line[], int maxLine);
int asc(int a);
int desc(int a);


main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if(strcmp(argv[i], "-r") == 0)
            reverse = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void**) lineptr, 0, nlines-1,
              (int (*)(void*,void*))(numeric ? numcmp : strcmp), (int (*)(int))(reverse ? desc : asc));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

int desc(int a)
{
    return a > 0;
}

int asc(int a)
{
    return a < 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int (*ord)(int))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        //if ((*comp)(v[i], v[left]) > 0)
        if ((*ord)((*comp)(v[i], v[left])))
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1, comp, ord);
    qsort(v, last+1, right, comp, ord);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || ((p = malloc(len)) == NULL))
            return -1;
        else
        {
            strcpy(p, line);
            lineptr[nlines++] = p;
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

int _getline(char line[], int maxLine)
{
    int c, i;
    for(i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}
