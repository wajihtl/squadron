#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "map.h"
void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->stage=1;
map->fond = IMG_Load("testin.png");

}


void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran)
{
 if(map.stage==1)
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);

}




