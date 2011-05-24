#ifndef PION_H
#define PION_H

enum PION {
	CARRE,
	TRIANGLE,
	LOSANGE,
	CERCLE
};



typedef struct pion{
	enum PION type;
	int left;
	int right;
	int up;
	int down;
	int diagupleft;
	int diagdownleft;
	int diagupright;
	int diagdownright;
}pion;

#endif
