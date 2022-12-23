# n2048
NCurses Port of 2048

Version Alpha 2.0.0 (December 23rd, 2022)

# Description
	n2048 is a NCurses-based port of the game 2048 - where the point is to merge tiles together with a numeric multiple of two in order to eventually get to 2048.

# Compiling
  To compile, simply run the command ``make`` in the source directory.

# Changelog
	
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
