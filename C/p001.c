/*
 * p001.c
 *
 *  Created on: Jul 12, 2014
 *      Author: David Perrot
 */
#include <stdio.h>

void p001()
{
	int sum;
	int i;

	for( i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("Sum is: %d", sum);
}
