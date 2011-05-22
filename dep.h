#ifndef DEP_H
#define DEP_H

#include "map.h"

int depV(dalle grid[10][10], int x, int y, int i);
int sautValide(dalle grid[10][10], int x, int y,int rx,int ry, int xx, int yy);
void deplacement (dalle grid[10][10], int x, int y, int xx, int yy);
int mvt(dalle grid[10][10], int x, int y, int xx, int yy);
void reset(dalle grid[10][10]);
#endif
