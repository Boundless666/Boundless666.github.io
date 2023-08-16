/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-24 17:34:52
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-24 17:51:05
 * @FilePath: 08_ex_2-7.c
 */
#include <stdio.h>
unsigned invert(unsigned x, int p, int n);

int main(){
    unsigned x = 0x2A75;    //10869
    printf("the result :%u \n", invert(x, 5, 2));
    return 0;
}

/* invert: return x with n bits that begin at position p inverted(eg. 1 changed into 0 and vice versa)*/
unsigned invert(unsigned x, int p, int n){
    return x ^ ~((~0 << p) | ~(~0 << (p-n)));
}