#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shifts.h"

void Simple2048(){

  // First we create our array that's used to store tile data:
  int Array[4][4] = {
    (0,0,0,0),
    (0,0,0,0),
    (0,0,0,0),
    (0,0,0,0)
  };

  // Next up is the operator used to store the user's input.
  char UserInput;

  // This integer will be used to prevent nonvalid input.
  int NonvalidInputCheck = 0;

  // These two numbers will be used for the sake of finding an empty tile, see below:
  int RandomX = rand() % 4;
  int RandomY = rand() % 4;

  // This is the loop for the game. As of the current version, it doesn't have a "fail condition".
  while(1){

    printf("\n");  

    // First thing in the loop is to find an empty tile.
    // New numbers will be generated until there's an empty tile.
    while(Array[RandomX][RandomY] != 0){
      srand(time(0));
      RandomX = rand() % 4;
      srand(time(0));
      RandomY = rand() % 4;
  
    }
    
    Array[RandomX][RandomY] = 2;

    // This will print the current array.
    // This first for() loop prints the y-axis.
    for(int y = 0; y < 4; y++){
      printf("\n");

      // This second for() loop prints the x-axis.
      for(int x = 0; x < 4; x++)
        printf("%d  ",Array[y][x]);      


    } 

    // Then we take user input after providing useful instructions:
    printf("\nEnter your input:");
    printf("\n'u' for Up-to-Down, 'd' for Down-to-Up, 'l' for Left-to-Right, and 'r' for Right-to-Left\n");

    // Now to create a while loop that is broken if the user's input is valid.
    while (1) {

      // We take the users input,      
      scanf("%c",&UserInput);

      // And run it through a switch to see what to do.
      switch(UserInput){
        
        case 'u':
          dtu(Array);
          NonvalidInputCheck = 0;
          break;

        case 'd':
          utd(Array);
          NonvalidInputCheck = 0;
          break;

        case 'l':
          ltr(Array);
          NonvalidInputCheck = 0;
          break;

        case 'r':
          rtl(Array);
          NonvalidInputCheck = 0;
          break;

        // In the case that the input is invalid, we repeat the process.
        default:
          NonvalidInputCheck = 1;
          break;
      }
      
      if(NonvalidInputCheck == 0)
        break;

    }
  }
  return;
}
