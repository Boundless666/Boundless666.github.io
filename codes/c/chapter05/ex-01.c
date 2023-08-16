/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-07 21:51:18
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-07 22:26:21
 * @FilePath: ex-01.c
 */
#include <ctype.h>
#include <stdio.h>

#define BUFLEN 100
int buf[BUFLEN];
int p = 0;

void viewbuffer(void){
    int i;
    printf("buffer: \n");
    for(i = 0; i < p; i++)
        printf("%d\t", buf[i]);
    printf("\n");
}

int getch(void){
    return p > 0 ? buf[--p] : getchar();
}

void ungetch(int r){
    if(p < BUFLEN)
        buf[p++] = r;
    else
        printf("error: out bound of buffer array.");
}

int getint(int *pn){
    int c, sign;
    while(isspace(c = getch()));
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
        ungetch(c);
        return 0;
    }
    sign = c == '-' ? -1:1;
    if(c=='+' || c=='-'){
        c = getch();
        if(!isdigit(c)){
            ungetch(sign == 1 ? '+':'-');
            return 0;
        }
    }

    for(*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}

int main(){
    int x, retval;
    int* px;

    x = 0;
    px = &x;
    retval = getint(px);
    printf("retval = %d , x = %d\n", retval, x);
    viewbuffer();
    return 0;
}