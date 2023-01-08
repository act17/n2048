#include "shifts.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NCursesGame(int Ymax, int Xmax) {

  // First we need to create the windows - and the integer for user input.
  WINDOW *Tiles[4][4];
  int Selection;

  // And for the sake of it, lets create operators that will be used to generate
  // a two in a random empty space right now.
  srand(time(0));
  int RandomX = rand() % 4;
  int RandomY = rand() % 4;

  // Next is to create the array that tile data will be stored in.
  int TileData[4][4] = {(0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0)};

  // Then we create our relative start positions
  int RelativeY = (Ymax - 32) / 2;
  int RelativeX = (Xmax - 72) / 2;

  // And then we init the colour pairs
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_CYAN, COLOR_CYAN);
  init_pair(3, COLOR_BLUE, COLOR_WHITE);

  // Then we apply the color to the background
  wbkgd(stdscr, COLOR_PAIR(2));

  // Finally we enable keypad usage.
  keypad(stdscr, TRUE);

  // Now to initialize the windows.

  // This loop will go through all 4 sets of windows on the "y-axis".
  for (int y = 0; y < 4; y++) {

    // This loop will go through the 4 windows on the "x-axis".
    for (int x = 0; x < 4; x++) {

      // This creates the window. The size is standardized to 8x18, and the
      // position will be equal to the relative X and Y, plus an offset that
      // is determined by which window it is. (E.g., the first window will have
      // no offset, while the last window will have the greatest.)
      Tiles[y][x] = newwin(8, 18, RelativeY + (8 * y), RelativeX + (18 * x));

      // Then, we add things like color and boxes to each window.
      // We capstone this with a refresh to the window.
      wbkgd(Tiles[y][x], COLOR_PAIR(1));
      wattron(Tiles[y][x], COLOR_PAIR(1));
      box(Tiles[y][x], 1, 1);
      wrefresh(Tiles[y][x]);
    }
  }

  // Now for the game loop.

  // Currently, since there's no "game end" detection, we'll just set this to a
  // while() loop.
  while (1) {

    // Step Zero: We add a random 2 to the tiledata, if there's an empty space
    // for it. This loop finds an empty space.
    while (TileData[RandomX][RandomY] != 0) {
      srand(time(0));
      RandomX = rand() % 4;
      srand(time(0));
      RandomY = rand() % 4;
    }

    // Once the empty space is found, we replace that empty space with a 2 and
    // regenerate a new random position.
    TileData[RandomX][RandomY] = 2;
    srand(time(0));
    RandomX = rand() % 4;
    RandomY = rand() % 4;

    // First up is to print the tile data to a corresponding tile. We do this
    // with two for-loops.
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {

        // In the case that the tile is NOT zero, we make it so it'll be printed
        // with colored bold text.
        if (TileData[x][y] != 0) {
          wattron(Tiles[x][y], A_BOLD);
          wattron(Tiles[x][y], A_REVERSE);
        }

        // Otherwise, it'll be set back to normal.
        else {
          wattroff(Tiles[x][y], A_BOLD);
          wattroff(Tiles[x][y], A_REVERSE);
        }

        mvwprintw(Tiles[x][y], 4, 2, "  %d  ", TileData[x][y]);
        wrefresh(Tiles[x][y]);
      }
    }
    wrefresh(stdscr);

    // Second is to take the user input, and perform the corresponding shift.
    Selection = wgetch(stdscr);

    switch (Selection) {

    case KEY_UP:
      dtu(TileData);
      break;

    case KEY_DOWN:
      utd(TileData);
      break;

    case KEY_LEFT:
      rtl(TileData);
      break;

    case KEY_RIGHT:
      ltr(TileData);
      break;

    default:
      break;
    }
  }

  refresh();

  return;
}
