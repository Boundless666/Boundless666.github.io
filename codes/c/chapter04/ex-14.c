/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-03 21:52:38
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-07 21:50:59
 * @FilePath: ex-14.c
 */
#include <stdio.h>

#define swap(t,x,y) t tmp = x;  \
                    x = y;      \
                    y = tmp;    
                    

#if SYSTEM == SYSV
    #define HDR "stdio.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR

int main(){
    int x , y;
    x = 2;
    y = 3;
    swap(int, x, y);

    printf("x = %d, y = %d \n", x, y);

    return 0;
}