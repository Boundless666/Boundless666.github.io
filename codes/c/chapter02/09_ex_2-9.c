/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-24 21:37:07
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-25 22:11:56
 * @FilePath: 09_ex_2-9.c
 */
#include <stdio.h>
int bitcount(unsigned x);

int main(){
    unsigned x = 0x75;
    printf("the result is: %d\n", bitcount(x));
    
    return 0;
}


// int bitcount(unsigned x){
//     int count;
//     for(count = 0; x != 0; x >>= 1){
//         if(x & 0x1)
//             ++count;
//     }
//     return count;
// }

/* bitcount: count 1 bits in x*/
int bitcount(unsigned x){
    int count;
    for(count = 0; x != 0; x &= (x - 1))
        ++count;
    return count;
}
// a & b       The result is 1 when both a and b are 1
// x & (x-1)    
/*
    x            0X75     01110101     x has five 1-bits
    x-1          0X74     01110100     flipping the last bit
    x &= x-1     0X74     01110100     zeroing the last bit

    x            0X74     01110100     x now has four 1-bits
    x-1          0X73     01110011     flipping the three last bits
    x &= x-1     0X70     01110000     zeroing the three last bits
*/