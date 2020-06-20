/**
* @file hero.c
* @brief Testing Program.
* @author chorfi mouna
* @version 0.1
* @date juin 14, 2020
*
* Testing program for hero
*
*/
#include "hero.h"

/**
* @brief To initialize the hero H .
* @param H the hero
* @return OK
*/
int init_hero(Hero* H)
{
	int OK;

	OK = loadHeroImages(H);
	if (OK != -1)
	{
		initHeroAttributes(H);
	}
	
	return OK;
}
/**
* @brief To load the image .
* @param h the hero
* @return 0
*/

int loadHeroImages(Hero * H)
{
	H->image = IMG_Load("hero_spr.png");

	if(H->image == NULL) {
		printf("Unable to load Hero gif:%s\n", SDL_GetError());
		return (-1);
	}

	return (0);
}
/**
* @brief To position the hero h .
* @param h the hero
* @return Nothing
*/

void initHeroAttributes(Hero* H)
{	
	int i, j;	
	
	H->positionAbsolue.x = 0;
	H->positionAbsolue.y = 0.8 * BACKGND_H - Hero_HEIGHT;
	H->positionAbsolue.w = Hero_WIDTH;
	H->positionAbsolue.h = Hero_HEIGHT;
	H->Frame.i = 0;
	H->Frame.j = 0;
	
        // Faire le calcul des SDL_Rect des positions de toutes 
	// les imagettes une seule fois à l'initialisation
	for (i = 0; i < SPRITE_HERO_NbL; i++)
	{	for(j = 0; j < SPRITE_HERO_NbCol; j++)
		{	
			H->positionAnimation[i][j].x = j * Hero_WIDTH;
			H->positionAnimation[i][j].y = i * Hero_HEIGHT;
			H->positionAnimation[i][j].w = Hero_WIDTH;  
			H->positionAnimation[i][j].h = Hero_HEIGHT;
		}
	}
	H->vies = 100;
	H->is_attacking = 0;	
}
/**
* @brief To blit the hero h .
* @param h the hero
* @param screen
* @return Nothing
*/

void display_hero(Hero H, SDL_Surface* screen)
{
	if (H.vies!=0)
	SDL_BlitSurface(H.image, &H.positionAnimation[H.Frame.i][H.Frame.j], screen, &H.positionAbsolue);
}
/**
* @brief To update the hero h .
* @param h the hero
* @param tab_input
* @param he_collision
* @return Nothing
*/


void update_hero(Hero* H, int Tab_input[], int HE_collision)
{

	animateHero(H, Tab_input);
	moveHero(H, Tab_input);
	updateHeroScore(H, HE_collision);
}
/**
* @brief To animate the hero h.
* @param h the hero
* @param tab_input
* @return Nothing
*/

void animateHero(Hero *H, int Tab_input[])
{
	// mise a jour du numero de l'imagette 
		if(Tab_input[SDLK_RIGHT])
		{
			H->Frame.i = 0;
			H->Frame.j ++;    
			if (H->Frame.j == SPRITE_HERO_NbCol)   
		 		H->Frame.j = 0;
		}
		if(Tab_input[SDLK_LEFT])
		{
			H->Frame.i = 1;
			H->Frame.j ++;    
			if (H->Frame.j == SPRITE_HERO_NbCol)   
		 		H->Frame.j = 0;
		}	
}
/**
* @brief To move the hero h .
* @param h the hero
* @param tab_input
* @return Nothing
*/

void moveHero(Hero *H, int Tab_input[])
{
	if(Tab_input[SDLK_RIGHT])
        	H->positionAbsolue.x +=20;   
	if(Tab_input[SDLK_LEFT])
        	H->positionAbsolue.x -=20; 
/*if(Tab_input[SDLK_UP]){
        	H->positionAbsolue.y -=20; 
		
}*/
}

/**
* @brief To update score .
* @param h the hero
* @param he_collision
* @return Nothing
*/

void updateHeroScore(Hero* H, int HE_collision)
{
	if(HE_collision)
		if(H->vies > 0)
			H->vies --;
}

/**
* @brief To free the memory .
* @param h the hero
* @return Nothing
*/
void freeHero(Hero *H)
{
	SDL_FreeSurface(H->image);
}
