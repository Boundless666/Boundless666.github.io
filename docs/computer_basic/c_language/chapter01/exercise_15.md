```c
/*
 * File: exercise_15.c
 * File Created: Friday, 5th May 2023 2:49:18 pm
 * Author: 无涯 (mxl233@qq.com)
 * Last Modified: Friday, 5th May 2023 2:53:38 pm
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float temperatureConvert(int fahr);

main(){
	int fahr;
	printf("Fahrenheit temperatures \t Celsius\n");
	for(fahr=LOWER; fahr <= UPPER; fahr += STEP){
		
    printf("\t%3d \t\t\t%6.1f\n",fahr,temperatureConvert(fahr));
	}

}

float temperatureConvert(int fahr){
  return (5.0 / 9.0) * (fahr - 32);
}
```

