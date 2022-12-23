#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game/game.h"

int main(int argc, char** argv){

  // Option-transport array:
  int Options[1];
  Options[0] = 1; // Used to enable "Simple" mode. See below.
  
  // Parsing arguments
  for(int Argument = 1; Argument < argc; Argument++){

    // --help - Prints a message instructing the user about various arguments that can be passed.
    if(strcmp(argv[Argument], "--help") == 0){
      printf("\n\nRunning n2048:");
      printf("\n./n2048 <arguments>");
      printf("\n\nList of arguments:");
      printf("\n--help - Prints this screen.");
      printf("\n-s - 'Simple'. Forgeos nCurses and is entirely terminal. Primarily for debugging purposes.");
      printf("\n");
      return 0;
    }    

    if(strcmp(argv[Argument], "-s") == 0)
      Options[0] = 1;     

  }

  GameWrapper(Options);
  return 0;
}
