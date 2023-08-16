/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-01 21:58:43
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-01 22:06:43
 * @FilePath: ex-12.c
 */
#include <stdio.h>

void itoa(int n);
// write a recursive version of itoa.
int main(){
    itoa(123);
    printf("\n");
    return 0;
}

/* itoa: convert an integer into a string*/
void itoa(int n){
    if(n < 0){
        printf("-");
        n = -n;
    }
    if(n / 10)
        itoa(n / 10);
    printf("%d",n % 10);
}