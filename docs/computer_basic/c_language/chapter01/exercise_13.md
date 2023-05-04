```c
/*
 * File: exercise_13.c
 * File Created: Thursday, 4th May 2023 8:40:46 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Thursday, 4th May 2023 9:58:50 pm
 */

#include <stdio.h>
// Write a program to print a histogram of the lengths of words in its input. It is
// easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging
main(){
  int c, nw;
  nw = 0;
  while ((c = getchar()) != EOF)
  {
    if(c == ' ' || c == '\t' || c == '\n'){
      printf("%d ", nw);
      nw = 0;
    }
    else{
      ++nw;
    }
  }
  
}
```

