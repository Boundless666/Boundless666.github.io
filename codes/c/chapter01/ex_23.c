/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-15 21:43:47
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-15 22:00:57
 * @FilePath: ex_23.c
 */

#include <stdio.h>

// Assume implement a Link Stack Structure named Stack.

// Write a program to remove all comments from a C program. Don't forget to handle quoted
// strings and character constants properly. C comments don't nest.
int main(){
    int c, first, second;
    while ((c = getchar()) != EOF)
    {
        if(c == '/')
            first = c;
        if(first = '/' && (c == '*' || c == '/')){
            // Stack.Push(first);
            // Stack.Push(c);
        }
        
    }

    return 0;
}

