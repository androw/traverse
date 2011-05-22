#include <SDL/SDL.h>
#include "map.h"
#include "pion.h"
#include "dep.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
dalle grid[10][10];
createGrid(grid,4);
fillGrid(grid, 4);
SDL1(grid);
return EXIT_SUCCESS;
}



