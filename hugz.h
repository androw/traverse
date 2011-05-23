#include<stdio.h>
#include<stdlib.h>
#include "map.h"

typedef struct Noeud {
	dalle grille[10][10];
	int acc;
	struct Noeud* suivant;
} Noeud;
