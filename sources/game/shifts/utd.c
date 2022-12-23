#include <stdio.h>
#include <stdlib.h>

void utd(int array[4][4]) {

  // As opposed to rtl(); and ltr();, dtu(); and utd(); focuses on the 'Y-Axis'
  // for shifts and all that.
  for (int x = 0; x < 4; x++) {

    for (int y = 0; y < 3; y++) {

      // This routine occurs when there's two elements of the
      // same value next to eachother.
      // It combines the two elements, leaving a zero in the
      // right (higher-valued) element.
      if (array[y + 1][x] == array[y][x]) {
        array[y + 1][x] = array[y][x] * 2;
        array[y][x] = 0;
      }

      // This routine occurs when there's a zero in the array.
      // It shifts an element to the left, being repeated until
      // no longer nessicary.
      if (array[y + 1][x] == 0) {
        array[y + 1][x] = array[y][x];
        array[y][x] = 0;
      }
    }
  }

  return;
}
