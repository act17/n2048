#include <stdio.h>
#include <stdlib.h>

void dtu(int array[4][4]){

	for(int x = 0; x < 4; x++){
	
		for(int y = 3; y > 0; y--){
		
			if(array[y - 1][x] == array[y][x]){
				array[y - 1][x] = array[y][x] * 2;
				array[y][x] = 0;
			}

			if(array[y - 1][x] == 0){
				array[y - 1][x] = array[y][x];
				array[y][x] = 0;
			}
		}
	}

	return;
}
