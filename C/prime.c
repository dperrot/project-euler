/*
  prime.c
  
  Created: Jul 17, 2014
   Author: David Perrot
   
  This file handles functions related to primes for
  various problem sets to utilize.
*/
#include <math.h>

// GLOBAL VARIABLE DECLERATION
char* sieve;

// This function generates a boolean table for index values
// that are considered prime up to a given size.
void generate_sieve(unsigned long long sieve_size) {
  unsigned long sieve_size_sqrrt = sqrt(sieve_size);
  unsigned long long sieve_index = 2;
  unsigned long long sieve_comp_index;
  sieve = calloc(sieve_size + 1, sizeof(char));
  *sieve = 1; *(sieve + 1) = 1;
  
  while (sieve_index < sieve_size_sqrrt) {
    if (*(sieve + sieve_index) == 0) {
      sieve_comp_index = sieve_index * sieve_index;
      while (sieve_comp_index <= sieve_size) {
        *(sieve + sieve_comp_index) = 1;
        sieve_comp_index += sieve_index;
      }
    }
    sieve_index++;
  }
}

char is_composite(unsigned long long sieve_index) {
  return *(sieve + sieve_index);
}

void free_prime() { free(sieve); }