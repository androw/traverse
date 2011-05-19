#include "ai.h"

//http://www.pressibus.org/ataxx/autre/minimax/node2.html


void minimax(dalle grid[10][10], int d, int maxd, int* chosen_score, int[4] chosen_move) {
	int best_score;
	int[4] best_move;
	if (d == maxd) {
		chosen_score =  evaluation(grid);
	} else {
		list* movesl = liste des coups possible;
		if (movesl == NULL) {
			chosen_score = evaluation(grid);
		} else {
			while (movesl == NULL) {
				best_score = 999;
				ngrid copy de grid;
				deplacement(ngrid, movesl->m[0], movesl->m[1], movesl->m[2], movesl->m[3]);
				int* the_score;
				int[4] the_move;
				minimax(ngrid, d+1, maxd, the_score, the_move);
				if (best_score < best_score) {
					best_score = the_score;
					best_move = the_move;
				}
				movesl = movesl->next;
			}
			chosen_score = best_score;
			chosen_move = best_move;
		}
	}
}
