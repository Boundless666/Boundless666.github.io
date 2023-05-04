```c
// Write a program to copy its input to its output, replacing each string of one or
// more blanks by a single blank.
#include <stdio.h>
#define true 1
#define false 0
#define LEN 10

main(){
  int c,index;
  int preIsBlank = false;
  index = 0;
  char res[LEN];
  while ( (c = getchar()) != EOF && index<LEN)
  {
    if(c == ' '){
      if( preIsBlank == true){
        // printf("skip index:%d\n", index);
        continue;
      }
      preIsBlank = true;
    }
    else{
      preIsBlank = false;
    }
    res[index++] = c;
  }
  // printf("index value:%d\n", index);
  printf("the result:\n%s \n", res);
}
```

