#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

// The Version && Release Date
char Version[10] = "Beta 1.0.0";
char ReleaseDate[10] = "2023-01-08";

void MainMenu(int Ymax, int Xmax) {

  // Defining the relative starts (Equal to the height/width, divided by two.)
  int RelativeYStart = (Ymax - 32) / 2;
  int RelativeXStart = (Xmax - 72) / 2;

  // Creating the color pairs
  init_pair(1, COLOR_BLACK, COLOR_WHITE); // Text box & panel color.
  init_pair(2, COLOR_CYAN, COLOR_CYAN);   // Background color.

  // Creating the window
  WINDOW *mainwindow = newwin(32, 72, RelativeYStart, RelativeXStart);

  // Setting visual settings and information
  wbkgd(mainwindow, COLOR_PAIR(1));
  wbkgd(stdscr, COLOR_PAIR(2));

  wattron(mainwindow, COLOR_PAIR(1));
  box(mainwindow, 0, 0);

  // Printing messages
  mvwprintw(mainwindow, 1, 30, "ACT's N2048");
  mvwprintw(mainwindow, 2, 31, "%s", Version);
  mvwprintw(mainwindow, 3, 31, "%s", ReleaseDate);

  mvwprintw(mainwindow, 5, 21, "Released under the GNU GPL 3.0");
  mvwprintw(mainwindow, 6, 27, "Copyright 2023 ACT");

  wattron(mainwindow, A_REVERSE);
  wattron(mainwindow, A_BOLD);
  mvwprintw(mainwindow, 8, 25, "PRESS ANY KEY TO START");

  // Refresh
  wrefresh(stdscr);
  wrefresh(mainwindow);
  refresh();

  getch();

  return;
}
