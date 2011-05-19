#include "map.h"
#include "pion.h"
#include "dep.h"

int main () {
	dalle grid[10][10];
	createGrid(grid);
	fillGrid(grid, 4);
	afficher(grid);
	//printf ("%i\n",depV(grid,0,4,6));
	printf("%i\n",sautValide(grid,0,1,0,1,1,2));
	mvt(grid, 0, 1, 1, 1);
	afficher(grid);
	printf("%i\n",sautValide(grid,0,1,0,1,1,2));
	mvt(grid, 1, 0, 1, 2);
	afficher(grid);
	return 0;
}
