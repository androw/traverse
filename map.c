#include "map.h"
#include "dep.h"
void  createGrid(dalle grid[10][10]){
	int i;
	int j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j< 10; j++) {
			grid[i][j].color = (i+j)%2;
			grid[i][j].joueur = 0;
			grid[i][j].pion = NULL;
			grid[i][j].pass = 0;
			if ((i == 0) || (i == 9) || (j == 0) || (j == 9)) {
				grid[i][j].border = 1;
			} else {
				grid[i][j].border = 0;
			}
			if ((i == 0) && ((j>=1) && (j<9))) {
				grid[i][j].djoueur = 2;
				grid[i][j].ajoueur = 1;
			} else if ((i == 9) && ((j>=1) && (j<9))) {
				grid[i][j].djoueur = 1;
                                grid[i][j].ajoueur = 2;
			} else if ((j == 0)  && ((i>=1) && (i<9))) {
				grid[i][j].djoueur = 3;
                                grid[i][j].ajoueur = 4;
			} else if ((j == 9)  && ((i>=1) && (i<9))) {
                                grid[i][j].djoueur = 4;
                                grid[i][j].ajoueur = 3;
			} else {
				grid[i][j].djoueur = 0;
                                grid[i][j].ajoueur = 0;
			}
		}
	}
}

void fillGrid(dalle grille[10][10],int player) {
	pion* carre=(pion*)malloc(sizeof(pion));
	carre->up=1;
	carre->down=1;
	carre->left=1;
	carre->right=1;
	carre->diagupleft=0;
	carre->diagupright=0;
	carre->diagdownleft=0;
	carre->diagdownright=0;
	carre->type=CARRE;
	grille[0][1].pion = carre;
	grille[0][1].joueur = 2;
	grille[0][8].pion = carre;
	grille[0][8].joueur = 2;
	grille[9][1].pion = carre;
	grille[9][1].joueur = 1;
	grille[9][8].pion = carre;
	grille[9][8].joueur = 1;
	if (player==4) {
		grille[1][0].pion = carre;
       		grille[8][0].pion = carre;
       		grille[1][9].pion = carre;
       		grille[8][9].pion = carre;
		grille[1][0].joueur = 3;
                grille[8][0].joueur = 3;
                grille[1][9].joueur = 4;
                grille[8][9].joueur = 4;
}
	pion* losange=(pion*)malloc(sizeof(pion));
        losange->up=0;
        losange->down=0;
        losange->left=0;
        losange->right=0;
        losange->diagupleft=1;
        losange->diagupright=1;
        losange->diagdownleft=1;
        losange->diagdownright=1;
        losange->type=LOSANGE;
        grille[0][3].pion = losange;
        grille[0][6].pion = losange;
        grille[9][3].pion = losange;
        grille[9][6].pion = losange;
        grille[0][3].joueur = 2;
        grille[0][6].joueur = 2;
        grille[9][3].joueur = 1;
        grille[9][6].joueur = 1;
	 if (player==4) {
                 grille[3][0].pion = losange;
                 grille[3][9].pion = losange;
                 grille[6][0].pion = losange;
                 grille[6][9].pion = losange;
       		 grille[3][0].joueur = 3;
                 grille[3][9].joueur = 4;
                 grille[6][0].joueur = 3;
                 grille[6][9].joueur = 4;
	 }
	pion* cercle=(pion*)malloc(sizeof(pion));
        cercle->up=1;
        cercle->down=1;
        cercle->left=1;
        cercle->right=1;
        cercle->diagupleft=1;
        cercle->diagupright=1;
        cercle->diagdownleft=1;
        cercle->diagdownright=1;
        cercle->type=CERCLE;
        grille[0][4].pion = cercle;
        grille[0][5].pion = cercle;
        grille[9][4].pion = cercle;
        grille[9][5].pion = cercle;
	grille[0][4].joueur = 2;
        grille[0][5].joueur = 2;
        grille[9][4].joueur = 1;
        grille[9][5].joueur = 1;

        if (player==4) {
                grille[4][0].pion = cercle;
                grille[5][0].pion = cercle;
                grille[4][9].pion = cercle;
                grille[5][9].pion = cercle;
		grille[4][0].joueur = 3;
                grille[5][0].joueur = 3;
                grille[4][9].joueur = 4;
                grille[5][9].joueur = 4;
        }
	pion* triangle1=(pion*)malloc(sizeof(pion));
	pion* triangle2=(pion*)malloc(sizeof(pion));
	pion* triangle3=(pion*)malloc(sizeof(pion));
	pion* triangle4=(pion*)malloc(sizeof(pion));
        triangle1->up=0;
        triangle1->down=1;
        triangle1->left=0;
        triangle1->right=0;
        triangle1->diagupleft=1;
        triangle1->diagupright=1;
        triangle1->diagdownleft=0;
        triangle1->diagdownright=0;
        triangle1->type=TRIANGLE;
	triangle2->up=1;
        triangle2->down=0;
        triangle2->left=0;
        triangle2->right=0;
        triangle2->diagupleft=0;
        triangle2->diagupright=0;
        triangle2->diagdownleft=1;
        triangle2->diagdownright=1;
        triangle2->type=TRIANGLE;
	
        grille[0][2].pion = triangle2;
        grille[0][7].pion = triangle2;
        grille[9][2].pion = triangle1;
        grille[9][7].pion = triangle1;
        grille[0][2].joueur = 2;
        grille[0][7].joueur = 2;
        grille[9][2].joueur = 1;
        grille[9][7].joueur = 1;
	 if (player==4) {
                grille[2][0].pion = triangle3;
                grille[7][0].pion = triangle3;
                grille[2][9].pion = triangle4;
                grille[7][9].pion = triangle4;
		grille[2][0].joueur = 3;
                grille[7][0].joueur = 3;
                grille[2][9].joueur = 4;
                grille[7][9].joueur = 4;
		triangle3->up=0;
        	triangle3->down=0;
        	triangle3->left=1;
        	triangle3->right=0;
        	triangle3->diagupleft=0;
        	triangle3->diagupright=1;
        	triangle3->diagdownleft=0;
        	triangle3->diagdownright=1;
        	triangle3->type=TRIANGLE;
         	triangle4->up=0;
        	triangle4->down=0;
        	triangle4->left=0;
        	triangle4->right=1;
        	triangle4->diagupleft=1;
        	triangle4->diagupright=0;
        	triangle4->diagdownleft=1;
        	triangle4->diagdownright=0;
        	triangle4->type=TRIANGLE;
	}
}

void afficher(dalle g[10][10],SDL_Surface* ecran) {
	SDL_Surface *imageDeFond = NULL;
	SDL_Rect positionFond;
	imageDeFond = SDL_LoadBMP("plateau.bmp");
	positionFond.x = 0;
        positionFond.y = 0;
    	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	SDL_FreeSurface(imageDeFond);
	int i;
	int j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if ((g[i][j].pion == NULL) && ( j == 9)) {
				SDL_Surface *imageDeFond = NULL;
				SDL_Rect positionFond;
    				positionFond.x = j*0 ;
    				positionFond.y = i*0 ;
				
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			} else if ((g[i][j].pion == NULL)) {
				SDL_Surface *imageDeFond = NULL;
				SDL_Rect positionFond;
    				positionFond.x = j*0;
    				positionFond.y = i*0 ;
				
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == CERCLE) && ( j == 9)) {
				
				SDL_Rect positionFond;
    				positionFond.x = j*70  ;
    				positionFond.y = i*70 - 2;
				imageDeFond = SDL_LoadBMP("cercle.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == CERCLE)) {

				SDL_Rect positionFond;
    				positionFond.x = j*70 ;
    				positionFond.y = i*70- 2;
				imageDeFond = SDL_LoadBMP("cercle.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == TRIANGLE) && ( j == 9)) {

				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70- 2;
				imageDeFond = SDL_LoadBMP("triangle.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == TRIANGLE)) {

				
				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70- 2;
				imageDeFond = SDL_LoadBMP("triangle.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == CARRE) && (j == 9)) {

				
				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70;
				imageDeFond = SDL_LoadBMP("carre.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == CARRE)) {

				
				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70;
				imageDeFond = SDL_LoadBMP("carre.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == LOSANGE) && (j == 9)) {

				
				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70- 2;
				imageDeFond = SDL_LoadBMP("losange.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond);
			}else if ((g[i][j].pion->type == LOSANGE)) {

				
				SDL_Rect positionFond;
    				positionFond.x = j*70;
    				positionFond.y = i*70- 2;
				imageDeFond = SDL_LoadBMP("losange.bmp");
				SDL_SetColorKey(imageDeFond, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			}
		}
	}
}

void SDL1(dalle grid[10][10]){
SDL_Surface *ecran = NULL;
SDL_Surface *texte = NULL;
SDL_Rect positiontext;
SDL_Event event;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {255, 255, 255};
int continuer = 1;
int* x;
int* y;
int acc = 1;
int* tourj;
*tourj = 1;


    

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
TTF_Init();
    
ecran = SDL_SetVideoMode(1280, 699, 32,  SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
SDL_WM_SetCaption("TRAVERSE!", NULL);
police = TTF_OpenFont("a.ttf", 30);
afficher(grid,ecran);
turn(tourj,ecran);
positiontext.x = 700;
positiontext.y = 10;
texte = TTF_RenderText_Blended(police, "click on the piece you want to move !", couleurNoire);
SDL_BlitSurface(texte, NULL, ecran, &positiontext);
SDL_Flip(ecran);
SDL_FreeSurface(texte);

    while (continuer){

    	SDL_WaitEvent(&event);
    		switch(event.type){
        		case SDL_QUIT:
            			continuer = 0;
            			break;
        		case SDL_KEYDOWN:
            			switch (event.key.keysym.sym){
                			case SDLK_ESCAPE: 
                    			continuer = 0;
                    			break;
				  	default:
	       				break;
            			}
            			break;
			case SDL_MOUSEBUTTONUP:
        			if (event.button.button == SDL_BUTTON_LEFT) {
					if( acc == 1) {
                           	 		*x = (event.button.x)/69.9; 
           		   	 		*y = (event.button.y)/69.9;
				 		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
						SDL_FreeSurface(ecran);
						afficher(grid,ecran);
						turn(tourj,ecran);
				 		texte = TTF_RenderText_Blended(police, "click where you want to move !", couleurNoire);
						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						SDL_Flip(ecran);
				 		acc = 2;
					}else {
				 		mvt(grid, *y, *x, (event.button.y)/69.9, (event.button.x)/69.9,tourj);
						if (grid[1][9].djoueur == 4){
							if (*tourj == 3) {
								*tourj = 1;
							}
						}else {
							if (*tourj == 5) {
								*tourj = 1;
							}
						}							
				 		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,0));
						SDL_FreeSurface(ecran);
						afficher(grid,ecran);
						turn(tourj,ecran);
						texte = TTF_RenderText_Blended(police, "click on the piece you want to move !", couleurNoire);
    						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
    						SDL_Flip(ecran);
						acc=1;
					
					}
				
        				break;
				}
	 			 default:
	      			 break;
    		}
       
    

	}

TTF_CloseFont(police); 
TTF_Quit();

SDL_Quit();
}

void turn(int* tourj,SDL_Surface* ecran) {
SDL_Surface *texte = NULL;
TTF_Font *police = NULL;
SDL_Color rouge = {255, 0, 0};
police = TTF_OpenFont("a.ttf", 30);
SDL_Rect positiontext;
positiontext.x = 700;
positiontext.y = 50;
						if(*tourj == 1) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 1 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(*tourj == 2) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 2 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(*tourj == 3) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 3 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(*tourj == 4) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 4 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}
SDL_FreeSurface(texte);
}

void copy(dalle grid[10][10], dalle r[10][10]) {
	int i;
	int j;
	for (i = 0; i<10; i++) {
		for (j = 0; j<10; j++) {
			r[i][j].joueur = grid[i][j].joueur;
			r[i][j].border = grid[i][j].border;
			r[i][j].pion = grid[i][j].pion;
			r[i][j].ajoueur = grid[i][j].ajoueur;
			r[i][j].pass = grid[i][j].pass;
		}
	}
}
