/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-23 22:02:46
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-30 22:20:29
 * @FilePath: main.c
 */
#include <stdio.h>
#include <math.h>
#include "calc.h"
#include "atof.h"

#define MAX 100

int main(){
    int type;
    double op2;
    char s[MAX];
    extern int bufp;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            double t = atof(s);
            printf("push %lf\n", t);
            push(atof(s));
            break;
        case '+':
            printf("extern buf:%d \n",bufp);
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            printf("subtract %f\n", op2);
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divizor\n");
            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                printf("execute module\n");
                // push(fmod(pop(), op2));
            else
                printf("error: division by zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '#':
            viewStack();
            break;
        default:
            break;
        }
    }
    
    
    return 0;
}