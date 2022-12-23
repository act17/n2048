n2048: sources/main.c sources/game/wrapper.c sources/game/simple.c sources/game/shifts/ltr.c sources/game/shifts/rtl.c sources/game/shifts/dtu.c sources/game/shifts/utd.c
	gcc -o $@ $^ -Werror -Wpedantic -g
clean:
	rm n2048
