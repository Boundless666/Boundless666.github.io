/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-02 13:59:50
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-02 14:19:10
 * @FilePath: itoa.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(){
    char s[20];
    printf("%d \n", INT_MIN);
    itoa(INT_MIN, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert number n to string s*/
void itoa(int n, char s[]){
    int i, sign;
    i = 0;
    sign = n;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if(sign < 0)
        s[i++] = '-';
    reverse(s);
}

void reverse(char s[]){
    int i, j, temp;

    for(i = 0, j = strlen(s) - 1; i < j; ++i,--j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
