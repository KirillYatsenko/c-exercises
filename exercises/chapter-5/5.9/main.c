#include <stdio.h>
#include <stdlib.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int day = day_of_year(1997, 05, 31);
    printf("day = %d\n", day);

    int month;
    month_day(1997, 151, &month, &day);
    printf("month = %d, day = %d", month, day);

    return 0;
}

static char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 0)
    {
        printf("\n ERROR: 'year' param is not correct");
        return -1;
    }

    if (month <= 0 || month > 12)
    {
        printf("\n ERROR: 'month' param is not correct");
        return -1;
    }

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(day <= 1 || day > *(*(daytab + leap) + month))
    {
        printf("\n ERROR: 'day' param is not correct");
        return -1;
    }

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0 || year > 2020)
    {
        printf("\n ERROR: 'year' param is not correct");
        return;
    }

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (yearday <= 0 || yearday >= 365 + leap)
    {
        printf("\n ERROR: 'day' param is not correct");
        return;
    }

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);

    *pmonth = i;
    *pday = yearday;
}
