/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-30 21:51:42
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-07-01 22:09:22
 * @FilePath: expand.c
 */
#include <stdio.h>
#include <ctype.h>
#define isExp(PREV, NEXT)   ((islower(PREV) && islower(NEXT)) || \
                            (isupper(PREV) && isupper(NEXT)) || \
                            (isdigit(PREV) && isdigit(PREV)))
void expand(const char s1[], char s2[]);

int main(){
    char s1[] = "a-elalal0-9";
    char s2[100];

    expand(s1, s2);
    printf("%s\n",s2);

    return 0;
}

void expand(const char s1[], char s2[]){
    int i,j;
    for (i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if(s1[i] == '-' && i && isExp(s1[i-1], s1[i+1])){
            j--;
            if(s1[i-1] > s1[i+1])
                for (char c = s1[i-1]; c >= s1[i+1]; c--)
                    s2[j++] = c;
            else
                for (char c = s1[i-1]; c <= s1[i+1]; c++)
                    s2[j++] = c;
            i++;
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}