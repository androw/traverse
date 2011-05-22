#include "ai.h"

//http://www.pressibus.org/ataxx/autre/minimax/node2.html


void minimax(dalle grid[10][10], int d, int maxd, int* chosen_score, int chosen_move[4]) {
	int best_score;
	int best_move[4];
	if (d == maxd) {
		chosen_score =  evaluation(grid);
	} else {
		Move* movesl = listedescoupspossible;
		if (movesl == NULL) {
			*chosen_score = evaluation(grid);
		} else {
			while (movesl == NULL) {
				best_score = 999;
				dalle ngrid[10][10];
				copy(ngrid, grid);
				deplacement(ngrid, movesl->mov[0], movesl->mov[1], movesl->mov[2], movesl->mov[3]);
				int* the_score;
				int the_move[4];
				minimax(ngrid, d+1, maxd, the_score, the_move);
				if (*the_score < best_score) {
					best_score = *the_score;
					best_move[0] = the_move[0];
					best_move[1] = the_move[1];
					best_move[2] = the_move[2];
					best_move[3] = the_move[3];
				}
				movesl = movesl->next;
			}
			*chosen_score = best_score;
			chosen_move = best_move;
		}
	}
}

void add(Move* list, int move[4]) {
	Move* n = (Move*) malloc(sizeof(Move));
	n->next = NULL;
	n->mov[0] = move[0];
	n->mov[1] = move[1];
	n->mov[2] = move[2];
	n->mov[3] = move[3];
	if (list == NULL) {
		list = n;
	} else {
		n->next = list;
		list = n;
	}
}

int evaluation(dalle grid[10][10]) {
	int acc = 0;
	int i;
	int j;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			if (grid[i][j].joueur == 2) {
				acc = acc + 10 - i;
			}
		}
	} 
	return acc;
}
