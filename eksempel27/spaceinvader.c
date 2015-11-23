/*
    C -programmering, en innføring. 

    Eksempel 27

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include "spaceinvader.h"


Spaceinvader * Spaceinvader_opprett() { 
	
	/* Opprett Spaceinvader-objekt. */
	
	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}
	
	s->modell = Modell_opprett(s);
			
			
			kontrollsentral må oprettestasdfalsdfsødlfk
			
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

	Kontrollsentral *k = spaceinvader->kontrollsentral;
	
	while (Kontrollsentral_er_vi_ferdig(k) != 1) {
	
		SDL_Event e;
		
		/* Sjekk input*/
		
		while (SDL_PollEvent(&e)){
		
			if (e.type == SDL_QUIT){
				Kontrollsentral_avslutt(k);				
			}
					
			if (e.type == SDL_KEYDOWN){
				Kontrollsentral_avslutt(k);				
			}	
					
			if (e.type == SDL_MOUSEBUTTONDOWN){
				Kontrollsentral_avslutt(k);				
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




