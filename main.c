#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "ennemi.h"
#include "map.h"
#include "vie.h"
#include "perso.h"
#include "collision.h"
#include "scrolling.h"
#include "input.h"


int main(int argc, char *argv[])
{
/*perso perso ;*/
vie vie;
map map ;

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


int d,x=0,y=1;
int continuer = 1;

SDL_Event event;

ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

/*initialiserperso(&perso);*/
initialiserfond(&map);
initialiserennemi(&ennemi);
initialiservie(&vie) ;

SDL_EnableKeyRepeat(300,10);
SDL_ShowCursor(SDL_DISABLE);
SDL_LockSurface;
while (continuer)
{
d=direction(event,&continuer);

x = mouv(d,x);
y=splitennemi(y);

/*camera = scrolling(d,camera,perso);*/

perso=mouvement(perso,camera,d);
ennemi=mouvennemi(ennemi,d,camera,&q,&w,&y);
collisionennemi(&perso,&ennemi,&camera,&vie);


afficherfond(map,camera,ecran);
/*afficherperso(perso,ecran,x);*/
afficherennemi(ennemi,ecran,y);
affichervie(&vie,ecran);
SDL_Flip(ecran);
SDL_Delay(80);
}
return 0 ;
}
