/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-12 22:39:26
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-13 10:51:52
 * @FilePath: ex-05.c
 */
#include <stdio.h>

#define MAXLEN 100

char *strncpy(char *s,const char *t, unsigned int n);
char *strncat(char *s,const char *t, unsigned int n);
int strncmp(const char *s, const char *t, unsigned int n);

int main(){
    char s[MAXLEN];
    char t[MAXLEN] = "abcdefgh";
    strncpy(s, t, 5);
    printf("current s is:%s\ncurrent t is:%s\n\n", s, t);

    strncat(s,t, 4);
    printf("current s is:%s\ncurrent t is:%s\n\n", s,t);

    int res = strncmp(s,t, 4);
    printf("current s is:%s\ncurrent t is:%s\n", s, t);
    printf("current res is:%d\n\n", res);

    res = strncmp(s,t, 6);
    printf("current s is:%s\ncurrent t is:%s\n", s, t);
    printf("current res is:%d\n\n", res);
    return 0;
}

/* strncpy: copy at most n characters of t to s. return s*/
char* strncpy(char *s,const char *t, unsigned int n){
    int i;
    for (i = 0; i < n; i++)
        *(s + i) = *(t + i) ? *(t + i) : '\0';
    
    return s;
}

/* concatenate string t to end of string s. return s*/
char *strncat(char *s,const char *t, unsigned int n){
    while(*s++);
    s--;
    while(n-- > 0 && (*s++ = *t++));
    return s;
}

/* compare string s to string t. return <0 if s<t, 0 if s=t, or >0 if s>t*/
int strncmp(const char *s, const char *t, unsigned int n){
    for(; n > 0 && *s == *t; s++,t++,n--)
        if(*s == '\0')
            return 0;
    return *s - *t;
}