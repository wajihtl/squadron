#ifndef MAP_H_
#define MAP_H_
typedef struct map
{
	SDL_Rect position;
	SDL_Surface *fond;
}map;


void initialiserfond(map *map);

void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran);
#endif 
