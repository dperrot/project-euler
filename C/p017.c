/*
  p017.c | Problem 17 - Number letter counts

  Created: Aug 13, 2014
   Author: David Perrot

  Using if-else cases, int numbers for letter
  counts and if-else cases for patterns of numbers,
  iteration of numbers 1 - 1000 occur to sum letter
  count.
*/
#include <stdio.h>

void p017() {
  int sum = 11; // 'one thousand'
  int i, n, t;

  for (i = 1; i < 1000; i++) {
    n = 0;

    if (i >= 100) {
      n += 7; // 'hundred'
      if (i % 100 != 0) { n += 3; } // 'and'
      t = i / 100;
      if (t == 1) { n += 3; }       // 'one'
      else if (t == 2) { n += 3; }  // 'two'
      else if (t == 3) { n += 5; }  // 'three'
      else if (t == 4) { n += 4; }  // 'four'
      else if (t == 5) { n += 4; }  // 'five'
      else if (t == 6) { n += 3; }  // 'six'
      else if (t == 7) { n += 5; }  // 'seven'
      else if (t == 8) { n += 5; }  // 'eight'
      else if (t == 9) { n += 4; }  // 'nine'
    }

    t = i % 100;
    if (t < 10 || t >= 20) {
      if (t >= 20) {
        t /= 10;
        if (t == 2) { n += 6; }       // 'twenty'
        else if (t == 3) { n += 6; }  // 'thirty'
        else if (t == 4) { n += 5; }  // 'forty'
        else if (t == 5) { n += 5; }  // 'fifty'
        else if (t == 6) { n += 5; }  // 'sixty'
        else if (t == 7) { n += 7; }  // 'seventy'
        else if (t == 8) { n += 6; }  // 'eighty'
        else if (t == 9) { n += 6; }  // 'ninety'
      }

      t = i % 10;
      if (t == 1) { n += 3; }       // 'one'
      else if (t == 2) { n += 3; }  // 'two'
      else if (t == 3) { n += 5; }  // 'three'
      else if (t == 4) { n += 4; }  // 'four'
      else if (t == 5) { n += 4; }  // 'five'
      else if (t == 6) { n += 3; }  // 'six'
      else if (t == 7) { n += 5; }  // 'seven'
      else if (t == 8) { n += 5; }  // 'eight'
      else if (t == 9) { n += 4; }  // 'nine'

    } else {
      if (t == 10) { n += 3; }      // 'ten'
      else if (t == 11) { n += 6; } // 'eleven'
      else if (t == 12) { n += 6; } // 'twelve'
      else if (t == 13) { n += 8; } // 'thirteen'
      else if (t == 14) { n += 8; } // 'fourteen'
      else if (t == 15) { n += 7; } // 'fifteen'
      else if (t == 16) { n += 7; } // 'sixteen'
      else if (t == 17) { n += 9; } // 'seventeen'
      else if (t == 18) { n += 8; } // 'eighteen'
      else if (t == 19) { n += 8; } // 'nineteen'
    }

    sum += n;
  }

  printf("The sum of the letter counts from 1 to 1000 is %d", sum);
}
