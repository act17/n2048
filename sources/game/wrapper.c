#include <stdio.h>
#include "game.h"

void GameWrapper(int* Options){

  // Parse the passed options:
  // In the case that the "-s" parameter has been passed, "Simple" mode is used.
  if(Options[0] == 1){
    Simple2048();
    return;
  }    

  return;
}
