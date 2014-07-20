/*
  p003.c | Problem 3 - Largest prime factor
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Generate prime sieve of given number and starting from the
  number's square root working backwards, find largest prime.
*/
#include <stdio.h>
#include "prime.h"

void p003() {
  unsigned long long number = 600851475143;
  unsigned long number_index = sqrt(number);
  generate_sieve(number_index);
  
  while(is_composite(number_index) || number % number_index > 0) {
    number_index--;
  }
  free_prime();
  
  printf("Largest prime factor of %llu is %lu.", number, number_index);
}