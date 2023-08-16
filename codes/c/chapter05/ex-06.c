/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-13 10:16:29
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-13 11:38:53
 * @FilePath: ex-06.c
 */
#include <stdio.h>

#define ISEMPTY(c) ((c)==' ' || (c)=='\t')
#define ISDIGIT(c) ((c)>='0' && (c)<='9')

/* get line to s. return length */
int getnline(const char *s);

/* convert s to integer. return integer*/
int atoi(const char *s);

/* convert number n to string s.*/
void itoa(int n, char *s);

/* revert string s.*/
void reverse(char *s);

/* return position or index in string s where the string t begins, or -1 if string s not contains t*/
int strindex(char *s, char *t);

int main(){
    char *s = " hello world!\n this is test\n haha.";
    int res = getnline(s);
    printf("%s line number is:%d\n\n", s, res);

    s = " 300a";
    res = atoi(s);
    printf("%s atoi is:%d\n\n", s, res);

    char x[100];
    itoa(res, x);
    printf("%d itoa is:%s\n\n", res, x);

    return 0;
}

/* get line to s. return length */
int getnline(const char *s){
    int len;
    if(*s == '\0')
        return 0;
    for(len = 1; *s != '\0'; s++)
        if(*s == '\n')
            len++;
    return len;
}

/* convert s to integer. return integer */
int atoi(const char *s){
    int res;
    for(;ISEMPTY(*s);s++);
    for(res = 0; ISDIGIT(*s); s++)
        res = res * 10 + (*s - '0');
    
    return res;
}

/* convert number n to string s.*/
void itoa(int n, char *s){
    char *p = s;
    for(; n>0; n /= 10)
        *p++ = n % 10 + '0';
    p = '\0';
    reverse(s);
}

int strlen(const char *s){
    int len;
    for(len = 0; *s != '\0'; s++,len++);
    return len;
}

/* revert string s.*/
void reverse(char *s){
    int len = strlen(s);
    int i;
    char tmp;
    for(i = len/2; i<len; i++){
        tmp = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = tmp;
    }
}

/* return position or index in string s where the string t begins, or -1 if string s not contains t*/
int strindex(char *s, char *t){
    return 0;
}


