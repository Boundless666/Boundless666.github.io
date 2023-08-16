/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-12 18:14:08
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-12 18:33:13
 * @FilePath: ex-04.c
 */
#include <stdio.h>

/* strend: return 1 if string t occurs at the end of string s, and 0 otherwise */
int strend(char *s, char *t);

int main(){
    char s[] = "Daiki", t1[] = "iki", t2[] = "Midorima";
	printf("strend(%s, %s) = %d\n", s, t1, strend(s, t1));
	printf("strend(%s, %s) = %d\n", s, t2, strend(s, t2));
    return 0;
}

int strcmp(char *s, char *t){
    for (; *s == *t; s++,t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

int strlen(char *s){
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}

int strend(char *s, char *t){
    int slen = strlen(s), tlen = strlen(t);
    if(slen < tlen)
        return 0;
    s = s + slen - tlen;
    return strcmp(s, t) ? 0:1;
}