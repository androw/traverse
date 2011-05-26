#ifndef MAP_H
#define MAP_H

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include "pion.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "dep.h"
#include "dalle.h"
#include "arb.h"
#include "ai.h"
#include<time.h>

void createGrid(dalle grid[10][10],int joueur);
void fillGrid(dalle grid[10][10], int player);
void afficher(dalle g[10][10],SDL_Surface* ecran);
void SDL1(dalle grid[10][10]);
void SDL2(dalle grid[10][10]);
void turn(int tourj,SDL_Surface* ecran);
void copy(dalle grid[10][10], dalle r[10][10]);
void fillGridHM(dalle grille[10][10],int player);
void afficheConsole(dalle g[10][10]);
#endif
