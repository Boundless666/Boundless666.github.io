```c
/*
 * File: exercise_10.c
 * File Created: Tuesday, 2nd May 2023 11:09:46 am
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Thursday, 4th May 2023 9:59:23 pm
 */

#include <stdio.h>

// Write a program to copy its input to its output, replacing each tab by \t, each
// backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
// unambiguous way.
main(){
  int c;

  while ((c = getchar()) != EOF)
  {
    if(c == '\t'){
      printf("\\t");
    }
    else if(c == '\b'){
      printf("\\b");
    }
    else if(c == '\\'){
      printf("\\\\");
    }
    else{
      printf("%c",c);
    }
  }
  
}
```

