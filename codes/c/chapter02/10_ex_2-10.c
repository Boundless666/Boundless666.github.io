/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-26 07:21:17
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-26 07:24:04
 * @FilePath: 10_ex_2-10.c
 */
#include <stdio.h>
int lower(int c);

int main(){
    int c;
    while ((c = getchar()) != EOF )
    {
        printf("%c", lower(c));
    }
    return 0;
}

/* lower: Convert c to lower. Ascll only*/
int lower(int c){
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}