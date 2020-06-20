/**
* @file main.c
* @brief Testing Program.
* @author Chorfi mouna
* @version 0.1
* @date juin 14,2020
*
* Testing program for integrated
*
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "perso.h"
#include "scrolling.h"
#include "input.h"


int main(int argc, char *argv[])
{
perso perso ;
map map ;
SDL_Rect pos;
int q,w=10;

pos.x=0;
pos.y=0;

SDL_Rect camera = { 0, 0, 1000, 600 };

camera.x=0;
camera.y=0;
SDL_Surface *ecran = NULL;
int d,x=0,y=1;
int continuer = 1;

SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

initialiserperso(&perso);
initialiserfond(&map);
SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
Uint32 start;
const int FPS=10;
while (continuer)
{

start=SDL_GetTicks();
d=direction(event,&continuer);
x = mouv(d,x);

camera = scrolling(d,camera,&perso,&map);

perso=mouvement(perso,camera,d);

afficherfond(map,camera,ecran);
afficherperso(perso,ecran,x);

SDL_Flip(ecran);
if(1000/FPS>SDL_GetTicks()-start)
SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
}

return 0 ;
}
