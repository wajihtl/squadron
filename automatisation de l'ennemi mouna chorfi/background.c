
/**
* @file bakground.c
* @brief Testing Program.
* @author chorfi mouna
* @version 0.1
* @date juin 14, 2020
*
* Testing program for background scrollilng
*
*/
#include <SDL/SDL_image.h>
#include "background.h"
/**
* @brief To initialize the background b .
* @param b the background
* @return ok
*/

int init_background(Background *B)
{
	int OK;

	OK = loadBackground(B); //Verification de chargement de background
	if (OK != -1)
	{
		initBackgoundAttributes(B); //attribuer les positions
	}
	
	return OK;
}
/**
* @brief to load the background b .
* @param b the background
* @return 0
*/

int loadBackground(Background *B)
{

	B->background = IMG_Load("background.png"); //chargement de l'image
	if (B->background == NULL)
		{
			printf("Unable to load backround image: %s\n", SDL_GetError());
			return (-1);
		}
	
	
	return (0);
}

/**
* @brief To position the background b .
* @param b the background
* @return Nothing
*/
void initBackgoundAttributes(Background *B) //position du background
{
	B->posback.x=0;
	B->posback.y=0;
	B->posback.w=SCREEN_W;
	B->posback.h=SCREEN_H;
}
/**
* @brief To blit the image .
* @param b the background
* @param screen
* @return Nothing
*/

void display_background(Background B,SDL_Surface *screen) //coller l'image sur screen
{
	SDL_BlitSurface(B.background, &(B.posback), screen,NULL); 

}
/**
* @brief To free the memory .
* @param b the background
* @return Nothing
*/

void freeBackground(Background *B) //liberer l'espace
{
	SDL_FreeSurface(B->background);
}
