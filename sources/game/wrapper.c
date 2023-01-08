#include "game.h"
#include <stdio.h>

void GameWrapper(int *Options) {

  // Parse the passed options:
  // In the case that the "-s" parameter has been passed, "Simple" mode is used.
  if (Options[0] == 1) {
    Simple2048();
    return;
  } else
    NCursesInit();

  return;
}
