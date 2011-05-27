#ifndef ARB_H
#define ARB_H

#include<stdio.h>
#include<stdlib.h>
#include "dalle.h"

typedef struct Noeud {
	dalle grille[10][10];
	int acc;
	struct Noeud* suivant;
} Noeud;

int pathTest (Noeud* teteliste, dalle grid[10][10]);
int condWin(dalle grid[10][10],int player);
int condWinHM(dalle grid[10][10],int player);
int antiJeuTest(dalle grid[10][10],int tour);
#endif
