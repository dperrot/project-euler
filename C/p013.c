/*
  p013.c | Problem 13 - Large sum

  Created: Jul 27, 2014
   Author: David Perrot

  Given a text file with numbers of arbritrary length to sum,
  we utilize old school arithmetic (summation per column) to
  figure out the answer. The majority of this program deals
  with file manipulation and position seeking, thanks to the
  C language.
*/
#include <stdio.h>

void p013() {
  FILE* fp;
  int i = 1;
  int sum = 0;
  int target_width = 10;
  int lines = 1;
  int width = 0;
  int pos = 1;
  int n, l;
  char* total_sum;
  int* width_list;

  // Load data file for this problem.
  fp = fopen("data/p013.txt", "r");
  if (fp == NULL) {
    printf("Cannot run the problem. Data file does not exist.");
    return;
  }

  // Add numbers using old school arithmetic for all
  // columns. Leave enough room for expansion of total
  // sum.
  while (getc(fp) != '\n') { width++; }
  while (EOF != (fscanf(fp, "%*[^\n]"), fscanf(fp, "%*c"))) { lines++; }
  pos = width * 4;
  total_sum = (char *)malloc(pos * sizeof(char));
  width_list = (int *)calloc(lines, sizeof(int));
  width_list[0] = width;
  rewind(fp);

  do {
    for (l = 0; l < lines; l++) {
      if (width_list[l] > 0) {
        fscanf(fp, "%*[^\n]");
        width = width_list[l];
      } else {
        width = 0;
        while (getc(fp) != '\n') { width++; }
        width_list[l] = width;
        fseek(fp, -2, SEEK_CUR); // Data has CR+LF for line break.
      }

      if (i > width) {
        fscanf(fp, "%*c");
        continue;
      }

      fseek(fp, -i, SEEK_CUR);
      fscanf(fp, "%1d", &n);
      sum += n;
      fscanf(fp, "%*[^\n]");
      fscanf(fp, "%*c");
    }
    total_sum[pos-(i++)] = sum % 10;
    sum /= 10;
    rewind(fp);
  } while (sum > 0);

  width = pos - i + 1;
  printf("The first 10 digits of the sum of large numbers is ");
  for (i = 0; i < target_width; ++i) { printf("%d", total_sum[width+i]); }
  free(total_sum);
  free(width_list);
}
