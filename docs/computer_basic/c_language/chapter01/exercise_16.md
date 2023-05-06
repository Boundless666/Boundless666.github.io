```c
/*
 * File: 09_longest.c
 * File Created: Saturday, 6th May 2023 8:49:45 am
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Saturday, 6th May 2023 8:45:08 pm
 */

#include <stdio.h>

#define MAXLEN 1000

int get_line(char s[], int maxlen);
void copy(char to[], char from[]);

// Revise the main routine of the longest-line program so it will correctly print the
// length of arbitrary long input lines, and as much as possible of the text
main(){
  int curLen, maxLen;
  char curArrs[MAXLEN];
  char maxArrs[MAXLEN];

  maxLen = 0;
  while ((curLen = get_line(curArrs, MAXLEN)) > 0)
  {
    if(curLen > maxLen){
      copy(maxArrs, curArrs);
      maxLen = curLen;
    }
  }
  
  if(maxLen > 0)
    printf("%s\n", maxArrs);
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

/* copy: copy chars 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

/*OUTLINE
  while(thers's another line)
    if(it's longer than previous longest)
      save(it)
      save(its length)
*/
```

