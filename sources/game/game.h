#ifndef __GAME_H
#define __GAME_H

void GameWrapper(int* Options);
void Simple2048();

void NCursesInit();
void MainMenu(int Ymax, int Xmax);
void NCursesGame(int Ymax, int Xmax);
#endif
