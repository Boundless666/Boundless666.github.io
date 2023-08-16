/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-17 09:34:00
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-29 11:42:31
 * @FilePath: atof.c
 */
#include "atof.h"

#define isdigit(c) (c >= '0' && c <= '9')

double atof(const char s[]){
    double a = 0.0;
    int i, e;
    int c;
    i = e = 0;
    while((c=s[i++])!='\0' &&  isdigit(c))
        a = a*10.0 + (c - '0');
    if(c == '.'){
        while ((c=s[++i]) != '\0' && isdigit(c))
        {
            a = a*10.0 + (c - '0');
            e = e-1;
        }
    }
    while (e<0)
    {
        a *= 0.1;
        e += 1;
    }
    return a;
}