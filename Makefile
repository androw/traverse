CFLAGS=-lSDLmain -lSDL -lSDL_ttf -lSDL_image -Wall 
EXEC=traveisti

all: main.c map.o pion.o dep.o arb.o ai.o
	gcc $(CFLAGS) main.c map.o pion.o dep.o arb.o ai.o -o $(EXEC)
map.o: map.c map.h pion.o dep.o arb.o ai.o
	gcc $(CFLAGS) -c map.c
pion.o: pion.c pion.h
	gcc $(CFLAGS) -c pion.c
dep.o: dep.c dep.h
	gcc $(CFLAGS) -c dep.c
ai.o: ai.h ai.c dep.o
	gcc $(CFLAGS) -c ai.c
arb.o: dalle.h arb.h arb.c
	gcc $(CFLAGS) -c arb.c
clean:
	rm -R *.o
mproper: clean
	rm $(EXEC)
