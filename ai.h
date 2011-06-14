#ifndef AI_H
#define AI_H

#include "dep.h"
#include "dalle.h"

typedef struct Move {
	int mov[4];
	struct Move* next;
} Move;

typedef struct evalCoup {
	int move[4];
	int valeur;
	struct evalCoup* next;
} evalCoup;


int evaluation(dalle grid[10][10]);
Move* add(Move* list, int move[4]);
Move* coupPos(dalle grid[10][10], int player);
int minmax(dalle grid[10][10], int d, int alpha, int beta, int evalMax);
int max(int a, int b);
int min(int a, int b);
int defaite(dalle g[10][10]);
int victoire(dalle g[10][10]);
evalCoup* jouer(dalle g[10][10]);
evalCoup* addC(evalCoup* coups, int coup[4], int a);
evalCoup* cMax(evalCoup* coups);
#endif
