/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-17 22:03:59
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-17 22:11:27
 * @FilePath: ex-10.c
 */
#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100
#define NUMBER 0

static double stack[MAXLEN];
static int p = 0;

double pop(void){
    if(p > 0)
        return stack[--p];
    else{
        printf("error: stack is empty.\n");
        return 0.0;
    }
}

void push(double n){
    if(p < MAXLEN)
        stack[p++] = n;
    else
        printf("error: stack is full.\n");
}

int main(int argc, char *argv[]){
    char *p;
    int i;
    double op2;
    printf("argc is %d\n\n", argc);
    for (i = 1; i < argc; i++)
    {
        p = argv[i];
        printf("argv[%d] = %s\n", i, argv[i]);
        while (*p && isdigit(*p))
            p++;
        printf("*p = %d, %c\n", *p, *p);
        switch (*p)
        {
            case '\0':
                push(atoi(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if( op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: %c is error character \n", *p);
                break;
        }
    }
    printf("final result is :%lf\n", pop());

    return 0;
}