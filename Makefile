all: main.c map.o pion.o
	gcc -Wall main.c map.o pion.o -o main
map.o: map.c map.h pion.o
	gcc -Wall -c map.c
pion.o: pion.c pion.h
	gcc -Wall -c pion.c
