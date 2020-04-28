#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
#include "ennemi.h"
#include "map.h"
#include "vie.h"
#include "perso.h"
#include "collision.h"
#include "scrolling.h"
#include "input.h"
#include "score.h"

int main(int argc, char *argv[])
{
perso perso ;
vie vie;
map map ;
score score;
ennemis ennemi ;
SDL_Rect pos;
int q,w=10;

pos.x=0;
pos.y=0;

SDL_Rect camera = { 0, 0, 1000, 600 };

camera.x=0;
camera.y=0;
SDL_Surface *ecran = NULL;

srand(time(NULL)) ;
TTF_Font *police;
loadFont(&police);
int d,x=0,y=1;
int continuer = 1;

SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

initialiserperso(&perso);
initialiserfond(&map);
initialiserennemi(&ennemi);
initialiservie(&vie) ;
initialiserscore(&score);

SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
Uint32 start;
const int FPS=10;
while (continuer)
{

start=SDL_GetTicks();
d=direction(event,&continuer);
calculerScore(&score,d);
x = mouv(d,x);
y=splitennemi(y);

camera = scrolling(d,camera,&perso,&map);

perso=mouvement(perso,camera,d);
ennemi=mouvennemi(ennemi,d,camera,&q,&w,&y);


collisionennemi(&perso,&ennemi,&camera,&vie,&score);


score.posScore.x=0;
score.posScore.y=0;
vie.position.x=640;
vie.position.y=0;
afficherfond(map,camera,ecran);
afficherperso(perso,ecran,x);
afficherennemi(ennemi,ecran,y);
affichervie(&vie,ecran);
afficherscore(&score,ecran,police);
SDL_Flip(ecran);
if(1000/FPS>SDL_GetTicks()-start)
SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
}
freeFont(&police);
return 0 ;
}
