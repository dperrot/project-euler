/*
  p004.c | Problem 4 - Largest palindrome product
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Iterating between two numbers between 100 - 999 inclusive,
  numbers are checked if they are palindromes and stored if
  they are the highest set.
*/
#include <stdio.h>
#include "palindrome.h"

void p004() {
  int a, b, max_a, max_b, p;
  int max = 0;
  
  for(a = 100; a < 1000; a++) {
    for (b = a; b < 1000; b++) {
      p = a * b;
      if (is_palindromic(p) && p > max) {
        max = p;
        max_a = a;
        max_b = b;
      }
    }
  }
  
  printf("Largest palindromic product of two 3-digit numbers is %d * %d = %d.", max_a, max_b, max);
}