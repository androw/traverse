CFLAGS=-lSDLmain -lSDL -Wall -lSDL_ttf
EXEC=main

all: main.c map.o pion.o dep.o
	gcc $(CFLAGS) main.c map.o pion.o dep.o -o $(EXEC)
map.o: map.c map.h pion.o
	gcc $(CFLAGS) -c map.c
pion.o: pion.c pion.h
	gcc $(CFLAGS) -c pion.c
dep.o: map.o dep.c dep.h
	gcc $(CFLAGS) -c dep.c
clean:
	rm -R *.o

mproper: clean
	rm $(EXEC)
