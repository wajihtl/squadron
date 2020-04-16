#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "scrolling.h"

SDL_Rect scrolling(int d,SDL_Rect camera,perso pers)
{
int C;

if(camera.x<=0) camera.x=0;
if(camera.x>=7000) camera.x=7000;
if(d==1&&pers.position.x>=500)
{
camera.x=camera.x+20;
}
if(d==2&&pers.position.x<=500 )
{
camera.x=camera.x-20;
}



return camera ;
}

