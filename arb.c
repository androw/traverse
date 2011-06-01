#include "arb.h"

int pathTest (Noeud* teteliste, dalle grid[10][10]) {
    Noeud* l = teteliste;
    int fullPath;
    int i;
    int j;


    while (l != NULL) { //pour chaque situation deja rencontree ...
        fullPath = 1;
        for (i=0;i<10;i++) {
            for (j=0;j<10;j++) {//...pour chaque case...
                if (grid[i][j].joueur != l->grille[i][j].joueur || grid[i][j].pion != l->grille[i][j].pion) {
                    fullPath = 0; //...il y a une différence donc pas de situation d'egalite...
                }
                else  {
                    fullPath = fullPath && 1;//...il n'y a pas de difference pour cette case, on continue a verifier
                }
            }
        }
        if (fullPath == 1) {
            l->acc = l->acc + 1;//incrementation de la situation rencontree
            if (l->acc >= 3) {//cas ou la partie est nulle (meme situation 3fois)
                return 1;
            }
            else {return 0;}
        }
        else { // on verifie la situation enregistree plus recement
        if (l->suivant != NULL) {
                    l = l->suivant;
        } else {
            Noeud* p = (Noeud*)malloc(sizeof(Noeud)); //création du nouveau noeud pour la grille
                p->acc= 1;//situation rencontrée deja une fois
                for (i=0;i<10;i++) {
                        for (j=0;j<10;j++) {//copie de la grille
                            p->grille[i][j].pion = grid[i][j].pion;
                            p->grille[i][j].joueur = grid[i][j].joueur;
                        }
                }
                p->suivant=NULL;//ajoutfin
                l->suivant=p;
                return 0;
            }
        }
    }
    return 0;
}

int pat(Noeud* teteliste) {
	Noeud* l = teteliste;
	while (l != NULL) {
		if (l->acc >= 3) {
			return 1;
		}
		else {
			l = l->suivant;
		}
	}
	return 0;
}


int condWin(dalle grid[10][10],int player) {
    
        if (
               grid[0][1].joueur==1
            && grid[0][2].joueur==1
            && grid[0][3].joueur==1
            && grid[0][4].joueur==1
            && grid[0][5].joueur==1
            && grid[0][6].joueur==1
            && grid[0][7].joueur==1
            && grid[0][8].joueur==1) {
                return 1;
        }
        else if (
               grid[9][1].joueur==2
            && grid[9][2].joueur==2
            && grid[9][3].joueur==2
            && grid[9][4].joueur==2
            && grid[9][5].joueur==2
            && grid[9][6].joueur==2
            && grid[9][7].joueur==2
            && grid[9][8].joueur==2) {
                return 2;
        }
     if (player == 4) {
        if (
               grid[1][9].joueur==3
            && grid[2][9].joueur==3
            && grid[3][9].joueur==3
            && grid[4][9].joueur==3
            && grid[5][9].joueur==3
            && grid[6][9].joueur==3
            && grid[7][9].joueur==3
            && grid[8][9].joueur==3) {
                return 3;
        }
        else if (
               grid[1][0].joueur==4
            && grid[2][0].joueur==4
            && grid[3][0].joueur==4
            && grid[4][0].joueur==4
            && grid[5][0].joueur==4
            && grid[6][0].joueur==4
            && grid[7][0].joueur==4
            && grid[8][0].joueur==4 ) {
                return 4;
        }
        else return 0;
     }
    else return 0;
}


int condWinHM(dalle grid[10][10],int player) {
    
        if (
               grid[0][1].joueur==1 && grid[0][1].pion->type == CARRE
            && grid[0][2].joueur==1 && grid[0][2].pion->type == TRIANGLE
            && grid[0][3].joueur==1 && grid[0][3].pion->type == LOSANGE
            && grid[0][4].joueur==1 && grid[0][4].pion->type == CERCLE
            && grid[0][5].joueur==1 && grid[0][5].pion->type == CERCLE
            && grid[0][6].joueur==1 && grid[0][6].pion->type == LOSANGE
            && grid[0][7].joueur==1 && grid[0][7].pion->type == TRIANGLE
            && grid[0][8].joueur==1 && grid[0][8].pion->type == CARRE) {
                return 1;
        }
        else if (
               grid[9][1].joueur==2 && grid[9][1].pion->type == CARRE
            && grid[9][2].joueur==2 && grid[9][2].pion->type == TRIANGLE
            && grid[9][3].joueur==2 && grid[9][3].pion->type == LOSANGE
            && grid[9][4].joueur==2 && grid[9][4].pion->type == CERCLE
            && grid[9][5].joueur==2 && grid[9][4].pion->type == CERCLE
            && grid[9][6].joueur==2 && grid[9][6].pion->type == LOSANGE
            && grid[9][7].joueur==2 && grid[9][7].pion->type == TRIANGLE
            && grid[9][8].joueur==2 && grid[9][8].pion->type == CARRE) {
                return 2;
        }
     if (player == 4) {
        if (
               grid[1][9].joueur==3 && grid[1][9].pion->type == CARRE
            && grid[2][9].joueur==3 && grid[2][9].pion->type == TRIANGLE
            && grid[3][9].joueur==3 && grid[3][9].pion->type == LOSANGE
            && grid[4][9].joueur==3 && grid[4][9].pion->type == CERCLE
            && grid[5][9].joueur==3 && grid[5][9].pion->type == CERCLE
            && grid[6][9].joueur==3 && grid[6][9].pion->type == LOSANGE
            && grid[7][9].joueur==3 && grid[7][9].pion->type == TRIANGLE
            && grid[8][9].joueur==3 && grid[8][9].pion->type == CARRE) {
                return 3;
        }
        else if (
               grid[1][0].joueur==4 && grid[1][0].pion->type == CARRE
            && grid[2][0].joueur==4 && grid[2][0].pion->type == TRIANGLE
            && grid[3][0].joueur==4 && grid[3][0].pion->type == LOSANGE
            && grid[4][0].joueur==4 && grid[4][0].pion->type == CERCLE
            && grid[5][0].joueur==4 && grid[5][0].pion->type == CERCLE
            && grid[6][0].joueur==4 && grid[6][0].pion->type == LOSANGE
            && grid[7][0].joueur==4 && grid[7][0].pion->type == TRIANGLE
            && grid[8][0].joueur==4 && grid[8][0].pion->type == CARRE ) {
                return 4;
        }
        else return 0;
    }
    else return 0;
}

int antiJeuTest(dalle grid[10][10],int tour) {
	int i;
if (tour >= 30) {
	for (i=1;i<9;i++) {
		if (grid[9][i].joueur == 1) {
			return 1;
		}
	}
	for (i=1;i<9;i++) {
		if (grid[0][i].joueur == 2) {
			return 2;
		}
	}
	for (i=1;i<9;i++) {
		if (grid[i][0].joueur == 3) {
			return 3;
		}
	}
	for (i=1;i<9;i++) {
		if (grid[i][9].joueur == 4) {
			return 4;
		}
	}
	return 0;
}
else return 0;
}
