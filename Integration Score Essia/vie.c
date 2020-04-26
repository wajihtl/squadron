#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "vie.h"
void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 640 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("f1.png");
vie->fond2 = IMG_Load("f2.png");
vie->fond3 = IMG_Load("f3.png");
vie->fond5 = IMG_Load("GameOver.png");
}

void affichervie(vie *vie,SDL_Surface *ecran)
{
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);
}
if(vie->nb==0)
{
vie->position.x = 0 ;
vie->position.y = 0 ;
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position);
vie->nb=3;

SDL_Flip(ecran);
sleep(4);
vie->position.x = 100 ;
vie->position.y = 150 ;
}
}
