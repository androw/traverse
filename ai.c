#include "ai.h"

void bestmove(dalle grid[10][10], int move[4]) {
	int * score;
	minimax(grid, 0, 4, score, move, 1);
}

void minimax(dalle grid[10][10], int d, int maxd, int* chosen_score, int chosen_move[4], int min) {
	int best_score;
	int best_move[4];
	if (d == maxd) {
		*chosen_score =  evaluation(grid);
	} else {
		Move* movesl = NULL;
		if (min) {
		coupPos(grid, movesl, 2);
		} else {
		coupPos(grid, movesl, 1);
		}
		printf("TESSSST\n");
		if (movesl == NULL) {
			*chosen_score = evaluation(grid);
		} else {
			while (movesl == NULL) {
				best_score = 50;
				dalle ngrid[10][10];
				copy(ngrid, grid);
				printf("%i %i %i %i\n",  movesl->mov[0], movesl->mov[1], movesl->mov[2], movesl->mov[3]);
				deplacement(ngrid, movesl->mov[0], movesl->mov[1], movesl->mov[2], movesl->mov[3]);
				int* the_score;
				int the_move[4];
				
				minimax(ngrid, d+1, maxd, the_score, the_move, !min);
				if (*the_score <= best_score  && min) {
					best_score = *the_score;
					best_move[0] = the_move[0];
					best_move[1] = the_move[1];
					best_move[2] = the_move[2];
					best_move[3] = the_move[3];
				} else if (*the_score >= best_score  && !min) { 
					best_score = *the_score;
				}
				movesl = movesl->next;
			}
			*chosen_score = best_score;
			chosen_move[0] = best_move[0];
			chosen_move[1] = best_move[1];
			chosen_move[2] = best_move[2];
			chosen_move[3] = best_move[3];
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

void coupPos(dalle grid[10][10], Move* list, int player) {
	int i;
	int j;
	int ii;
	int jj;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			int tab[4];
			tab[0] = i;
			tab[1] = j;
			if (grid[i][j].joueur == player) {
				printf("TESSSSSST\n");
				for (ii = 0; ii < i+5 && ii < 10; ii++) {
					for (jj = 0; jj < j+5 && jj < 10; jj++) {
						if (verif(grid, i, j, ii, jj)) {
						tab[2] = ii;
						tab[3] = jj;
						add(list, tab);
						}
					}
				}
			}
		}
	}			
}
	
