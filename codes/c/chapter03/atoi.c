/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-29 14:23:53
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-29 14:34:13
 * @FilePath: atoi.c
 */
#include <stdio.h>
#include <ctype.h>

int main(){


    return 0;
}

/* atoi: convert s to integer*/
int atoi(char s[]){
    int i, n, sign;
    for(i = 0; isspace(s[i]); ++i);
    
    sign = s[i] == '-' ? -1 : 1;
    if(s[i] == '-' || s[i] == '+')
        ++i;
    
    for(n = 0; isdigit(s[i]); ++n)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}