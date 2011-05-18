#include "map.h"
#include "pion.h"

int main () {
	dalle grid[10][10];
	createGrid(grid);
	printf("TEST1\n");
	fillGrid(grid, 4);
	printf("TEST2\n");
	afficher(grid);
	return 0;
}
