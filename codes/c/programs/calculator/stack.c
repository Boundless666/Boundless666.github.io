/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-23 22:00:20
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-29 11:43:45
 * @FilePath: stack.c
 */
#include <stdio.h>
#include "calc.h"

#define MAX 100     /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAX];    /* value stack */

/* push: push f onto value stack */
void push(double f){
    if(sp < MAX)
        val[sp++] = f;
    else
        printf("error: stack full, can't push \n");
}

/* pop: pop and return top value from stack */
double pop(){
    if(sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

void viewStack(void){
    int i = sp;
    while (i>0)
    {
        printf("%lf\n",val[--i]);
    }
    printf("\n");
}