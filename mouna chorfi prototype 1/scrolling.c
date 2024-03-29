/**
* @file scrolling.c
* @brief Testing Program.
* @author Chorfi mouna
* @version 0.1
* @date juin 20, 2020
*
* Testing program for background scrollilng
*
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
/**
* @brief To initialize the scrolling.
* @param d
* @param camera
* @param pers the perso
* @param map the map
* @return camera
*/
SDL_Rect scrolling(int d,SDL_Rect camera,perso *pers,map *map)
{
int C;

if(camera.x<=0) camera.x=0;
if(camera.x>=6478) camera.x=6478;
if(d==1&&pers->position.x>=500)
{
camera.x=camera.x+20;
}
if(d==2&&pers->position.x<=500 )
{
camera.x=camera.x-20;
}

if(d==1 && pers->position.x>=1000){
map->stage++;
camera.x=0;
pers->position.x=100;
}


return camera ;
}

