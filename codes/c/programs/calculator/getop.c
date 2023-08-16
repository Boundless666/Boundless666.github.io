/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-17 21:45:53
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-29 11:45:42
 * @FilePath: getop.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define isdigit(c) ((c)>='0' && (c)<='9')

int getop(char s[]){
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');   /* skip blanks and tabs*/
    s[1] = '\0';

    if(!isdigit(c) && c != '.' && c != '-')
        return c;    /* is not number */

    i = 0;
    if(c == '-'){
        s[i] = c;
        if(!isdigit(c = getch()))
            return c;
        else
            s[++i] = c; 
    }

    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
}