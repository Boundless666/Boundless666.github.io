```c
/*
 * File: exercise_19.c
 * File Created: Saturday, 6th May 2023 9:33:49 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Saturday, 6th May 2023 9:48:13 pm
 */

#include <stdio.h>

#define MAXLEN 1000

int get_line(char s[], int maxlen);
void c_reverse(char s[], int len);
/* Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.*/
main(){
  int curLen, maxLen;
  char curArrs[MAXLEN];

  while ((curLen = get_line(curArrs, MAXLEN)) > 0)
  {
    c_reverse(curArrs,curLen);
    // printf("%s \n", curArrs);
  }
  
  return 0;
}

/* getline: fetch next line into s and return it's length*/
int get_line(char s[], int maxLen){
  int i,c;
  
  for (i = 0; i < maxLen-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
void c_reverse(char s[], int len){
  int i;
  char tmp;
  for(i=0; i<len/2; ++i){
    tmp = s[i];
    s[i] = s[len - i - 2];
    s[len - i - 2] = tmp;
  }
  printf("%s",s);
}
```

