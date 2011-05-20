#include "map.h"
#include "pion.h"
#include "dep.h"

int main () {
	dalle grid[10][10];
	createGrid(grid);
	fillGrid(grid, 4);
	afficher(grid);
	mvt(grid, 0, 1, 1, 1);
	mvt(grid, 0, 4, 1, 3);
	mvt(grid, 0, 5, 1, 5);
	afficher(grid);
	//printf("%i\n",sautValide(grid,1,0,1,0,1,2));
	//reset(grid);
	//mvt(grid, 1, 0, 1, 2);
	mvt(grid, 1, 0, 1, 6);
	afficher(grid);
	return 0;
}
