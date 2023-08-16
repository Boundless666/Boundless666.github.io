/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-21 15:45:20
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-21 16:50:13
 * @FilePath: 02_htoi.c
 */
#include <stdio.h>
#define HEX 16
#define DEC 10

int htoi(const char hex[]);

int main(){
    char hex[] = "0xabcde";
    printf("%d\n", htoi(hex));
    return 0;
}

/* htoi: converts a string of hexadecimal digits(including an optional 0x or 0X) into its equivalent integer value.*/
int htoi(const char hex[]){
    int res,i;
    i = res = 0;
    if(hex[i] == '0')
    {
        ++i;
        if(hex[i] == 'x' || hex[i] == 'X')
            ++i;
    }
    for(; hex[i] != '\0'; ++i){
        if(hex[i] >= '0' && hex[i] <= '9')
            res = res * HEX + hex[i];
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            res = res * HEX + (hex[i] - 'a' + DEC);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            res = res * HEX + (hex[i] - 'A' + DEC);
        else
            res = 0;
    }
    return res;
}