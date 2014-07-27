/*
  p011.c | Problem 11 - Largest product in a grid

  Created: Jul 26, 2014
   Author: David Perrot

  Load the given data file into a 2D array, determining
  the width and height. Iterate through the 2D array and
  perform product series calculations and determine the
  largest product given the series.
*/
#include <stdio.h>

void p011() {
  FILE *fp;
  int** grid;
  int width  = 0;
  int height = 1;
  int num_count = 4;
  int i, j, k, p;
  int num_max = 0;
  int* products;

  // Load data file for this problem.
  fp = fopen("data/p011.txt", "r");
  if (fp == NULL) {
    printf("Cannot run the problem. Data file does not exist.");
    return;
  }

  // Get width
  do {
    fscanf(fp, "%*d");
    width++;
  } while (getc(fp) != '\n');

  // Get height
  while (EOF != (fscanf(fp, "%*[^\n]"), fscanf(fp, "%*c"))) {
    height++;
  }

  // Transfer data file numbers to the grid.
  rewind(fp);
  grid = (int **)malloc(width * sizeof(int));
  for (i = 0; i < height; ++i) {
    grid[i] = (int *)malloc(height * sizeof(int));
  }

  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {
      fscanf(fp, "%d", &grid[i][j]);
    }
  }
  fclose(fp);

  // Iterate through the grid and if possibe,
  // do a product series in all directions with
  // the given count. Store max value.
  products = (int *)malloc(num_count * sizeof(int));
  for (j = 0; j < height; ++j) {
    for (i = 0; i < width; ++i) {
      // Down + Left
      if (i - num_count >= 0 && j + num_count < height) {
        p = 1;
        for (k = 0; k < num_count; ++k) { p *= grid[i-k][j+k]; }
        if (p > num_max) {
          num_max = p;
          for (k = 0; k < num_count; ++k) { products[k] = grid[i-k][j+k]; }
        }
      }

      // Down
      if (j + num_count < height) {
        p = 1;
        for (k = 0; k < num_count; ++k) { p *= grid[i][j+k]; }
        if (p > num_max) {
          num_max = p;
          for (k = 0; k < num_count; ++k) { products[k] = grid[i][j+k]; }
        }
      }

      // Down + Right
      if (i + num_count < width && j + num_count < height) {
        p = 1;
        for (k = 0; k < num_count; ++k) { p *= grid[i+k][j+k]; }
        if (p > num_max) {
          num_max = p;
          for (k = 0; k < num_count; ++k) { products[k] = grid[i+k][j+k]; }
        }
      }

      // Right
      if (i + num_count < width) {
        p = 1;
        for (k = 0; k < num_count; ++k) { p *= grid[i+k][j]; }
        if (p > num_max) {
          num_max = p;
          for (k = 0; k < num_count; ++k) { products[k] = grid[i+k][j]; }
        }
      }
    }
  }

  // Free memory and print result
  for (i = 0; i < height; ++i) { free(grid[i]); }
  free(grid);
  printf("The largest product in the grid is ");
  for (i = 0; i < num_count-1; ++i) { printf("%d * ", products[i]); }
  printf("%d = %d", products[num_count-1], num_max);
  free(products);
}
