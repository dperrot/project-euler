/*
  prime.h
  
  Created: Jul 17, 2014
   Author: David Perrot
   
  This file handles linking various problem sets to
  common prime functions for ease of facilitation.
*/

#ifndef PRIME_H_
#define PRIME_H_

void generate_sieve(unsigned long long sieve_size);
char is_composite(unsigned long long sieve_index);
void free_prime();

#endif