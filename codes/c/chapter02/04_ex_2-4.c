/*
 * @Author: 无涯 (mxl233@qq.com)
 * @Date: 2023-06-23 16:45:37
 * @LastEditors: 开心好梦🥳
 * @LastEditTime: 2023-06-23 17:18:55
 * @FilePath: 04_ex_2-4.c
 */
#include <stdio.h>
void squeeze(char s[], char c[]);

int main(){
    char s[] = "Hello! this Is test!";
    char c[] = "Hi";
    printf("old str is : %s\n", s);
    squeeze(s, c);
    printf("new str is : %s\n", s);

    return 0;
}

/* squeeze: delete each character in s that matches any character in the string c*/
void squeeze(char s[], char c[]){
    int i, j, set[128] = {0};
    for(i = 0; c[i] != '\0'; ++i)
        if(set[c[i] - '0'] == 0)
            set[c[i] - '0'] = 1;
    
    for(i = j = 0; s[i] != '\0'; ++i){
        if(set[s[i] - '0'] == 0)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

/* squeeze: delete each character in s that matches any character(Non-case sensitive) in the string c*/
// void squeeze(char s[], char c[]){
//     int i, j, set[26]={0};
//     for(i = 0; c[i] != '\0'; ++i)
//     {
//         if(c[i] >= 'A' && c[i] <= 'Z')
//             if(set[c[i] - 'A'] == 0)
//                 set[c[i] - 'A'] = 1;
//         else if(c[i] >= 'a' && c[i] <= 'z')
//             if(set[c[i] - 'a'] == 0)
//                 set[c[i] - 'a'] = 1;
//     }

//     for(i = j = 0; s[i] != '\0'; ++i){
//         if(s[i] >= 'A' && s[i] <= 'Z')
//             if(set[s[i] - 'A'] == 0)
//                 s[j++] = s[i];
//         else if(s[i] >= 'a' && s[i] <= 'z')
//             if(set[s[i] - 'a'] == 0)
//                 s[j++] = s[i];
//     }
//     s[j] = '\0';
// }