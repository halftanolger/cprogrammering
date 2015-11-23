/*
    C -programmering, en innføring. 

    Eksempel 27

*/

#include <stdio.h>
#include "skjerm.h"

Skjerm * Skjerm_opprett(void * spaceinvader) {

	Skjerm *s = (Skjerm*)malloc(sizeof(Skjerm));
	
	if (s == NULL) {
		return NULL;
	}
	
	s->spaceinvader = spaceinvader;
	
	s->win = SDL_CreateWindow("SpaceInvaders", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	if (s->win == NULL){
		printf ("SDL_CreateWindow Error: %s", SDL_GetError());
		return NULL;		
	}	
	
	s->ren = SDL_CreateRenderer(s->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (s->ren == NULL){
		printf ("SDL_CreateRenderer Error: %s", SDL_GetError());
		return NULL;		
	}	
		
	return s;

}

int Skjerm_slett (Skjerm ** skjerm) {

	free(*skjerm);
	return 0;
	
}

