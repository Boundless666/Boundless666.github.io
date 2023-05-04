```c
/*
 * File: exercise_12.c
 * File Created: Wednesday, 3rd May 2023 4:26:32 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Thursday, 4th May 2023 9:59:07 pm
 */

#include <stdio.h>
#define IN 1    // word character start.
#define OUT 0   // word character end.

// Write a program that prints its input one word per line.
main(){
  int c, nl, nw, state;
  state = OUT;
  nl = nw = 0;

  while ((c = getchar()) != EOF)
  {
    putchar(c);
    if(c == ' ' || c == '\t' || c == '\n'){
      putchar('\n');
    }
  }
  
}
```

