/*
  p014.c | Problem 14 - Longest Collatz sequence

  Created: Aug 9, 2014
   Author: David Perrot

  Iterating from 2 to target length (with value of
  the collatz chain of 1 stored), solve for chain
  length. Store the length of the chain for each
  number within the limit to speed up the process
  of calculation.
*/
#include <stdio.h>

void p014() {
  int limit = 1000000;
  int max_n = 1;
  int chain_size = 3000;
  int* collatz_count;
  unsigned long long* chain;
  int n, i, pos;
  unsigned long long n2;

  collatz_count = (int *)calloc(limit, sizeof(int));
  chain = (unsigned long long *)malloc(chain_size * sizeof(unsigned long long));
  collatz_count[1] = 1;

  for (n = 2; n < limit; n++) {
    n2 = n; pos = 0;
    while (n2 >= limit || collatz_count[n2] == 0) {
      chain[pos++] = n2;
      if (pos == chain_size) {
        printf("Chain size limit reached. Cannot proceed any further.");
        return;
      }
      n2 = n2%2 ? n2*3+1 : n2/2;
    }

    for (i = 1; i <= pos; i++) {
      if (chain[pos-i] >= limit) { continue; }
      collatz_count[chain[pos-i]] = collatz_count[n2] + i;
    }
    if (collatz_count[chain[0]] > collatz_count[max_n]) { max_n = chain[0]; }
  }

  printf("The number with the longest collatz chain (%d) is %d", collatz_count[max_n], max_n);
  free(collatz_count);
  free(chain);
}
