/*
  p006.c | Problem 6 - Sum square difference
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Iterative add of sum and square sum of the first 100
  numbers, then calculated the difference after squaring 
  the regular sum.
*/
#include <stdio.h>

void p006() {
  int result, i;
  int sum = 0;
  int square_sum = 0;
  
  for(i = 1; i <= 100; ++i) { 
    sum += i;
    square_sum += i * i;
  }
  result = sum * sum - square_sum;
  
  printf("The sum square difference of the first 100 numbers is %d.", result);
}