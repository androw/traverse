#include "map.h"
#include "pion.h"
#include "dep.h"

int main () {
	dalle grid[10][10];
	createGrid(grid);
	fillGrid(grid, 4);
	afficher(grid);
	//printf("%i\n",sautValide(grid,1,0,1,0,1,2));
	//reset(grid);
	mvt(grid, 0, 1, 1, 1);
	afficher(grid);
	//printf("%i\n",sautValide(grid,1,0,1,0,1,2));
	//reset(grid);
	mvt(grid, 1, 0, 1, 2);
	afficher(grid);
	return 0;
}
