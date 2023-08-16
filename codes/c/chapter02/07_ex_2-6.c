/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-24 13:03:54
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-24 17:34:39
 * @FilePath: 07_ex_2-6.c
 */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);

/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged.*/
int main(){
    unsigned x = 0xAB2A;    //43818
    printf("the result: %u\n", setbits(x, 5, 2, 0x260A));
    return 0;
}

/* setbits: return x with n bits that begin at position p set to the rightmost n bits of y*/
unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ((~0 << p) | ~(~0 << n))) | ((y & ~(~0 << n)) << (p - n));
}

/*
x:  1010 1011 0010 1010         p:5 n:2 y:  0010 0110 0000 1010
    &                                       &
~   1111 1111 1110 0111                     0000 0000 0000 0011
                                            0000 0000 0000 0010
                                            << (p-n)
    1010 1011 0010 0010                     0000 0000 0001 0000
    |                                       
    0000 0000 0001 1000
res:1010 1011 0011 1010
*/