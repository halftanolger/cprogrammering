/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#include <stdio.h>
#include "kanon.h"
#include "spaceinvader.h"
#include "skjerm.h"

Skjerm * Skjerm_opprett(void * spaceinvader) {

	Skjerm *s = (Skjerm*)malloc(sizeof(Skjerm));
	
	if (s == NULL) {
		return NULL;
	}
	
	s->spaceinvader = spaceinvader;
	
	s->bredde = 640;
	s->hoeyde = 480;
	
	s->win = SDL_CreateWindow("SpaceInvaders", 100, 100, s->bredde, s->hoeyde, SDL_WINDOW_SHOWN);
	
	if (s->win == NULL){
		printf ("SDL_CreateWindow Error: %s", SDL_GetError());
		return NULL;		
	}	
	
	s->ren = SDL_CreateRenderer(s->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (s->ren == NULL){
		printf ("SDL_CreateRenderer Error: %s", SDL_GetError());
		return NULL;		
	}	
		
	SDL_SetRenderDrawColor (s->ren, 0, 0, 0, 255);
	SDL_RenderClear (s->ren);		
	SDL_RenderPresent (s->ren);		
		
	return s;

}

int Skjerm_slett (Skjerm ** skjerm) {

	free(*skjerm);
	return 0;
	
}


void Skjerm_render (Skjerm * skjerm) {

	Spaceinvader * spaceinvader = skjerm->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Kanon * kanon = modell->kanon;

	SDL_SetRenderDrawColor (skjerm->ren, 0, 0, 0, 255);
	SDL_RenderClear (skjerm->ren);		

	/* Render kanonen med eventuelle tilhørene prosjektiler. */
	
	Kanon_render (kanon);
	
	/* Render ufo'er med eventuelle tilhørene prosjektiler. */
	
	int teller;
	for (teller = 0; teller < 55; teller++) {
		Ufo_render(modell->ufo[teller]);
	}
	
	SDL_RenderPresent(skjerm->ren);
	
}
