/*
  p016.c | Problem 16 - Power digit sum

  Created: Aug 10, 2014
   Author: David Perrot

  The char array is used as an 'ascii' digit placeholder
  (base 10). Simple multiplicitive math is then handled
  per digit over an iteration.
*/
#include <stdio.h>

void p016() {
  int limit = 1000;
  int base = 2;
  int digit_limit = 350;
  int pos = 1;
  int sum = 0;
  int i, j;
  char r;
  char* digits;

  digits = malloc(digit_limit * sizeof(char));
  digits[0] = 1;

  for (i = 1; i <= 1000; i++) {
    for (j = 0; j < pos; j++) {
       r = base * digits[j] + r;
       digits[j] = r % 10;
       r /= 10;
    }
    if (r > 0) { digits[pos++] = r; r = 0; }
  }

  for (i = 0; i < pos; i++) { sum += digits[i]; }

  printf("The sum of the digits of %d^%d is %d", base, limit, sum);
  free(digits);
}
