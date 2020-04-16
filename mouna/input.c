#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "input.h"
int direction(SDL_Event event,int *continuer){
int d;
SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            *continuer = 0;
  		break;
	case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    continuer=0 ;
			break ;

		case SDLK_LEFT :
		d=2;	
                    	break ;

		case SDLK_RIGHT :
		d=1; 
			break ;

		case SDLK_UP :
		d=3;	
                    	break ;

		case SDLK_DOWN :
		d=4; 
			break ;
	    }
		break;
    }
return d;
}
