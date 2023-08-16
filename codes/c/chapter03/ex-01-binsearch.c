/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-27 22:05:09
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-30 21:21:04
 * @FilePath: ex-01-binsearch.c
 */
/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-27 22:05:09
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-28 11:54:00
 * @FilePath: ex-01.c
 */
#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearch3(int x, int v[], int n);

#define MAX_ELEMENT 20000

int main(){
    int i, test_data[MAX_ELEMENT], index;
    clock_t time_taken;
    for(i=0; i< MAX_ELEMENT; ++i)
        test_data[i] = i;

    for(i = 0, time_taken = clock(); i < 100000; ++i)
        index = binsearch(i, test_data, MAX_ELEMENT);
    time_taken = clock() - time_taken;
    
    printf("binsearch =%lu \n", (long)time_taken);


    for(i = 0, time_taken = clock(); i < 100000; ++i)
        index = binsearch2(i, test_data, MAX_ELEMENT);
    time_taken = clock() - time_taken;
    
    printf("binsearch2=%lu \n", (long)time_taken);

    for(i = 0, time_taken = clock(); i < 100000; ++i)
        index = binsearch3(i, test_data, MAX_ELEMENT);
    time_taken = clock() - time_taken;
    
    printf("binsearch3=%lu \n", (long)time_taken);


    index = binsearch3(7, test_data, MAX_ELEMENT);
    printf("%d\n", index);

    return 0;
}

/* binsearch: Performs a binary search for x in array v, which has n elements of arranged from small to large.*/
int binsearch(int x, int v[], int n){
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n){
    int low, mid, high;
    
    low = -1;
    high = n;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        if (v[mid] < x)
        low = mid;
        else
        high = mid;
    }
    if (high == n || v[high] != x)
        return -1;
    else
        return high;
}

int binsearch3(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while ( low <= high && x != v[mid] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if ( x == v[mid] )
        return mid;
    else
        return -1;
}