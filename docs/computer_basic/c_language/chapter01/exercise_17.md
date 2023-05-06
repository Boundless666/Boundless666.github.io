```c
/*
 * File: exercise_17.c
 * File Created: Saturday, 6th May 2023 8:45:21 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Saturday, 6th May 2023 8:48:52 pm
 */

#include <stdio.h>

#define MAXLEN 1000

int get_line(char s[], int maxlen);
/* Write a program to print all input lines that are longer than 80 characters.*/
main(){
  int curLen, maxLen;
  char curArrs[MAXLEN];

  while ((curLen = get_line(curArrs, MAXLEN)) > 0)
  {
    if(curLen > 8)
      printf("%s \n", curArrs);
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
```

