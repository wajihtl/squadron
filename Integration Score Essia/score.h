#ifndef SCORE_H_
#define SCORE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct score
{
	int nb;
	SDL_Surface *textScore;
	SDL_Rect posScore;
	
}score;

void initialiserscore(score *score);
void afficherscore(score *score , SDL_Surface *ecran,TTF_Font *police);
void calculerScore(score *score,int d);
void loadFont(TTF_Font **police);
void freeFont(TTF_Font **police);
#endif 

