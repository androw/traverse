all: main.c map.o pion.o dep.o
	gcc -lSDLmain -lSDL -lSDL_ttf -Wall main.c map.o pion.o dep.o -o main
map.o: map.c map.h pion.o
	gcc -lSDLmain -lSDL -lSDL_ttf -Wall -c map.c
pion.o: pion.c pion.h
	gcc -lSDLmain -lSDL -lSDL_ttf -Wall -c pion.c
dep.o: map.o dep.c dep.h
	gcc -lSDLmain -lSDL -lSDL_ttf -Wall -c dep.c
clean:
	rm -R *.o main
