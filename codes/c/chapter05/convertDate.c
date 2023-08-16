/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-14 22:08:49
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-15 21:29:55
 * @FilePath: convertDate.c
 */
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

static int daytab[2][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

int main(){
    int year, month, mday, yday;
    year = 2023;
    month = 8;
    mday = 14;
    yday = day_of_year(year, month, mday);
    printf("%d-%d-%d is current year %d-th day.\n", year, month, mday, yday);
    
    month_day(year, yday, &month, &mday);
    printf("%d-th day is %d-%d-%d\n", yday, year, month, mday);

    printf("It's %s\n", month_name(month));
    return 0;
}

/* set day of year from month day. */
int day_of_year(int year, int month, int day){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if(month < 1 || month > 12 || day > daytab[leap][--month]){
        printf("month %d or day %d is incorrect", month, day);
        return -1;
    }

    for (i = 0; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* set month, day from day of year. */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(yearday < 1 || yearday > (leap ? 364: 365)){
        printf("%d exceed current year %d scope.\n", yearday, year);
        return;
    }

    for(i = 0; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i+1;
    *pday = yearday;
}

char *month_name(int n){
    /* static char* name[] */
    static char *name[] ={
        "Illegal month",
        "January","February","March",
        "April","March","June",
        "July","August","September",
        "October","November","December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}