/*
 * p002.c
 *
 *  Created on: Jul 16, 2014
 *      Author: David Perrot
 */
#include <stdio.h>

void p002()
{
  int LIMIT = 4000000;
	int sum = 2;
	int a = 1;
  int b = 2;
  int temp = a+b;

	while (temp < LIMIT) {
    if (temp % 2 == 0) { sum += temp; }
    a = b;
    b = temp;
    temp = a+b;
  }
  
	printf("Sum is: %d", sum);
}
