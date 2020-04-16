#ifndef ENNEMI_H_
#define ENNEMI_H_
typedef struct ennemis
{
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
}ennemis;

void initialiserennemi(ennemis *ennemi);
ennemis mouvennemi(ennemis ennemi,int d,SDL_Rect camera,int *q,int *w,int *y);
int splitennemi(int y);
void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y);
#endif 
