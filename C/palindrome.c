/*
  palindrome.c
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  This file handles functions related to palindromes
  for various problem sets to utilize.
*/

char is_palindromic (int num) {
  int n = num;
  int reverse = 0;
  char digit;
  
  while (n > 0) {
    digit = n % 10;
    reverse = reverse * 10 + digit;
    n /= 10;
  }
  
  return num == reverse;
}