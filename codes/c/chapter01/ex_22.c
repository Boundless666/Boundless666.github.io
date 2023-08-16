/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-15 21:39:09
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-15 21:42:46
 * @FilePath: ex_22.c
 */

#include <stdio.h>

// Write a program to ``fold'' long input lines into two or more shorter lines after the last
// non−blank character that occurs before the n−th column of input. Make sure your program does something
// intelligent with very long lines, and if there are no blanks or tabs before the specified column.
int main(){
    int c;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
            printf("\n");
        else
            printf("%c",c);
    }
    

    return 0;
}