#ifndef DALLE_H
#define DALLE_H

#include "pion.h"

typedef struct dalle{
	struct pion* pion;
	int mur;
	int border;
	int color;
	int djoueur;
	int ajoueur;
	int joueur;
	int pass;
}dalle;

#endif
