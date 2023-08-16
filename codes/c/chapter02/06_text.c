/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-24 09:16:55
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-24 13:20:06
 * @FilePath: 06_text.c
 */
#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

int main(){
    int i;
    i = 1 & 2;
    printf("%d\n", i);
    i = 1 && 2;
    printf("%d\n", i);

    int x = 0xAF32;//binary digit: 1010 1111 0011 0010
    printf("result: %u\n", getbits(x, 4, 3));
    return 0;
}

/* getbits: return n-bits field of x that begins at position p*/
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}

// 1010 1111 0011 0010      0xAF32 >> (4+1-3) = 0xAF32 >> 2
// 0010 1011 1100 1100      
//
// 1111 1111 1111 1000      (~0 << 3)
// 0000 0000 0000 0111      ~(~0 << 3)
// &
// 0010 1011 1100 1100
// 0000 0000 0000 0100      result = 4