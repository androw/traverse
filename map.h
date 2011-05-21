#ifndef MAP_H
#define MAP_H

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include "pion.h"
#include <SDL/SDL_ttf.h>

typedef struct {
	pion* pion;
	int border;
	int color;
	int djoueur;
	int ajoueur;
	int joueur;
	int pass;
} dalle;


void createGrid(dalle grid[10][10]);
void fillGrid(dalle grid[10][10], int player);
void afficher(dalle g[10][10],SDL_Surface* ecran);
void SDL1(dalle grid[10][10]);
void turn(int* tourj,SDL_Surface* ecran);
void copy(dalle grid[10][10], dalle r[10][10]);
#endif
