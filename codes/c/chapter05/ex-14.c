/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-30 22:14:14
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-09-17 17:47:42
 * @FilePath: ex-14.c
 */
/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-08-26 22:35:15
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-08-30 22:14:14
 * @FilePath: ex-14.c
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int (*compare)(void *left, void *right);            // *(int compare(void *left, void *right) )
int reverseCompare(void *left, void *right);
int partition(void *v[], int left, int right, int (*comp)(void *, void *));
int strcmp(char *left, char *right);
int numcmp(char *left, char *right);

int main(int argc, char *argv[]){
    char *p = *++argv;
    int reverse = FALSE;
    int numeric = FALSE;
    while(--argc > 0){
        if(*p == '-'){
            while(*++p != '\0'){
                switch(*p){
                    case 'r': reverse = TRUE; break;
                    case 'n': numeric = TRUE; break;
                    default: printf("error: input parameters invalid\n"); break;
                }
            }
        }
    }
    reverse = TRUE;
    compare = (int (*)(void *, void *))(numeric ? numcmp : strcmp);
    int (*comp)(void *, void *) = reverse ? reverseCompare : compare;

    //char *arr[] = {"123", "1223", "45"};
    char *arr[] = {"abc", "abd", "abcd"};
    partition((void **)arr, 0, 2, comp);

    for(int i = 0; i < 3; i++)
        printf("%s\t", arr[i]);
    printf("\n");

    return 0;
}

void swap(void *v[], int i, int j){
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int partition(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i , j;
    i = left;
    j = right;
    while(i < j){
        while(i < j && ((*comp)(v[j], v[left]) >= 0))
            j--;
        while(i < j && ((*comp)(v[i], v[left]) <= 0))
            i++;
        if(i < j)
            swap(v, i, j);
    }
    swap(v, i, left);
    return i;
}

void mysqort(void *v[], int left, int right, int (*comp)(void *, void *)){
    if(left >= right)
        return;
    
    int mid = partition(v, left, right, comp);
    mysqort(v, left, mid - 1, comp);
    mysqort(v, mid+1, right, comp);
}

int strcmp(char *left, char *right){
    int res;
    for(; *left == *right; left++, right++)
        if(*left == '\0')
            return 0;
    if(*left > *right)
        return 1;
    return -1;
}

int numcmp(char *left, char *right){
    double l, r;
    l = atof(left);
    r = atof(right);
    if(l < r)
        return -1;
    else if (l > r)
        return 1;
    else
        return 0;
}

int reverseCompare(void *left, void *right){
    return (*compare)(right, left);
}