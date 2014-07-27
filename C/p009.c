/*
  p009.c | Problem 9 - Special Pythagorean triplet

  Created: Jul 23, 2014
   Author: David Perrot

  Increment a & b efficiently so all possible variants
  are checked once until target number is reached from
  secondary equation. The solution makes sure that
  non-triples are skipped through float vs. int comparison.
*/
#include <stdio.h>
#include <math.h>

void p009() {
  int target = 1000;
  int a = 1;
  int b = 1;
  int c, t1;
  double t2;

  do {
    t1 = a*a + b*b;
    t2 = sqrt(t1);
    if (t2 > target) { a++; b = a; continue; }
    c = (int) t2;
    if (t2 != c) { b++; continue; }
    if (a+b+c == target) { break; }
    b++;
  } while (1);

  printf("The pythagorean triplet %d^2 + %d^2 = %d^2 satisfies the equation:\n\n", a, b, c);
  printf("  %d + %d + %d = %d\n\n", a, b, c, target);
  printf("The resulting product is %d * %d * %d = %d", a, b, c, a*b*c);
}
