> Modify the temperature conversion program to print a heading above the table

```c
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

main(){
	int fahr;
	printf("Fahrenheit temperatures \t Celsius\n");
	for(fahr=LOWER; fahr <= UPPER; fahr += STEP){
		
    printf("\t%3d \t\t\t%6.1f\n",fahr,(5.0 / 9.0) * (fahr -32));
	}

}
```

