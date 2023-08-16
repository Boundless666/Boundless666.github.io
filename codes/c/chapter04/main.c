/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-08 21:30:13
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-10 21:25:09
 * @FilePath: main.c
 */

#include "mystr.h"

/* find all lines matching pattern*/
int main(){
    char s[] = "hello, this is test";
    char t[] = "th";
    printf("value = %d",strindex(s, t));

    return 0;
}