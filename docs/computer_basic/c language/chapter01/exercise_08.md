```c
#include <stdio.h>

main(){
  int count,lineCount,c;

  count=lineCount=0;
  while ((c = getchar()) != EOF)
  {
    if(c == '\n'){
      ++lineCount;
    }
    ++count;
  }
  printf("character count:%d\n line count:%d\n", count, lineCount);
}
```

