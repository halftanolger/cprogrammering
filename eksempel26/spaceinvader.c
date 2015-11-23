/*
    C -programmering, en innføring. 

    Eksempel 26

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <spaceinvader.h>
#include <SDL2/SDL.h>

Spaceinvader * Spaceinvader_opprett() { 
	
	/* Opprett Spaceinvader-objekt. */
	
	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}
	
	s->status = STATUS_PAUSE;
		
	/* Initier SDL */
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf ("SDL_Init Error: %s", SDL_GetError());
		return NULL;		
	}
	
	/* Opprett skjerm-objekt. */
	
	s->skjerm = Skjerm_opprett(s);
	
	if (s->skjerm == NULL) {
		printf ("Skjerm_opprett Error: Systemfeil.");
		return NULL;
	}
			
	return s;
		
}

int Spaceinvader_spill(Spaceinvader * spaceinvader) { 

	if (spaceinvader == NULL) {
		return 1;
	}

	while ( spaceinvader->status != STATUS_STOPP) {
	
		SDL_Event e;
		
		/* Sjekk input*/
		
		while (SDL_PollEvent(&e)){
		
			if (e.type == SDL_QUIT){
				spaceinvader->status = STATUS_STOPP;
			}
					
			if (e.type == SDL_KEYDOWN){
				spaceinvader->status = STATUS_STOPP;
			}	
					
			if (e.type == SDL_MOUSEBUTTONDOWN){
				spaceinvader->status = STATUS_STOPP;
			}
			
		}		
		
		/* Oppdater status */
		
		/* Rendrer */
		
	}

	return 0; 
	
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 
	
	if (*spaceinvader == NULL) {
		return 1;
	}
	
	Skjerm_slett(&((*spaceinvader)->skjerm));
	
	SDL_Quit();
	
	free(*spaceinvader);

	return 0; 
	
}




