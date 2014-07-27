/*
  p012.c | Problem 12 - Highly divisible triangular number

  Created: Jul 27, 2014
   Author: David Perrot

  Iterate triangle numbers indefinitely. For each one, find
  the divisor by utilizing a product series and primes to greatly
  reduce calculation time vs. brute force iteration of numbers
  and using modulo. No need to generate a prime sieve as dividing
  the temporary triangle number eliminates composites from the
  calculation.
*/
#include <stdio.h>

void p012() {
  int i = 3;
  int target = 500;
  int j, tri, tri_tmp, divisor, d_count;

  while(1) {
    tri = triangle(i++);
    tri_tmp = tri;
    divisor = 1;
    for (j = 2; j <= tri_tmp; j++) {
      if (tri_tmp % j == 0) {
        d_count = 0;
        do {
          d_count++;
          tri_tmp /= j;
        } while (tri_tmp % j == 0);
        divisor *= d_count + 1;
      }
    }
    if (divisor > target) { break; }
  }

  printf("The first triangle number with over %d divisors (%d) is %d.", target, divisor, tri);
}

int triangle(int n) { return (n*(n+1))/2; }
