#include "map.h"
#include "pion.h"
#include "dep.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


int main(int argc, char *argv[])
{

    dalle grid[10][10];
    createGrid(grid);
    fillGrid(grid, 4);
    

SDL_Surface *ecran = NULL;
SDL_Surface *imageDeFond = NULL;
SDL_Rect positionFond;
SDL_Event event;
int continuer = 1;
int x;
int y;
int acc = 1;
    positionFond.x = 0;
    positionFond.y = 0;
    

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
 
    ecran = SDL_SetVideoMode(699, 699, 32,  SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("TRAVERSE!", NULL);

    
    imageDeFond = SDL_LoadBMP("plateau.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
   

    

    afficher(grid,ecran);
    SDL_Flip(ecran);

    while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
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
                           	 x = (event.button.x)/69.9; /* On change les coordonnées de Zozor */
           		   	 y = (event.button.y)/69.9;
				 acc = 2;
				}else {
				 mvt(grid, y, x, (event.button.y)/69.9, (event.button.x)/69.9);
				 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
				 
				 afficher(grid,ecran);
				 SDL_Flip(ecran);
				 acc=1;
					
				}
				
        	break;
		}
	  default:
	       break;
    }
       // SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); 
        //SDL_Flip(ecran); /* On met à jour l'affichage */
    

}


    SDL_FreeSurface(imageDeFond);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}

