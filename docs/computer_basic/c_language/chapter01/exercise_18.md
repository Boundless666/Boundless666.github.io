```c
/*
 * File: exercise_18.c
 * File Created: Saturday, 6th May 2023 8:55:23 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Saturday, 6th May 2023 9:27:59 pm
 */

#include <stdio.h>
#define MAXLEN 1000
#define ISTRAIL 1
#define NOTRAIL 0

int get_line(char s[], int maxLen);
/* Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/
main(){
  int lineLen;
  char s[MAXLEN];
  while ((lineLen = get_line(s, MAXLEN)) > 0)
  {
    printf("%s", s);
    printf("%d\n", lineLen);
  }
  
}

int get_line(char s[], int maxLen){
  int c, i, endIndex, state;

  endIndex = maxLen - 1;
  for(i=0; i<maxLen-1 && (c = getchar()) != EOF && c != '\n'; ++i){
    if(c == ' ' || c == '\t'){
      if(endIndex == maxLen - 1)
        endIndex = i;
      s[i] = c;
    }
    else{
      endIndex = maxLen - 1;
      s[i] = c;
    }
  }
  if(endIndex != maxLen - 1){
    i = endIndex;
  }
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
```

