/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-15 12:51:33
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-15 21:28:26
 * @FilePath: ex_21.c
 */

#include <stdio.h>
#define TAB 8
int entab();
// Write a program entab that replaces strings of blanks by the minimum number of tabs and
// blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
// would suffice to reach a tab stop, which should be given preference?
int main(){
    int c, count, restTabCount, blankCount;
    count = blankCount = 0;
    restTabCount = TAB;
    while ((c = getchar()) != EOF)
    {
        if(c == ' '){
            ++blankCount;
            if(blankCount == restTabCount){
                entab();
            }
        }else{
            if(blankCount != 0){
                printf(" *%d", blankCount);
                blankCount = 0;
            }             
            printf("%c", c);
        }
        restTabCount = (restTabCount - 1 + TAB) % TAB;
    }
    


    return 0;
}

int entab(){
    printf("\t");
    return 0;
}