/*
  p015.c | Problem 15 - Lattice paths

  Created: Aug 10, 2014
   Author: David Perrot

  Utilizing Pascal's triangle, a 2D array is built using
  the given grid size, adding them together and finding the
  bottom middle number of the triangle set to find the
  number of lattice points used for the given grid.
*/
#include <stdio.h>

void p015() {
  int target = 20;
  unsigned long long** triangle;
  int i, j, t2;

  t2 = target + target;
  triangle = (unsigned long long**)malloc((t2 + 1) * sizeof(unsigned long long));
  for (i = 0; i <= t2; i++) {
    triangle[i] = (unsigned long long*)malloc((i+1) * sizeof(unsigned long long));
    triangle[i][0] = 1;
    triangle[i][i] = 1;
    for (j = 1; j < i; j++) {
      triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
    }
  }

  printf("The number of lattice paths for a %dx%d grid is %llu", target, target, triangle[t2][t2/2]);
  for (i = 0; i <= t2; i++) { free(triangle[i]); }
  free(triangle);
}
