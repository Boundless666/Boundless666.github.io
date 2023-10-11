/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-15 20:51:33
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-20 12:16:10
 * @FilePath: ex_21.c
 */

#include <stdio.h>
#define TAB 8
int entab();
// Write a program entab that replaces strings of blanks by the minimum number of tabs and
// blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
// would suffice to reach a tab stop, which should be given preference?
int main(){
    int c;
    size_t blankCount, p;
    blankCount = p = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ')
            blankCount++;
        else{
            while(blankCount / TAB){    // equal   while( (blankCount / TAB) != 0 )
                putchar('\t');
                blankCount -= TAB;
                p += TAB;
            }
            while(blankCount > 0){
                putchar(' ');
                blankCount--;
                p++;
            }
            putchar(c);
            p++;
        }
    }
    


    return 0;
}

int entab(){
    printf("\t");
    return 0;
}