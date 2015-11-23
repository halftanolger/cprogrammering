/*
    C -programmering, en innføring. 

    Eksempel 27

*/

#ifndef _SKJERM_H_
#define _SKJERM_H_

#include <SDL2/SDL.h>

typedef struct skjerm_st {

	void * spaceinvader;

	SDL_Window * win;
	SDL_Renderer * ren;
	SDL_Texture * tex; 		
	
} Skjerm;

Skjerm * Skjerm_opprett (void *);
int Skjerm_slett( Skjerm ** );

#endif // _SKJERM_H_