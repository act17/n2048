#include <stdio.h>
#include <stdlib.h>

void ltr(int array[4][4]) {

  for (int y = 0; y < 4; y++) {

    for (int x = 0; x < 3; x++) {

      // This routine occurs when there's two elements of the
      // same value next to eachother.
      // It combines the two elements, leaving a zero in the
      // right (higher-valued) element.
      if (array[y][x + 1] == array[y][x]) {
        array[y][x + 1] = array[y][x] * 2;
        array[y][x] = 0;
      }

      // This routine occurs when there's a zero in the array.
      // It shifts an element to the left, being repeated until
      // no longer nessicary.
      if (array[y][x + 1] == 0) {
        array[y][x + 1] = array[y][x];
        array[y][x] = 0;
      }
    }
  }

  return;
}
