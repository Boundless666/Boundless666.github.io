##### 1.5 File

File Coping

```c
#	read a character
# 		while(character is not end-of-file indicator)
#			output the character just read
#			read a character
main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

#	while((c = getchar()) != EOF){
#   	putchar(c);
#	}
```

> How do that input the EOF symbols?
>
> in the Linux system.
>
> press **ctrl+d** keys.

##### 1.5.3 Character Counter

```c
#include <stdio.h>

main(){
  // 1 version
  // long nc;

  // nc=0;
  // while (getchar() != EOF)
  // {
  //   ++nc;
  // }
  // printf("%1d\n",nc);
  
  // 2 version
  double nc;
  for(nc = 0; getchar() != EOF; ++nc);
  printf("%0.f\n", nc);
    
  // 3 version
  double nc;
  char curChar = getchar();
  for(nc = 0; curChar != EOF && curChar != '\n'; ++nc);
    curChar = getchar();
  printf("%0.f\n", nc);
}
```

