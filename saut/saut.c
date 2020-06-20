#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
 *@file main.c
 *@brief Testing program 
 *@author EssiaLitaiem
 *@date juin,2020
 * 
 *Testing program
 *
*/

int main ( int argc, char** argv )
{
    //Init de la SDL
    SDL_Init( SDL_INIT_VIDEO );

    // On crée une fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(1000, 560, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    // On charge le fond
    SDL_Surface* fond = IMG_Load("fond.png");

    //On charge Mario
    SDL_Surface* mario = IMG_Load("mario.png");

    // La position du fond
    SDL_Rect posFond;
    posFond.x = 0;
    posFond.y = 0;

    // La position absolue de Mario
    SDL_Rect posMarioAbs;
    posMarioAbs.x = 100;
    posMarioAbs.y = 375-(mario->h);

    // La position relative de Mario
    SDL_Rect posMarioRel;
    posMarioRel.x = -50;
    posMarioRel.y = 0;

    // Boucle principale du programme
    int fin = 0;
    while (!fin)
    {
        // Gestion des evenements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                // Quand on ferme la fenetre
            case SDL_QUIT:
                fin = 1;
                break;

                // Quand on appuie sur une touche
            case SDL_KEYDOWN:
                {
                    // ECHAP
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        fin = 1;
                    break;
                }
            }
        }

        // EVOLUTION
            //On avance de 1
            posMarioRel.x++;

            if(posMarioRel.x>=50)
            {
                posMarioRel.x=-50;
            }

            //On met à "0" les pos abs:
            posMarioAbs.x = 100;
            posMarioAbs.y = 375-(mario->h);

            //On calcule la valeur relative de y:
            posMarioRel.y=(-0.04*(posMarioRel.x*posMarioRel.x)+100);

            //On calcule maintenant les valeurs abs
            posMarioAbs.x = posMarioAbs.x + posMarioRel.x+50;
            posMarioAbs.y = posMarioAbs.y - posMarioRel.y;

        //Intervalle de 10ms
        SDL_Delay(10);

        // FIN EVOLUTION

        // DESSIN

        // On vide l'ecran
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        // On dessine les images aux positions respectives
        SDL_BlitSurface(fond, 0, ecran, &posFond);
        SDL_BlitSurface(mario, 0, ecran, &posMarioAbs);

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
        SDL_Flip(ecran);
    }

    // Soulageons la memoire !
    SDL_FreeSurface(fond);
    SDL_FreeSurface(mario);

    SDL_Quit();

    return 0;
}
