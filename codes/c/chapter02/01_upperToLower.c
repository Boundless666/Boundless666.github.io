/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-20 11:41:07
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-20 11:46:18
 * @FilePath: 01_upperToLower.c
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

/* lower: Convert c to lower case; ASCLL only */
int lower(int c){
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}