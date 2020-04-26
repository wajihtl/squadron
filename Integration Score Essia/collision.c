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
#include "score.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

/*SDL_Rect collision(SDL_Rect camera,perso perso,int d)
{
if(camera.x<0)
{
camera.x=0;
}

if(camera.x>6460)
{
camera.x=6460;
}
if(camera.x>900&&camera.x<1080&&perso.position.y==435)
{
if(d==1)
{
camera.x=900;
}
if(d==2)
{
camera.x=1080;
}
}
return camera ;
}
*/

int collision(perso perso,map map,SDL_Rect camera)
{
Uint32 green = SDL_MapRGB(map.fond->format,173,212,76);
if(getpixel(map.fond,perso.position.x,perso.position.y+124) == green)
{
return 1;
}
return 0;
}

void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie,score * score)
{
if(perso->position.y==ennemi->position.y)
if((((perso->position.x+perso->fond1->w > ennemi->position.x)&&(perso->position.x+perso->fond1->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))/*&&perso->position.y==255*/)
{
score->nb-=30;
if(ennemi->position.x>=perso->position.x){
ennemi->position.x+=50;
perso->position.x-=50;
}else {
ennemi->position.x-=50;
perso->position.x+=50;
}
if(score->nb<=0){

SDL_Delay(100);
ennemi->position.x = 500 ;
perso->position.x = 100 ;
perso->position.y = 275 ;
camera->x=0;
vie->nb--;
}
}
}
