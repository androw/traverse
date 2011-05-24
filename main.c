#include <SDL/SDL.h>
#include "map.h"
#include "pion.h"
#include "dep.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
dalle grid[10][10];
createGrid(grid, 2);
fillGrid(grid, 2);
SDL1(grid);
return EXIT_SUCCESS;
}



