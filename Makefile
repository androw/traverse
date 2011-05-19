all: main.c map.o pion.o dep.o
	gcc -Wall main.c map.o pion.o dep.o -o main
map.o: map.c map.h pion.o
	gcc -Wall -c map.c
pion.o: pion.c pion.h
	gcc -Wall -c pion.c
dep.o: map.o dep.c dep.h
	gcc -Wall -c dep.c
clean:
	rm -R *.o main
