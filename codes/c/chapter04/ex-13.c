/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-01 22:08:42
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-01 22:23:55
 * @FilePath: ex-13.c
 */
#include <stdio.h>
#include <string.h>

void reverse(char *s);
/* reverse string*/
int main(){
    char s[] = "hello!";
    reverse(s);
    printf("%s\n", s);

    return 0;
}

/* reverse string.use recursive method*/
void reverse(char *s){
    static int left = 0, right;
    if(left == 0)
        right = strlen(s) - 1;
    if(right - left <= 1)
        return;
    int temp;
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
    reverse(s);
}