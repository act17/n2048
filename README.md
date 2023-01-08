# n2048
NCurses Port of 2048

Version Alpha 2.0.0 (December 23rd, 2022)

# Description
	n2048 is a NCurses-based port of the game 2048 - where the point is to merge tiles together with a numeric multiple of two in order to eventually get to 2048.

# Compiling
  To compile, simply run the command ``make`` in the source directory.

# Todo
  - Fix responsiveness issues with the shift functions.
  - Fix the warnings given by the compiler.
  - Add controls.
  - Add a system to detect if any moves can be made - and end the game if none can be made.

# Changelog
	
  *Beta 1.0.0 - January 8th, 2023*
  - Added three new files in the directory ``sources/game``; ``ncursesinit.c``, ``ncursesmenu.c``, and ``ncursesgame.c``:
    - ``ncursesinit.c`` - includes the function ``void NCursesInit()``. It acts as a wrapper to the NCurses version of the game, getting the screen size and returning an error in the case that the screen is too small.
    - ``ncursesmenu.c`` - includes the function ``void MainMenu(int Ymax, int Xmax)``. It simply prints the main menu for the game.
    - ``ncursesgame.c`` - inlcudes the function ``void NCursesGame(int Ymax, int Xmax)``. It acts as... the game.
  
  - Added the functions listed above to ``game.h``.

  - Changed the compiler flag in ``Makefile`` ``-Wpedantic`` to ``-Wall``.
  
  - Removed ``-Werror`` from ``Makefile``.

  - Changed ``sources/main.c`` to no longer use the "simple" version of the game by default - a flag must be passed to use it. 

  - Changed ``sources/game/wrapper.c`` to now permit the use of the proper NCurses version of the game.  


  *Alpha 2.0.0 - December 23rd, 2022*
  - Added ``Makefile`` to compile the program.

  - Moved ``rtl.c``, ``ltr.c``, ``utd.c``, and ``dtu.c`` to a new directory - ``sources/game/shifts``.
  
  - Added ``game.h`` which includes two new functions:
    - ``void GameWrapper(int* Options)``, a wrapper that acts as a macro to begin the game.
    - ``void Simple2048()``, a debugging-centered entirely CLI 2048.

  - Added ``wrapper.c``, which includes the function ``void GameWrapper(int* Options)``.

  - Added ``simple.c``, which includes the function ``void Simple2048()``.

  - Added ``main.c`` in the directory ``sources/``, which acts as a wrapper for the whole program.


	*Alpha 1.0* - December 5th, 2022
	- Added ``rtl.c``, ``ltr.c``, ``utd.c``, ``dtu.c``, and ``shifts.h`` in the ``sources/shifts/`` directory. These four files - and their corresponding header file - handle the shifting of the tiles.
