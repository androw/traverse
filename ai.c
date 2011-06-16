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
		for (j = 1; j<9; j++) {
			acc = acc - (distance(grid, i, j));
				if (grid[i][j].joueur == 2) {
					acc = acc - (nbrcasevidearriver(grid,2));
					if(victoire(grid)) {
						acc = acc + 3;
					}
				if ((grid[i][j].pion->type == CERCLE) && (i == 9 && (j == 1 || j == 8))) {
						acc = acc + 15;
					}

				if ((grid[i][j].pion->type == LOSANGE) && (i == 9)) {
						acc = acc + 35;
					}
				if ((grid[i][j].pion->type == LOSANGE) && (i == 8) && (grid[9][j-1].joueur == 2 || grid[9][j+1].joueur == 2)) {
						acc = acc - 30;
					}
				if ((grid[i][j].pion->type == TRIANGLE) && (i == 8) && (grid[9][j-1].joueur == 2 || grid[9][j+1].joueur == 2)) {
						acc = acc - 1000;
					}
				if ((grid[i][j].pion->type == TRIANGLE) && (i == 9) && (j != 1) && (j != 9) && (((grid[8][j-1].joueur == 2) || (grid[8][j+1].joueur == 2)) || ((grid[8][j-1].joueur == 2) || (grid[8][j+1].joueur == 2)))) {
						acc = acc - 30;
					}
				if ((grid[i][j].pion->type == LOSANGE) && (i == 9) && (j != 1) && (j != 9) && (((grid[8][j-1].joueur == 2) || (grid[8][j+1].joueur == 1)) || ((grid[8][j-1].joueur == 2) || (grid[8][j+1].joueur == 2)))) {
						acc = acc - 30;
					}
				if ((grid[i][j].pion->type == TRIANGLE) && (i == 9)) {
						acc = acc + 30;
					}
					if ((i == 9) && (j < 5)) {
						acc = acc + 100;
					} 
					if (i == 9) {
						acc = acc + 90;
					}
					if (i == 0) {
						acc = acc - 100;
					}
					if (i == 1) {
						acc = acc + 10;
					}
					if (i == 2) {
						acc = acc + 20;
					}
					if (i == 3) {
						acc = acc + 30;
					}
					if (i == 4) {
						acc = acc + 40;
					}
					if (i == 5) {
						acc = acc + 50;
					}
					if (i == 6) {
						acc = acc + 60;
					}
					if (i == 7) {
						acc = acc + 70;
					}
					if (i == 8) {
						acc = acc + 80;
					}
					if (j > 5  && i<7) {
                                                acc = acc + 10;
                                	}
					if((j == 1 || j == 8) && (grid[i][j].pion->type == TRIANGLE || grid[i][j].pion->type == LOSANGE) && (i == 8)) {
						acc = acc - 20;
					}
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
				for (ii = i-2; ii < 10; ii++) {
					for (jj = 1; jj < 9; jj++) {
						if (verif(grid, i, j, ii, jj)) {
						tab[2] = ii;
						tab[3] = jj;
						list = add(list, tab);
						}
					}
				}
			} else if (grid[i][j].joueur == player && grid[i][j].joueur == 1){
				for (ii = 0; ii < i+2; ii++) {
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

int nbrcasevidearriver(dalle grid[10][10], int joueur) {
int j;
int acc = 0;
if (joueur == 1){	
		for (j = 1; j<9; j++) {
			if (grid[0][j].joueur == 0) {
				acc++;
			}
		}
	
}

if (joueur == 2){	
		for (j = 1; j<9; j++) {
			if (grid[9][j].joueur == 0) {
				acc++;
			}
		}
}
return acc;
} 

int distance (dalle grille[10][10], int x,int y) { // x les lignes et y les colonnes
	int acc=0;
	int i;
	if (grille[0][2].ajoueur == grille[x][y].joueur) { //si jamais le pion veut arriver en haut
		acc = x; //distance entre la ligne x du pion et la ligne 0 d'arrivee
		for (i = 1;i < 9;i++) {
			if (grille[0][i].joueur == 0) {
				return (acc + abs( y - i)); //distance gauche-droite et inversement
			}
		}
	} else {//versl e bas
		acc = 9 - x; //distance entre la dernierel igne et la ligne du pion
		for (i = 1;i < 9;i++) {
			if (grille[9][i].joueur == 0) {
				return (acc + abs( y - i));
			}
		}
	}
return -1; //si jamais il n'y a pas de case libre
}	
	
int minmax(dalle grid[10][10], int d, int alpha, int beta, int evalMax) {
	if (d == 0 || victoire(grid) || defaite(grid)) {
		return evaluation(grid);
	}else {
		Move* moves = NULL;
		
		if (evalMax) {
			alpha = -99999;
			moves = coupPos(grid, 2);
		} else {
			beta = +99999;
			moves = coupPos(grid, 1);
		}
		while (moves != NULL) {
			dalle ngrid[10][10];
            copy(grid, ngrid);
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

evalCoup* jouer(dalle g[10][10], int pro) {
		Move* moves = NULL;
		evalCoup* coups = NULL;
		moves = coupPos(g, 2);
		while (moves != NULL) {
			dalle ngrid[10][10];
            copy(g, ngrid);
            deplacement(ngrid, moves->mov[0], moves->mov[1], moves->mov[2], moves->mov[3]);
			coups = addC(coups, moves->mov, minmax (ngrid, pro, -99999, 99999, 0));
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
		
