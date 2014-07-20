/*
  p008.c | Problem 8 - Largest product in a series
  
  Created: Jul 19, 2014
   Author: David Perrot
   
  Description of solution here.
*/
#include <stdio.h>

void p008() {
  FILE *fp;
  int size = 13;
  int i = 0;
  int j;
  char products[size];
  char max_products[size];
  char ch;
  unsigned long long result;
  unsigned long long max = 0;
  
  fp = fopen("data/p008.txt", "r");
  if (fp == NULL) {
    printf("Cannot run the problem. Data file does not exist.");
    return;
  }
  
  // Initialize product array since we use variable-sized objects.
  memset(products, 0, sizeof products);
  
  // Iterate through the file, taking out only the first
  // number in sequence from result and putting in the next number
  // for efficiency. Store products and max when reached.
  while ((ch = fgetc(fp)) != EOF) {
    result = 1;
    products[i] = ch - '0';
    if (products[i] >= 0 && products[i] <= 9) {
      for(j = 0; j < size; j++) { result *= products[j]; }
      if (result > max) {
        max = result;
        for(j = 0; j < size; j++) { max_products[j] = products[j]; }
      }
      i = (i+1) % size;
    } else {
      printf("Invalid char detected in file.");
      return;
    }
  }
  fclose(fp);
  
  printf("The highest products from the series is as follows:\n");
  for(i = 0; i < size-1; i++) { printf("%d * ", max_products[i]); }
  printf("%d = %llu", max_products[size-1], max);
}