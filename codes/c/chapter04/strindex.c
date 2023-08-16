/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-08 21:29:43
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-11 22:16:17
 * @FilePath: strindex.c
 */
// #include "mystr.h"
#include <stdio.h>
#include <string.h>

/* strindex: return index of t in s, -1 if none.*/
int strindex(char s[], char t[]){
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = 0; t[j] != '\0' && t[j] == s[i+j]; j++);
        if(j != 0 && t[j] == '\0')
            return j;
    }
    return -1;
}

int strindex2(char s[], char t[]){
    int i, j;
    for (i = strlen(s); i >= 0 ; i--)
    {
        for(j = 0; s[i+j] == t[j] && t[j]; j++);
        if(!t[j])
            return i;
    }
    return -1;
}

int main(){
    int x=1;
    if(!'\0'){
        x = 2;
    }
    printf("%d\n",x);
    return 0;
}