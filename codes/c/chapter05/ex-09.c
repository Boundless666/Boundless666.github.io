/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-15 21:45:21
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-15 22:13:26
 * @FilePath: ex-09.c
 */
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

// static int daytab[2][12] = {
//     {31,28,31,30,31,30,31,31,30,31,30,31},
//     {31,29,31,30,31,30,31,31,30,31,30,31}
// };
int Jan[] = {31};
int Feb[] = {28, 29};
int Mar[] = {31};
int Apr[] = {30};
int May[] = {31};
int Jun[] = {30};
int Jul[] = {31};
int Aug[] = {31};
int Sep[] = {30};
int Oct[] = {31};
int Nov[] = {30};
int Dec[] = {31};

int *daytab[] = { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

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

    if(month < 1 || month > 12 || day > *(*(daytab + month - 1) + ((leap && month == 2) ? 1 : 0))){
        printf("month %d or day %d is incorrect", month, day);
        return -1;
    }
    month--;
    for (i = 0; i < month; i++)
        day += *( *(daytab + i ) + ((leap && i == 1) ? 1 : 0));
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

    for(i = 0; yearday > *(*(daytab + i) + ((leap && i == 1) ? 1 : 0)); i++)
        yearday -= *(*(daytab + i) + ((leap && i == 1) ? 1 : 0));
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