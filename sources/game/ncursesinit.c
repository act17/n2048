#include "game.h"
#include "shifts.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void NCursesInit() {

  // Initializing NCurses
  initscr();
  start_color();
  cbreak();
  noecho();

  // Getting the Screen Size, and stopping program if the
  // game is too small.
  int Ymax, Xmax;
  getmaxyx(stdscr, Ymax, Xmax);

  if (Ymax < 36 || Xmax < 72) {
    echo();
    endwin();

    printf("\nError! Error!\nScreen is too small!");
    printf("\n\nYour screen size: %dx%d", Ymax, Xmax);
    printf("\nRequired size: 36x72");
    return;
  }

  // Launching the game
  MainMenu(Ymax, Xmax);
  NCursesGame(Ymax, Xmax);

  // Closing up NCurses
  echo();
  endwin();

  return;
}
