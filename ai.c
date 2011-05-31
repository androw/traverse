#include "ai.h"

Move* add(Move* list, int move[4]) {
	Move* n = (Move*) malloc(sizeof(Move));
	n->next = NULL;
	n->mov[0] = move[0];
	n->mov[1] = move[1];
	n->mov[2] = move[2];
	n->mov[3] = move[3];
	if (list == NULL) {
		return n;
	} else {
		n->next = list;
		return n;
	}
}

int evaluation(dalle grid[10][10]) {
	int acc = 0;
	int i;
	int j;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			if (grid[i][j].joueur == 2) {
				acc = acc + i;
			}
			else if (grid[i][j].joueur == 1) {
				acc = acc - 10 + i;
			}
		}
	} 
	return acc;
}

Move* coupPos(dalle grid[10][10], int player) {
	int i;
	int j;
	int ii;
	int jj;
	Move* list = NULL;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			int tab[4];
			tab[0] = i;
			tab[1] = j;
			if (grid[i][j].joueur == player && grid[i][j].joueur == 2) {
				for (ii = i; ii < 10; ii++) {
					for (jj = 1; jj < 9; jj++) {
						if (verif(grid, i, j, ii, jj)) {
						tab[2] = ii;
						tab[3] = jj;
						list = add(list, tab);
						}
					}
				}
			} else if (grid[i][j].joueur == player && grid[i][j].joueur == 1){
				for (ii = 0; ii < i; ii++) {
                                        for (jj = 1; jj < 9; jj++) {
                                                if (verif(grid, i, j, ii, jj)) {
                                                tab[2] = ii;
                                                tab[3] = jj;
                                                list = add(list, tab);
                                                }
                                        }
                                }
			}
		}
	}
	return list;			
}
	
int minmax(dalle grid[10][10], int d, int alpha, int beta, int evalMax) {
	if (d == 0 || victoire(grid) || defaite(grid)) {
		return evaluation(grid);
	}else {
		Move* moves = NULL;
		
		if (evalMax) {
			alpha = -999;
			moves = coupPos(grid, 2);
		} else {
			beta = +999;
			moves = coupPos(grid, 1);
		}
		while (moves != NULL) {
			dalle ngrid[10][10];
            copy(grid, ngrid);
            //printf("%i %i %i %i\n" , moves->mov[0], moves->mov[1], moves->mov[2], moves->mov[3]);
            deplacement(ngrid, moves->mov[0], moves->mov[1], moves->mov[2], moves->mov[3]);
            if (evalMax) {
				alpha = max(alpha, minmax(ngrid, d-1, alpha, beta, 0));
				if (alpha >= beta) {
					return alpha;
				}
			} else {
				beta = min(beta, minmax(ngrid, d-1, alpha, beta, 1));
				if (alpha >= beta) {
					return beta;
				}
			}
			moves = moves->next;
		}
		if (evalMax) {
			return alpha;
		} else {
			return beta;
		}
	}
}

int min(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int max(int a, int b) {
    if (a > b) {
		return a;
	} else {
		return b;
	}
}

int victoire(dalle g[10][10]) {
	if ((g[9][1].joueur == 2) && (g[9][2].joueur == 2) && (g[9][3].joueur == 2) && (g[9][4].joueur == 2) && (g[9][5].joueur == 2) &&(g[9][6].joueur == 2) &&(g[9][7].joueur == 2) &&(g[9][8].joueur == 2)) {
		return 1;
	} else {
		return 0;
	}
}

int defaite(dalle g[10][10]) {
        if ((g[0][1].joueur == 1) &&(g[0][2].joueur == 1) &&(g[0][3].joueur == 1) &&(g[0][4].joueur == 1) &&(g[0][5].joueur == 1) &&(g[0][6].joueur == 1) &&(g[0][7].joueur == 1) &&(g[0][8].joueur == 1)) {
                return 1;
        } else {
                return 0;
	}
}

evalCoup* jouer(dalle g[10][10]) {
		Move* moves = NULL;
		evalCoup* coups = NULL;
		moves = coupPos(g, 2);
		while (moves != NULL) {
			dalle ngrid[10][10];
            copy(g, ngrid);
            deplacement(ngrid, moves->mov[0], moves->mov[1], moves->mov[2], moves->mov[3]);
			coups = addC(coups, moves->mov, minmax (ngrid, 2, -999, 999, 0));
			moves = moves->next;
			
		}
		return cMax(coups);
}

evalCoup* addC(evalCoup* coups, int coup[4], int a) {
	evalCoup* n = (evalCoup*) malloc(sizeof(evalCoup));
	n->move[0] = coup[0];
	n->move[1] = coup[1];
	n->move[2] = coup[2];
	n->move[3] = coup[3];
	n->valeur = a;
	n->next = NULL;
	if (coups == NULL) {
                return n;
    } else {
                n->next = coups;
                return n;
    }
}

evalCoup* cMax(evalCoup* coups) {
		evalCoup* max = coups;
		while (coups != NULL) {
			if (coups->valeur > max->valeur) {
					max = coups;
			}
			coups = coups->next;
		}
		return max;
}
		
