#ifndef COLLISION_H_
#define COLLISION_H_
#include "score.h"


Uint32 getpixel(SDL_Surface *surface, int x, int y);
int collision(perso perso,map map,SDL_Rect camera);

void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie,score *score);

#endif 
