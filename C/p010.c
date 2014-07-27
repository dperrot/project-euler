/*
  p010.c | Problem 10 - Summation of primes

  Created: Jul 23, 2014
   Author: David Perrot

  Utilize the common prime class to create prime sieves
  and sum all primes below target number.
*/
#include <stdio.h>
#include "prime.h"

void p010() {
  int target = 2000000;
  int i;
  unsigned long long sum = 0;

  generate_sieve(target);
  for (i = 0; i < target; i++) {
    if (!is_composite(i)) { sum += i; }
  }
  free_prime();

  printf("The sum of all primes below %d is %llu", target, sum);
}
