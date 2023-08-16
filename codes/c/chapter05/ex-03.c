/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-12 18:05:44
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-12 18:36:35
 * @FilePath: ex-03.c
 */
#include <stdio.h>

/* strcat: concate string s and t. pointer version. */
void strcat(char *s, char *t);

int main(){
    char s[100] = "hello,";
    char t[100] = " world!";

    strcat(s, t);

    printf("%s\n", s);
    return 0;
}


void strcat(char *s, char *t){
    while (*s++ != '\0');
    s--;
    while (*s++ = *t++);
}