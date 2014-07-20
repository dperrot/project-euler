/*
  p005.c | Problem 5 - Smallest multiple
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Increment the number to check by 20, and for every increment,
  check that each modulus operation from 1-20 equals 0.
*/
#include <stdio.h>

void p005() {
  char mod = 2;
  int num = 20;
  
  while(mod <= 20) {
    if (!(num % mod)) { mod++; }
    else { mod = 2; num += 20; }
  }
  
  printf("Smallest multiple that is evenly divisible by numbers 1 - 20: %d", num);
}