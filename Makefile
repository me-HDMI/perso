test:scrolling.o func.o
	gcc scrolling.o func.o   -o test -lSDL -lSDL_image -lSDL_mixer -g
main.o:scrolling.c
	gcc -c scrolling.c -lSDL -lSDL_image -lSDL_mixer -g
fonction.o:func.c
	gcc -c func.c -lSDL -lSDL_image -lSDL_mixer -g
