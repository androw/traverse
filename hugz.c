#include "hugz.h"

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
            if (l->acc == 3) {//cas ou la partie est nulle (meme situation 3fois)
                return 1;
            }
            else {return 0;}
        }
        else { // on verifie la situation enregistree plus recement
        if (l->suivant != NULL) {
                    l = l->suivant;
        } else {
            Noeud* p = (Noeud*)malloc(sizeof(Noeud)); //création du nouveau noeud pour la grille
                p->acc=0;//situation rencontrée deja une fois
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
