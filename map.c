#include "map.h"
#include "time.h"


void  createGrid(dalle grid[10][10],int joueur){
	int i;
	int j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j< 10; j++) {
			grid[i][j].color = (i+j)%2;
			grid[i][j].joueur = 0;
			grid[i][j].pion = NULL;
			grid[i][j].pass = 0;
			grid[i][j].mur = 0;
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
			} else if ((j == 0)  && ((i>=1) && (i<9)) && (joueur == 4)) {
				grid[i][j].djoueur = 3;
                                grid[i][j].ajoueur = 4;
			} else if ((j == 9)  && ((i>=1) && (i<9)) && (joueur == 4)) {
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
	SDL_Rect positionFond;
	SDL_Surface *imageDeFond = NULL;
    	positionFond.x = 500;
    	positionFond.y = 0 ;
	imageDeFond = SDL_LoadBMP("fond.bmp");
	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	SDL_FreeSurface(imageDeFond);
	int i;
	int j;
	for (i = 0; i < 10; i = i + 2) {
		for (j = 0; j < 10; j++) {
			SDL_Surface *imageDeFond = NULL;
    			positionFond.x = j*70;
    			positionFond.y = i*70 ;
			imageDeFond = SDL_LoadBMP("1.bmp");
			SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			SDL_FreeSurface(imageDeFond);	
		}
	}
	for (i = 0; i < 10; i = i + 2) {
		for (j = 0; j < 10; j = j+2) {
			SDL_Surface *imageDeFond = NULL;
    			positionFond.x = j*70;
    			positionFond.y = i*70 ;
			imageDeFond = SDL_LoadBMP("2.bmp");
			SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			SDL_FreeSurface(imageDeFond);	
		}
	}
	for (i = 1; i < 10; i = i + 2) {
		for (j = 0; j < 10; j++) {
			SDL_Surface *imageDeFond = NULL;
    			positionFond.x = j*70;
    			positionFond.y = i*70 ;
			imageDeFond = SDL_LoadBMP("2.bmp");
			SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			SDL_FreeSurface(imageDeFond);	
		}
	}
	for (i = 1; i < 10; i = i + 2) {
		for (j = 0; j < 10; j = j+ 2) {
			SDL_Surface *imageDeFond = NULL;
    			positionFond.x = j*70;
    			positionFond.y = i*70 ;
			imageDeFond = SDL_LoadBMP("1.bmp");
			SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
			SDL_FreeSurface(imageDeFond);	
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if ((g[i][j].pion == NULL)) {
				SDL_Surface *imageDeFond0 = NULL;
    				positionFond.x = j*0;
    				positionFond.y = i*0 ;
				SDL_BlitSurface(imageDeFond0, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond0);
			}else if ((g[i][j].pion->type == CERCLE)) {
				SDL_Surface *imageDeFond1 = NULL;
    				positionFond.x = j*70 + 5  ;
    				positionFond.y = i*70  + 5;
				if (g[i][j].joueur == 1) {
				imageDeFond1 = IMG_Load("cercle1.png");
				}
				if (g[i][j].joueur == 2) {
				imageDeFond1 = IMG_Load("cercle2.png");
				}
				if (g[i][j].joueur == 3) {
				imageDeFond1 = IMG_Load("cercle3.png");
				}
				if (g[i][j].joueur == 4) {
				imageDeFond1 = IMG_Load("cercle4.png");
				}
				SDL_BlitSurface(imageDeFond1, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond1);
			}else if ((g[i][j].pion->type == TRIANGLE)) {
				SDL_Surface *imageDeFond2 = NULL;
    				positionFond.x = j*70 + 5 ;
    				positionFond.y = i*70+ 5;
				if (g[i][j].joueur == 1) {
				imageDeFond2 = IMG_Load("triangle1.png");
				}
				if (g[i][j].joueur == 2) {
				imageDeFond2 = IMG_Load("triangle2.png");
				}
				if (g[i][j].joueur == 3) {
				imageDeFond2 = IMG_Load("triangle3.png");
				}
				if (g[i][j].joueur == 4) {
				imageDeFond2 = IMG_Load("triangle4.png");
				}
				SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond2);
			}else if ((g[i][j].pion->type == CARRE)) {
				SDL_Surface *imageDeFond3 = NULL;
    				positionFond.x = j*70 + 5;
    				positionFond.y = i*70 + 5;
				if (g[i][j].joueur == 1) {
				imageDeFond3 = SDL_LoadBMP("carre1.bmp");
				}
				if (g[i][j].joueur == 2) {
				imageDeFond3 = SDL_LoadBMP("carre2.bmp");
				}
				if (g[i][j].joueur == 3) {
				imageDeFond3 = SDL_LoadBMP("carre3.bmp");
				}
				if (g[i][j].joueur == 4) {
				imageDeFond3 = SDL_LoadBMP("carre4.bmp");
				}
				SDL_SetColorKey(imageDeFond3, SDL_SRCCOLORKEY, SDL_MapRGB(imageDeFond3->format, 255, 255, 255));
				SDL_BlitSurface(imageDeFond3, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond3);
			}else if ((g[i][j].pion->type == LOSANGE)) {
				SDL_Surface *imageDeFond4 = NULL;
    				positionFond.x = j*70 + 5;
    				positionFond.y = i*70 + 5;
				if (g[i][j].joueur == 1) {
				imageDeFond4 = IMG_Load("losange1.png");
				}
				if (g[i][j].joueur == 2) {
				imageDeFond4 = IMG_Load("losange2.png");
				}
				if (g[i][j].joueur == 3) {
				imageDeFond4 = IMG_Load("losange3.png");
				}
				if (g[i][j].joueur == 4) {
				imageDeFond4 = IMG_Load("losange4.png");
				}
				SDL_BlitSurface(imageDeFond4, NULL, ecran, &positionFond);
				SDL_FreeSurface(imageDeFond4);
			}
		}
	}
}	

void SDL1(dalle grid[10][10]){
SDL_Surface *ecran = NULL;
SDL_Surface *texte = NULL;
SDL_Surface *caze = NULL;
SDL_Rect positiontext;
SDL_Rect positionCurseur;
SDL_Event event;
TTF_Font *police = NULL;
SDL_Color couleurNoire = {255, 255, 255};
int continuer = 1;
int x;
int y;
int acc = 1;
int tourj = 1;
int xp;
int yp;
char nbr[4];
int touri = 1;
sprintf( nbr, "%d", touri );
char tour[15] = "Turn number ";

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
TTF_Init();
    
ecran = SDL_SetVideoMode(1280, 699, 32,  SDL_HWSURFACE |SDL_DOUBLEBUF);
SDL_WM_SetCaption("TRAVERSE!", NULL);
police = TTF_OpenFont("a.ttf", 45);
afficher(grid,ecran);
turn(tourj,ecran);
positiontext.x = 700;
positiontext.y = 10;
texte = TTF_RenderText_Blended(police, "click on the piece you want to move !", couleurNoire);
SDL_BlitSurface(texte, NULL, ecran, &positiontext);
positiontext.x = 700;
positiontext.y = 100;
texte = TTF_RenderText_Blended(police, "Turn number 1", couleurNoire);
SDL_BlitSurface(texte, NULL, ecran, &positiontext);
positiontext.x = 700;
positiontext.y = 10;
SDL_Flip(ecran);
SDL_FreeSurface(texte);

    while (continuer && condWin(grid,4)==0) {

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
				case SDL_MOUSEBUTTONUP:
        			if (event.button.button == SDL_BUTTON_LEFT) {
						x = (event.button.x)/70; 
           		   	 	y = (event.button.y)/70;
						if( (acc == 1) ) {
							if ((grid[y][x].joueur == tourj)) {
                           		xp = x;
								yp = y;
								positionCurseur.x = (x)*70;
								positionCurseur.y = (y)*70;
								SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
								SDL_FreeSurface(ecran);
								afficher(grid,ecran);
								turn(tourj,ecran);
								texte = TTF_RenderText_Blended(police, "click where you want to move !", couleurNoire);
								SDL_BlitSurface(texte, NULL, ecran, &positiontext);
								SDL_FreeSurface(texte);
								positiontext.x = 700;
								positiontext.y = 100;
								texte = TTF_RenderText_Blended(police, tour, couleurNoire);
								SDL_BlitSurface(texte, NULL, ecran, &positiontext);
								SDL_FreeSurface(texte);
								positiontext.x = 900;
								positiontext.y = 100;
								texte = TTF_RenderText_Blended(police, nbr, couleurNoire);
								SDL_BlitSurface(texte, NULL, ecran, &positiontext);
								SDL_FreeSurface(texte);
								positiontext.x = 700;
								positiontext.y = 10;
								caze = SDL_LoadBMP("caze.bmp");
								SDL_SetAlpha(caze, SDL_SRCALPHA, 50);
								SDL_BlitSurface(caze, NULL, ecran, &positionCurseur);
								SDL_FreeSurface(caze);
								SDL_Flip(ecran);
								acc = 2;
							}else { 
							SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
						    SDL_FreeSurface(ecran);
							afficher(grid,ecran);
							positiontext.x = 700;
							positiontext.y = 150;
							texte = TTF_RenderText_Blended(police, "Uncorrect Click !! ", couleurNoire);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
							
							SDL_FreeSurface(texte);
							SDL_FreeSurface(ecran);
						turn(tourj,ecran);
						texte = TTF_RenderText_Blended(police, "click on the piece you want to move !", couleurNoire);
    						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 700;
						positiontext.y = 100;
						texte = TTF_RenderText_Blended(police, tour, couleurNoire);
						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 900;
						positiontext.y = 100;
						texte = TTF_RenderText_Blended(police, nbr, couleurNoire);
						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 700;
						positiontext.y = 10;
						SDL_Flip(ecran);
						}
												
				}else {SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,0));
						
				 		if(mvt(grid, yp, xp, (event.button.y)/69.9, (event.button.x)/69.9)) {
						
							tourj++;
							afficher(grid,ecran);
							if (tourj == 5) {
								touri++;
								sprintf( nbr, "%d", touri );
							}
						}else{afficher(grid,ecran);
							positiontext.x = 700;
							positiontext.y = 150;
							texte = TTF_RenderText_Blended(police, "Uncorrect Click !! ", couleurNoire);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
							SDL_FreeSurface(texte);	
							
						}
						
						
						if (grid[1][9].djoueur == 4){
							if (tourj == 5) {
								tourj = 1;
							}
						}else {
							if (tourj == 3) {
								tourj = 1;
							}
						}							
				 		
						SDL_FreeSurface(ecran);
						
						turn(tourj,ecran);
						texte = TTF_RenderText_Blended(police, "click on the piece you want to move !", couleurNoire);
    						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 700;
						positiontext.y = 100;
						texte = TTF_RenderText_Blended(police, tour, couleurNoire);
						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 900;
						positiontext.y = 100;
						texte = TTF_RenderText_Blended(police, nbr, couleurNoire);
						SDL_BlitSurface(texte, NULL, ecran, &positiontext);
						SDL_FreeSurface(texte);
						positiontext.x = 700;
						positiontext.y = 10;
						
						
						
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

void turn(int tourj,SDL_Surface* ecran) {
SDL_Surface *texte = NULL;
TTF_Font *police = NULL;
SDL_Color rouge = {255, 0, 0};
police = TTF_OpenFont("a.ttf", 45);
SDL_Rect positiontext;
positiontext.x = 700;
positiontext.y = 50;
						if(tourj == 1) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 1 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(tourj == 2) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 2 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(tourj == 3) {
							positiontext.x = 700;
							positiontext.y = 50;
							texte = TTF_RenderText_Blended(police, "Player 3 Turn !", rouge);
							SDL_BlitSurface(texte, NULL, ecran, &positiontext);
							positiontext.x = 700;
							positiontext.y = 10;
						}if(tourj == 4) {
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

void fillGridHM(dalle grille[10][10],int player) {
	pion* carre=(pion*)malloc(sizeof(pion));
	int accMur =7;
	int randx;
	int randy;
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
	while (accMur != 0) {
		srand(time(NULL));
		randx=rand()%6 + 1;
		randy=rand()%6 + 1;
		if (grille[randx][randy].mur == 0) {
			grille[randx][randy].mur =1;
			accMur--;
		}
	}
}

void afficheConsole(dalle g[10][10]) {
int i;
int j;
for (i = 0; i < 10; i++) {
for (j = 0; j < 10; j++) {
   if ((g[i][j].mur == 1) && ( j == 9)) {
printf("[  X ] \n");
} else if ((g[i][j].mur == 1)) {
printf("[  X ]");
}else if ((g[i][j].pion == NULL) && ( j == 9)) {
printf("[    ] \n");
} else if ((g[i][j].pion == NULL)) {
printf("[    ]");
}else if ((g[i][j].pion->type == CERCLE) && ( j == 9)) {
printf("[%i O ] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == CERCLE)) {
printf("[%i O ]",g[i][j].joueur);
}else if ((g[i][j].pion->type == TRIANGLE) && ( j == 9)) {
printf("[%i /\\] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == TRIANGLE)) {
printf("[%i /\\]",g[i][j].joueur);
}else if ((g[i][j].pion->type == CARRE) && (j == 9)) {
printf("[%i []] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == CARRE)) {
printf("[%i []]",g[i][j].joueur);
}else if ((g[i][j].pion->type == LOSANGE) && (j == 9)) {
printf("[%i <>] \n",g[i][j].joueur);
}else if ((g[i][j].pion->type == LOSANGE)) {
printf("[%i <>]",g[i][j].joueur);
}
}
}
}

