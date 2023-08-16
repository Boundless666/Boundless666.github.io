/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-13 19:07:12
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-14 21:51:21
 * @FilePath: ex_20.c
 */

#include <stdio.h>
#define TAB 8

int detab(int len);
// Write a program detab that replaces tabs in the input with the proper number of blanks to
// space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a
// symbolic parameter?
int main(){
    int c,count;
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == '\t'){
            detab(TAB - count);
            count = (count + (TAB - count) - 1) % TAB;
        }
        else
            printf("%c", c);
        count = (count + 1) % TAB;
    }
    
    
    return 0;
}

int detab(int len){
    printf("%c*%d",' ', len);
    return 0;
}