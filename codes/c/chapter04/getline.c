/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-08 21:29:28
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-10 21:21:41
 * @FilePath: getline.c
 */
#include <stdio.h>
#include "mystr.h"

/* getline: get line to s, return length */
int getline(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if(c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}