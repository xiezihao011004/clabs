#include <stdio.h>
#include <stdlib.h> //for atof()
#include <stdbool.h>
int month[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool isleap(int year) //判断是不是闰年
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int caculate(int year, int month0, int total) //计算这一年中到现在的天数
{
    total = 0;
    for (int i = 0; i < month0; i++)
    {
        if (isleap(year))
        {
            total += month[1][i];
        }
        else
        {
            total += month[0][i];
        }
    }
    return total;
}
int main(int argc, char *argv[])
{
    int i = 1, j = 0;
    int a[2];
    while (i < 3)
    {
        a[j] = atof(argv[i]);
        i++;
        j++;
    }
    int time1 = a[0], time2 = a[1];
    int year1, year2, month1, month2, day1, day2, difference = 0;
    if (time1 > time2) //保证time1小于time2
    {
        int temp;
        temp = time1;
        time1 = time2;
        time2 = temp;
    }
    year1 = time1 / 10000;
    year2 = time2 / 10000;
    month1 = time1 % 10000 / 100;
    month2 = time2 % 10000 / 100;
    day1 = time1 % 100;
    day2 = time2 % 100;
    printf("year1 is %d, month1 is %d, day1 is %d\n", year1, month1, day1);
    printf("year2 is %d, month2 is %d, day2 is %d\n", year2, month2, day2);
    if ((year2 - year1) == 1)
    {
        int total1 = caculate(year1, month1, total1);
        int total2 = caculate(year2, month2, total2);
        if (isleap(year1))
        {
            total1 = 366 - total1 + day1;
        }
        else
        {
            total1 = 365 - total1 + day1;
        }
        total2 += day2;
        printf("the number of days the difference is %d\n", total1 + total2 + difference + 1);
    }
    else if (year1 == year2)
    {
        int total1 = caculate(year1, month1, total1);
        int total2 = caculate(year2, month2, total2);
        printf("the number of days the difference is %d\n", total2 + day2 - (total1 + day1) + 1);
    }
    else
    {
        while (year1 < (year2 - 1))
        {
            if (isleap(year1))
            {
                difference += 366;
            }
            else
            {
                difference += 365;
            }
            year1++;
        }
        int total1 = caculate(year1, month1, total1);
        int total2 = caculate(year2, month2, total2);
        if (isleap(year1))
        {
            total1 = 366 - total1 + day1;
        }
        else
        {
            total1 = 365 - total1 + day1;
        }
        total2 += day2;
        printf("the number of days the difference is %d", total1 + total2 + difference + 1 +1);
    }
    return 0;
}
