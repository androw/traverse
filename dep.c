#include "dep.h"

int depV(dalle grid[10][10], int x, int y, int i) {
	if (   
		((i == 1) && (grid[x+1][y-1].mur == 1)) || 
		((i == 2) && (grid[x+1][y].mur == 1) ) || 
		((i == 3) && (grid[x+1][y+1].mur == 1)) || 
		((i == 4) && (grid[x][y-1].mur == 1)) || 
		((i == 6) && (grid[x][y+1].mur == 1)) || 
		((i == 7) && (grid[x-1][y-1].mur == 1)) || 
		((i == 8) && (grid[x-1][y].mur == 1)) || 
		((i == 9) && (grid[x-1][y+1].mur == 1))) {
	return 0; //mur
	}else if (   
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
    return 0; // Possibilité de jouer
}

void deplacement (dalle grid[10][10], int x, int y, int xx, int yy) {
	grid[xx][yy].pion = grid[x][y].pion;
	grid[xx][yy].joueur = grid[x][y].joueur;
	grid[x][y].pion = NULL;
	grid[x][y].joueur = 0;
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
        else if (grid[xx][yy].mur == 1 || grid[rx][ry].mur == 1) {
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

void reset(dalle grid[10][10]) {
	int i;
	int j;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			grid[i][j].pass = 0;
		}
	}
}



