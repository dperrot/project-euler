/*
  p007.c | Problem 7 - 10001st prime
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Generate a prime sieve of arbritrary length,
  then iterate to find 10001st prime.
*/
#include <stdio.h>
#include "prime.h"

void p007() {
  int counter = 0;
  int i = 0;
  
  generate_sieve(200000);
  while(counter < 10001) {
    if (!is_composite(i++)) { counter++; }
  }
  i--;
  free_prime();
  
  printf("The 10001st prime is %d", i);
}