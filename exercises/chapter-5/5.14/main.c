#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int (*ord)(int), char* (*consider_case)(char*), char* (*consider_symbols)(char *));
int numcmp(char *, char *);
int _getline(char line[], int maxLine);
int asc(int a);
int desc(int a);
char* ingore_case(char* a);
char* specific_symbols(char* a);
char* none(char* a);


main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int ignorecase = 0;
    int alphanumeric = 0;

    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if(strcmp(argv[i], "-r") == 0)
            reverse = 1;
        else if(strcmp(argv[i], "-f") == 0)
            ignorecase = 1;
        else if(strcmp(argv[i], "-d") == 0)
            alphanumeric = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void**) lineptr, 0, nlines-1,
              (int (*)(void*,void*))(numeric ? numcmp : strcmp), (int (*)(int))(reverse ? desc : asc), (char (*)(char))(ignorecase? ingore_case : none), (char (*)(char))(alphanumeric? specific_symbols : none) );

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

char* ingore_case(char* a)
{
    char *a_copy = malloc(strlen(a));
    strcpy(a_copy, a);

    for(int i = 0; *(a_copy + i); i++)
        *(a_copy + i) = tolower(*(a_copy + i));

    return a_copy;
}

char* none(char* a)
{
    return a;
}

char* specific_symbols(char* a)
{
    char *a_copy = malloc(strlen(a));
    strcpy(a_copy, a);

    int i, j;

    for(i = 0, j = 0; *(a_copy + i); i++)
        if(isalnum(*(a_copy + i) || *(a_copy + i) == ' '))
        {
            *(a_copy + j) = *(a_copy + i);
            j++;
        }

    *(a_copy + j) = '\0';
    return a_copy;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *), int (*ord)(int), char* (*consider_case)(char*), char* (*consider_symbols)(char *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
    {

        char* a = consider_case(consider_symbols(v[i]));
        char* b = consider_case(consider_symbols(v[left]));

        if ((*ord)((*comp)(a, b)))
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last-1, comp, ord, consider_case, consider_symbols);
    qsort(v, last+1, right, comp, ord, consider_case, consider_symbols);
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
