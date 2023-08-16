/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-23 21:55:42
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-26 22:22:59
 * @FilePath: calc.h
 */
#define NUMBER '0'

/* gettop: get next character or numeric operand */
int getop(char s[]);

/* getch: return character from buffer*/
int getch(void);

/* ungetch: */
void ungetch(int c);

/* push: push f onto value stack */
void push(double f);

/* pop: pop and return top value from stack */
double pop();

void viewStack(void);