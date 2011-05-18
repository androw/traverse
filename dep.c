#include "dep.h"


int depV(case grid[10][10], int x, int y, int i) {
	if (((i == 1) && (grid[x+1][y-1].border == 1) && (grid[x][y].joueur =! grid[x+1][y-1].ajoueur)) || ((i == 2) && (grid[x+1][y].border == 1) && (grid[x][y].joueur =! grid[x+1][y].ajoueur)) || ((i == 3) && (grid[x+1][y+1].border == 1) && (grid[x][y].joueur =! grid[x+1][y+1].ajoueur)) || 
((i == 4) && (grid[x][y-1].border == 1)&& (grid[x][y].joueur =! grid[x][y-1].ajoueur)) || ((i == 6) && (grid[x][y+1].border == 1)&& (grid[x][y].joueur =! grid[x][y+1].ajoueur)) || ((i == 7) && (grid[x-1][y-1].border == 1)&& (grid[x][y].joueur =! grid[x-1][y-1].ajoueur)) || ((i == 2) && (grid[x-1][y].border == 1) && (grid[x][y].joueur =! grid[x-1][y].ajoueur)) || ((i == 9) && (grid[x-1][y+1].border == 1)&& (grid[x][y].joueur =! grid[x-1][y+1].ajoueur))) {
	return 0;
	}else if (
			

 else{
		switch (i) {
			case 1 : return (grid[x][y].pion.diagdownleft);
			case 2 : return (grid[x][y].pion.down);
			case 3 : return (grid[x][y].pion.diagdownright);
			case 4 : return (grid[x][y].pion.left);
			case 6 : return (grid[x][y].pion.right);
			case 7 : return (grid[x][y].pion.diagupleft);
			case 8 : return (grid[x][y].pion.up);
			case 9 : return (grid[x][y].pion.diagupright);
		}
	}
}
