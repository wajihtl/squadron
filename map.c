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
map->fond = IMG_Load("forest.jpg");
}


void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
}




