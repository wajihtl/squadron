#ifndef PERSO_H_
#define PERSO_H_
/**
* @struct perso
* @brief struct for perso
*/
typedef struct perso
{
	SDL_Rect position;
	SDL_Surface *fond0;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
	SDL_Surface *fondc;
}perso;


void initialiserperso(perso *perso);
int mouv(int d,int x);
perso mouvement(perso pers,SDL_Rect camera,int d);
void afficherperso(perso perso,SDL_Surface *ecran,int x);

#endif 
