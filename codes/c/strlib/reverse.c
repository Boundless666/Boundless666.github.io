/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-30 21:37:30
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-30 21:42:40
 * @FilePath: reverse.c
 */
#include <string.h>

/* reverse: reverse string s in place*/
void reverse(char s[]){
    int i, j, temp;

    for(i = 0, j = strlen(s) - 1; i < j; ++i,--j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}