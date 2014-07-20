/* 
  p002.c | Problem 2 - Even Fibonacci numbers
  
  Created: Jul 16, 2014
   Author: David Perrot
  
  Iterative summation of even numbers through a while loop
  until the limit number is reached.
*/
#include <stdio.h>

void p002() {
  int limit = 4000000;
	int sum = 2;
	int a = 1;
  int b = 2;
  int temp = a+b;

	while (temp < limit) {
    if (temp % 2 == 0) { sum += temp; }
    a = b;
    b = temp;
    temp = a+b;
  }
  
	printf("Sum is: %d", sum);
}
