```c
/*
 * File: exercise_14.c
 * File Created: Thursday, 4th May 2023 9:38:37 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Thursday, 4th May 2023 9:58:39 pm
 */

#include <stdio.h>

// Write a program to print a histogram of the frequencies of different characters
// in its input.
main(){
  int c, i;
  char cCounts[26];
  for(i=0; i<26; i++)
    cCounts[i] = 0;

  while ((c = getchar()) != EOF)
  {
    if(c >= 'a' && c <= 'z')
      ++cCounts[c - 'a'];
  }
  
  for(i=0; i<26; i++)
    printf(" %d", cCounts[i]);
  printf("\n");
  for(i=0; i<26; i++)
    printf(" %c", 'a'+i);
  printf("\n");
}
```

