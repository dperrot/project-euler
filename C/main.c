/*
  main.c | Main project euler class handler

  Created: Jul 12, 2014
   Author: David Perrot

  This file handles facilitating running different problem
  sets provided for each of the different classes as they
  are built over time.
*/
#include <stdio.h>
#include <sys/time.h>
#include "problems.h"

typedef void (*ProblemFunctions)();
ProblemFunctions problems[] = {&p001,
                               &p002,
                               &p003,
                               &p004,
                               &p005,
                               &p006,
                               &p007,
                               &p008,
                               &p009,
                               &p010,
                               &p011,
                               &p012};

int main(void)
{
	int main_i;
	struct timeval tm1;
	struct timeval tm2;
	unsigned long long main_t;

	while(1) {
		printf("Enter the problem number to solve: ");
		scanf("%d", &main_i);
		main_i -= 1;

		if (main_i < 0 || main_i >= sizeof(problems)) {
			printf("Problem number is out of range.\n\n");
			continue;
		}
		printf("Calculating...\n\n");
		gettimeofday(&tm1, NULL);

		problems[main_i]();

		gettimeofday(&tm2, NULL);
		main_t = 1000 * (tm2.tv_sec - tm1.tv_sec) + (tm2.tv_usec - tm1.tv_usec) / 1000;
		printf("\nTime of execution: %llu ms\n", main_t);
	}

}
