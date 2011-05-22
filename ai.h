#ifndef AI_H
#define AI_H

#include "dep.h"

typedef struct Move {
	int mov[4];
	struct Move* next;
} Move;


int evaluation(dalle grid[10][10]);
void add(Move* list, int move[4]);
void minimax(dalle grid[10][10], int d, int maxd, int* chosen_score, int chosen_move[4]);
#endif
