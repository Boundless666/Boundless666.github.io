/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-23 17:21:10
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-23 17:31:47
 * @FilePath: 05_ex_2-5.c
 */
#include <stdio.h>
int any(char s1[], char s2[]);

int main(){
    char s1[] = "Hello this is test";
    char s2[] = "ehi";
    printf("the location is: %d \n", any(s1, s2));

    return 0;
}

/* any: return the first location in string s1 where any character from the string s2 occurs*/
int any(char s1[], char s2[]){
    int i, flag, set[128] = {0};
    for(i = 0; s2[i] != '\0'; ++i)
        if(set[s2[i] - '0'] == 0)
            set[s2[i] - '0'] = 1;
    
    for(i = flag = 0; s1[i] != '\0'; ++i)
        if(set[s1[i] - '0'] == 1){
            flag = 1;
            break;
        }
    if(flag == 0)
        i = -1;
    return i;
}