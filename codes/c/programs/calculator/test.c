/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-07-29 11:25:06
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-03 21:47:48
 * @FilePath: test.c
 */
#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main(){
	dprint(2/3);
	dprint("this is test \\");

	return 0;
}