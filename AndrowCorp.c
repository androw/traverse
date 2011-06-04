#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct evalCoup {
        int move[4];
        int valeur;
        struct evalCoup* next;
}evalCoup;

typedef struct dalle{
        struct pion* pion;
        int border;
        int djoueur;
        int ajoueur;
        int joueur;
        int pass;
}dalle;

enum PION {
        CARRE,
        TRIANGLE,
        LOSANGE,
        CERCLE
};

typedef struct pion{
        enum PION type;
        int left;
        int right;
        int up;
        int down;
        int diagupleft;
        int diagdownleft;
        int diagupright;
        int diagdownright;
}pion;

void afficheConsole(dalle g[10][10]);
void name(char answer[100]);
void ply(char board[100], int color, int time, char answer[4]);
void adapt(char board[100], dalle grid[10][10]);
int evaluation(dalle grid[10][10], int color);
evalCoup* cMax(evalCoup* coups);
evalCoup* addC(evalCoup* coups, int coup[4], int a);
evalCoup* jouer(dalle g[10][10], int color);
void copy(dalle grid[10][10], dalle r[10][10]);
void deplacement (dalle grid[10][10], int x, int y, int xx, int yy);
int abs(int x);
int distance (dalle grille[10][10], int x,int y);

void name(char answer[100])
{
  strcpy(answer,"AndrowCorp");
}
 
void ply(char board[100], int color, int time, char answer[4])
{
	dalle grid[10][10];
	adapt(board, grid);
	evalCoup* coup = NULL;
	if (color == 1) {
	coup = jouer(grid, 1);
	} else {
	coup = jouer(grid, 2);
        }
	
	//printf("%i %i %i %i\n", coup->move[0], coup->move[1], coup->move[2], coup->move[3]);
	

  	answer[0] = coup->move[1]+97;
  	answer[1] = coup->move[0]+48;
  	answer[2] = coup->move[3]+97;
  	answer[3] = coup->move[2]+48;
}

int abs(int x) {
	if (x > 0) {
		return x;
	}
	else {
		return -x;
	}
return x;
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
			 


void adapt(char board[100], dalle grid[10][10]) {
	pion* carre=(pion*)malloc(sizeof(pion));
        carre->up=1;
        carre->down=1;
        carre->left=1;
        carre->right=1;
        carre->diagupleft=0;
        carre->diagupright=0;
        carre->diagdownleft=0;
        carre->diagdownright=0;
        carre->type=CARRE;
	pion* losange=(pion*)malloc(sizeof(pion));
        losange->up=0;
        losange->down=0;
        losange->left=0;
        losange->right=0;
        losange->diagupleft=1;
        losange->diagupright=1;
        losange->diagdownleft=1;
        losange->diagdownright=1;
        losange->type=LOSANGE;
	pion* cercle=(pion*)malloc(sizeof(pion));
        cercle->up=1;
        cercle->down=1;
        cercle->left=1;
        cercle->right=1;
        cercle->diagupleft=1;
        cercle->diagupright=1;
        cercle->diagdownleft=1;
        cercle->diagdownright=1;
        cercle->type=CERCLE;
	pion* triangle1=(pion*)malloc(sizeof(pion));
        pion* triangle2=(pion*)malloc(sizeof(pion));	
	triangle1->up=0;
        triangle1->down=1;
        triangle1->left=0;
        triangle1->right=0;
        triangle1->diagupleft=1;
        triangle1->diagupright=1;
        triangle1->diagdownleft=0;
        triangle1->diagdownright=0;
        triangle1->type=TRIANGLE;
        triangle2->up=1;
        triangle2->down=0;
        triangle2->left=0;
        triangle2->right=0;
        triangle2->diagupleft=0;
        triangle2->diagupright=0;
        triangle2->diagdownleft=1;
        triangle2->diagdownright=1;
        triangle2->type=TRIANGLE;
	int i;
	int j;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			grid[i][j].pass = 0;
			if (i == 0 && j > 0 && j < 9) {
				grid[i][j].djoueur = 1;
				grid[i][j].ajoueur = 2;
			} else if (i == 9 && j > 0 && j < 9) {
				grid[i][j].djoueur = 2;
                                grid[i][j].ajoueur = 1; 
			} else {
				grid[i][j].djoueur = 0;
                                grid[i][j].ajoueur = 0;
			}
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				grid[i][j].border = 1;
			} else {
				grid[i][j].border = 0;
			}
			if (board[j+10*i] == 'S' || board[j+10*i] == 's') {
				grid[i][j].pion = carre;
			} else if (board[j+10*i] == 'C' || board[j+10*i] == 'c') {
				grid[i][j].pion = cercle;
			} else if (board[j+10*i] == 'D' || board[j+10*i] == 'd') {
				grid[i][j].pion = losange;
			} else if (board[j+10*i] == 'T') {
				grid[i][j].pion = triangle2;
			} else if (board[j+10*i] == 't') {
                                grid[i][j].pion = triangle1;
                        } else {
				grid[i][j].pion = NULL;
			}
			if (board[j+10*i] >= 97 && board[j+10*i] <= 122) {
				grid[i][j].joueur = 2;
			} else if (board[j+10*i] >= 65 && board[j+10*i] <= 90) {
                                grid[i][j].joueur = 1;
                        } else {
				grid[i][j].joueur = 0;
			}
		}
	}
}

int evaluation(dalle grid[10][10], int color) {
	int acc = 0;
	int i;
	int j;
	if (color == 1) {
		for (i = 0; i<10; i++) {
			for (j=0; j<10; j++) {
				if (grid[i][j].joueur == 1) {
					acc = acc + distance(grid, i, j);;
					if (i == 0){
					acc = acc - 10;
					}
					if (i == 9) {
					acc = acc + 20;
					}
					if (j < 7 && j >= 3 && i < 5) {
					acc++;
					} 
				} else if (grid[i][j].joueur == 2) {
					acc = acc - distance(grid, i, j);
				}
			}
		}
	} else  if (color == 2) {
                for (i = 0; i<10; i++) {
                        for (j=0; j<10; j++) {
                                if (grid[i][j].joueur == 2) {
                                        acc = acc + distance(grid, i, j);
                                        if (i == 9){
                                        acc = acc - 10;
                                        }
                                        if (i == 0) {
                                        acc = acc + 20;
                                        }
					if (j < 7 && j >= 3 && i >= 5) {
                                        acc++;
                                        }
                                } else if (grid[i][j].joueur == 1) {
                                        acc = acc - distance(grid, i, j);
                                }
                        }
                }
        }
	return acc;
}

evalCoup* coupPos(dalle grid[10][10], int player) {
	int i;
	int j;
	int ii;
	int jj;
	evalCoup* list = NULL;
	
	if (player == 2) {
		for (i = 9; i>=0; i--) {
			for (j = 0; j<10; j++) {
				int tab[4];
                        	tab[0] = i;
                        	tab[1] = j; 
				if (grid[i][j].joueur == player) {
					for (ii = i+1; ii >= 0; ii--) {
						for (jj = 0; jj < 10; jj++) {
							if (verif(grid, i, j, ii, jj)) {
                                                		tab[2] = ii;
                                                		tab[3] = jj;
                                                		list = addC(list, tab, -1);
                                                	}
						}
					}
				}
			}
		}
	} else {
		for (i = 0; i<10; i++) {
                        for (j = 0; j<10; j++) {
                                int tab[4];
                                tab[0] = i;
                                tab[1] = j;
                                if (grid[i][j].joueur == player) {
                                        for (ii = i-1; ii <10; ii++) {
                                                for (jj = 0; jj < 10; jj++) {
                                                        if (verif(grid, i, j, ii, jj)) {
                                                                tab[2] = ii;
                                                                tab[3] = jj;
                                                                list = addC(list, tab, -1);
                                                        }
                                                }
                                        }
                                }
                	}
		}
	}
	return list;			
}
	
int minmax(dalle grid[10][10], int d, int alpha, int beta, int evalMax, int color) {
	if (d == 0 || victoire(grid) || defaite(grid)) {
		return evaluation(grid, color);
	}else {
		evalCoup* moves = NULL;
		
		if (evalMax) {
			alpha = -999;
			moves = coupPos(grid, color);
		} else {
			beta = +999;
			if (color == 2) {
			moves = coupPos(grid, 1);
			} else {
			 moves = coupPos(grid, 2);
			}
		}
		while (moves != NULL) {
			dalle ngrid[10][10];
	            copy(grid, ngrid);
        	    deplacement(ngrid, moves->move[0], moves->move[1], moves->move[2], moves->move[3]);
            if (evalMax) {
				alpha = max(alpha, minmax(ngrid, d-1, alpha, beta, 0, color));
				if (alpha >= beta) {
					return alpha;
				}
			} else {
				beta = min(beta, minmax(ngrid, d-1, alpha, beta, 1, color));
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

evalCoup* jouer(dalle g[10][10], int color) {
		evalCoup* moves = NULL;
		evalCoup* coups = NULL;
		moves = coupPos(g, color);
		while (moves != NULL) {
			dalle ngrid[10][10];
            		copy(g, ngrid);
            		deplacement(ngrid, moves->move[0], moves->move[1], moves->move[2], moves->move[3]);
			coups = addC(coups, moves->move, minmax (ngrid, 2, -999, 999, 0, color));
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
		
void copy(dalle grid[10][10], dalle r[10][10]) {
        int i;
        int j;
        for (i = 0; i<10; i++) {
                for (j = 0; j<10; j++) {
                        r[i][j].joueur = grid[i][j].joueur;
                        r[i][j].border = grid[i][j].border;
                        r[i][j].pion = grid[i][j].pion;
                        r[i][j].ajoueur = grid[i][j].ajoueur;
                        r[i][j].pass = grid[i][j].pass;
                }
        }
}

void reset(dalle grid[10][10]) {
        int i;
        int j;
        for (i = 0; i<10; i++) {
                for (j = 0; j<10; j++) {
                        grid[i][j].pass = 0;
                }
        }
}

int verif(dalle grid[10][10], int x, int y, int xx, int yy){
    if ((x == xx) && (y == yy)) {
        return 0;
    }
    else if (grid[x][y].joueur == 0) {
        return 0;
    }
        else if  ((depV(grid,x,y,1) && xx==x+1 && yy==y-1) ||
                (depV(grid,x,y,2) && xx==x+1 && yy==y) ||
                (depV(grid,x,y,3) && xx==x+1 && yy==y+1) ||
                (depV(grid,x,y,4) && xx==x && yy==y-1) ||
                (depV(grid,x,y,6) && xx==x && yy==y+1) ||
                (depV(grid,x,y,7) && xx==x-1 && yy==y-1) ||
                (depV(grid,x,y,8) && xx==x-1 && yy==y) ||
                (depV(grid,x,y,9) && xx==x-1 && yy==y+1)) {
                return 1;
        }else if (sautValide(grid,x,y,x,y,xx,yy)) {
                reset(grid);
                return 1;
        }else {
                reset(grid);
                return 0;
        }
}

int mvt(dalle grid[10][10], int x, int y, int xx, int yy){
        if (verif(grid, x, y, xx, yy)) {
                deplacement (grid, x, y, xx, yy);
                return 1;
        } else {
                return 0;
        }
}

void deplacement (dalle grid[10][10], int x, int y, int xx, int yy) {
        grid[xx][yy].pion = grid[x][y].pion;
        grid[xx][yy].joueur = grid[x][y].joueur;
        grid[x][y].pion = NULL;
        grid[x][y].joueur = 0;
}

int depV(dalle grid[10][10], int x, int y, int i) {
        if (
                ((i == 1) && (grid[x+1][y-1].border == 1) && (grid[x][y].joueur != grid[x+1][y-1].ajoueur)) ||
                ((i == 2) && (grid[x+1][y].border == 1) && (grid[x][y].joueur != grid[x+1][y].ajoueur)) ||
                ((i == 3) && (grid[x+1][y+1].border == 1) && (grid[x][y].joueur != grid[x+1][y+1].ajoueur)) ||
                ((i == 4) && (grid[x][y-1].border == 1)&& (grid[x][y].joueur != grid[x][y-1].ajoueur)) ||
                ((i == 6) && (grid[x][y+1].border == 1)&& (grid[x][y].joueur != grid[x][y+1].ajoueur)) ||
                ((i == 7) && (grid[x-1][y-1].border == 1)&& (grid[x][y].joueur != grid[x-1][y-1].ajoueur)) ||
                ((i == 8) && (grid[x-1][y].border == 1) && (grid[x][y].joueur != grid[x-1][y].ajoueur)) ||
                ((i == 9) && (grid[x-1][y+1].border == 1)&& (grid[x][y].joueur != grid[x-1][y+1].ajoueur))) {
        return 0; //Bordure

        }else if  (    ((i == 1) && ((x == 9) || (y == 0))) ||
                       ((i == 2) && (x == 9)) ||
                       ((i == 3) && ((x == 9) || (y == 9))) ||
                       ((i == 4) && (y == 0)) ||
                       ((i == 6) && (y == 9)) ||
                       ((i == 7) && ((x == 0) || (y == 0))) ||
                       ((i == 8) && (x == 0)) ||
                       ((i == 9) && ((x == 0) || (y == 9))) ){
        return 0; //Sortie du plateau

        }else if (((i == 1) && (grid[x+1][y-1].joueur != 0)) ||
                 ((i == 2) && (grid[x+1][y].joueur != 0)) ||
                 ((i == 3) && (grid[x+1][y+1].joueur != 0)) ||
                 ((i == 4) && (grid[x][y-1].joueur != 0)) ||
                 ((i == 6) && (grid[x][y+1].joueur != 0)) ||
                 ((i == 7) && (grid[x-1][y-1].joueur != 0)) ||
                 ((i == 8) && (grid[x-1][y].joueur != 0)) ||
                 ((i == 9) && (grid[x-1][y+1].joueur != 0))) {
        return 0; //collision avec un autre pion
    }
         else{
                switch (i) {
                        case 1 : return (grid[x][y].pion->diagdownleft);
                        case 2 : return (grid[x][y].pion->down);
                        case 3 : return (grid[x][y].pion->diagdownright);
                        case 4 : return (grid[x][y].pion->left);
                        case 6 : return (grid[x][y].pion->right);
                        case 7 : return (grid[x][y].pion->diagupleft);
                        case 8 : return (grid[x][y].pion->up);
                        case 9 : return (grid[x][y].pion->diagupright);
                }
        }
    return 0;
}


int sautValide (dalle grid[10][10], int x, int y,int rx,int ry, int xx, int yy) {
        if ((grid[xx][yy].border == 1 && grid[xx][yy].ajoueur != grid[x][y].joueur) || grid[xx][yy].joueur != 0) {
                return 0;
        }
        else if (rx < 0 || rx >9 || ry >9 || ry < 0) {
                return 0;
        }
        else if (grid[rx][ry].joueur != 0 && rx != x && ry != y) {
                return 0;
        }
        else if (rx == xx && ry == yy) {
                return 1;
        }
        else if (grid[rx][ry].pass == 1) {
                return 0;
        }
        else {
                grid[rx][ry].pass = 1;
                dalle gridr[10][10];
                if (rx+2 <= 9 && rx+2 >= 0 && ry-2<= 9 && ry-2 >= 0 && (grid[x][y].pion->diagdownleft)) {
                        copy(grid, gridr);
                        if (grid[rx+1][ry-1].joueur != 0 && grid[rx+2][ry-2].joueur == 0){
                        if (sautValide(gridr, x, y, rx+2,ry-2,xx,yy)) {
                                grid[rx+2][ry-2].pass = 1;
                                return 1;
                        } else {
                                grid[rx+2][ry-2].pass = 1;
                        }
                        }
                }
                if (rx+2 <= 9 && rx+2 >= 0 && ry<= 9 && ry >= 0 && (grid[x][y].pion->down)) {
                        copy(grid, gridr);
                        if (grid[rx+1][ry].joueur != 0 && grid[rx+2][ry].joueur == 0) {
                        if (sautValide(gridr, x, y, rx+2,ry,xx,yy)) {
                                grid[rx+2][ry].pass = 1;
                                return 1;
                        } else {
                                grid[rx+2][ry].pass = 1;
                        }
                        }
                }
                if (rx+2 <= 9 && rx+2 >= 0 && ry+2<= 9 && ry+2 >= 0 && (grid[x][y].pion->diagdownright)) {
                        copy(grid, gridr);
                        if (grid[rx+1][ry+1].joueur != 0 && grid[rx+2][ry+2].joueur == 0) {
                        if (sautValide(gridr, x, y, rx+2,ry+2,xx,yy)) {
                                grid[rx+2][ry+2].pass = 1;
                                return 1;
                        } else {
                                grid[rx+2][ry+2].pass = 1;
                        }
                        }
                }
                if (rx<= 9 && rx >= 0 && ry-2<= 9 && ry-2 >= 0 && (grid[x][y].pion->left)) {
                        copy(grid, gridr);
                        if (grid[rx][ry-1].joueur != 0 && grid[rx][ry-2].joueur == 0) {
                        if (sautValide(gridr, x, y, rx,ry-2,xx,yy)) {
                                grid[rx][ry-2].pass = 1;
                                return 1;
                        } else {
                                grid[rx][ry-2].pass = 1;
                        }
                        }
                }
                if (rx<= 9 && rx >= 0 && ry+2<= 9 && ry+2 >= 0 && (grid[x][y].pion->right)) {
                        copy(grid, gridr);
                        if (grid[rx][ry+1].joueur != 0 && grid[rx][ry+2].joueur == 0) {
                        if (sautValide(gridr, x, y, rx,ry+2,xx,yy)) {
                                grid[rx][ry+2].pass = 1;
                                return 1;
                        } else {
                                grid[rx][ry+2].pass = 1;
                        }
                        }
                }
                if (rx-2<= 9 && rx-2 >= 0 && ry-2<= 9 && ry-2 >= 0 && (grid[x][y].pion->diagupleft)) {
                        copy(grid, gridr);
                        if (grid[rx-1][ry-1].joueur != 0 && grid[rx-2][ry-2].joueur == 0) {
                        if (sautValide(gridr, x, y, rx-2,ry-2,xx,yy)) {
                                grid[rx-2][ry-2].pass = 1;
                                return 1;
                        } else {
                                grid[rx-2][ry-2].pass = 1;
                        }
                        }
                }
                if (rx-2 <= 9 && rx-2 >= 0 && ry<= 9 && ry>= 0 && (grid[x][y].pion->up)) {
                        copy(grid, gridr);
                        if (grid[rx-1][ry].joueur != 0 && grid[rx-2][ry].joueur == 0) {
                        if (sautValide(gridr, x, y, rx-2,ry,xx,yy)) {
                                grid[rx-2][ry].pass = 1;
                                return 1;
                        } else {
                                grid[rx-2][ry].pass = 1;
                        }
                        }
                }
                if (rx-2 <= 9 && rx-2 >= 0 && ry+2<= 9 && ry+2 >= 0 && (grid[x][y].pion->diagupright)) {
                        copy(grid, gridr);
                        if (grid[rx-1][ry+1].joueur != 0 && grid[rx-2][ry+2].joueur == 0) {
                        if (sautValide(gridr, x, y, rx-2,ry+2,xx,yy)) {
                                grid[rx-2][ry+2].pass = 1;
                                return 1;
                        } else {
                                grid[rx-2][ry+2].pass = 1;
                        }
                        }
                }
                return 0;
        }
}

void afficheConsole(dalle g[10][10]) {
int i;
int j;
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++) {
if ((g[i][j].pion == NULL) && ( j == 9)) {
printf("[    ] \n");
} else if ((g[i][j].pion == NULL)) {
printf("[    ]");
}else if ((g[i][j].pion->type == CERCLE) && ( j == 9)) {
printf("[%i O ] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == CERCLE)) {
printf("[%i O ]",g[i][j].joueur);
}else if ((g[i][j].pion->type == TRIANGLE) && ( j == 9)) {
printf("[%i /\\] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == TRIANGLE)) {
printf("[%i /\\]",g[i][j].joueur);
}else if ((g[i][j].pion->type == CARRE) && (j == 9)) {
printf("[%i []] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == CARRE)) {
printf("[%i []]",g[i][j].joueur);
}else if ((g[i][j].pion->type == LOSANGE) && (j == 9)) {
printf("[%i <>] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == LOSANGE)) {
printf("[%i <>]",g[i][j].joueur);
}
}
}
}
