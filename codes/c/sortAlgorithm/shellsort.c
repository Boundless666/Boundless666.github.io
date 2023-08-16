/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-30 21:30:20
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-30 21:38:15
 * @FilePath: shellsort.c
 */

/* shellsort: sort v[0],v[1].... increasing order*/
void shellsort(int v[], int n){
    int i, j, temp, gap;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; ++i){
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
                temp = v[j+gap];
                v[j+gap] = v[j];
                v[j] = temp;
            }
        }
    }
    
}