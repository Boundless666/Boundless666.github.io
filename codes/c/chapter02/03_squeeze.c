/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-23 12:16:08
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-23 12:22:06
 * @FilePath: 03_squeeze.c
 */
#include <stdio.h>
void squeeze(char s[], int c);

int main(){
    char s[] = "hello! this is test";
    printf("old str is: %s\n", s);
    squeeze(s, 'i');
    printf("new str is: %s\n", s);
    return 0;
}

/* squeeze: delete all c from s*/
void squeeze(char s[], int c){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++){
        if(s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}