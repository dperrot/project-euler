/*
  p001.c | Problem 1 - Multiples of 3 and 5
 
  Created: Jul 12, 2014
   Author: David Perrot
   
  Iterative summation of numbers divisible by 3 and 5
  until the target is reached.
*/
#include <stdio.h>

void p001() {
	int sum;
	int i;

	for( i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("Sum is: %d", sum);
}
