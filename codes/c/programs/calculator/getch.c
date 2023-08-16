/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-23 21:58:42
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-30 22:21:12
 * @FilePath: getch.c
 */
#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;   /* test */

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        return;
    else
        buf[bufp++] = c;
}
