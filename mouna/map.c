#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "map.h"
void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->stage=1;
map->fond = IMG_Load("testin.png");
map->fondt = IMG_Load("forest.jpg");
}


void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran)
{
if(map.stage==1)
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
else if(map.stage==2)
SDL_BlitSurface(map.fondt,&camera, ecran,&map.position);
}




