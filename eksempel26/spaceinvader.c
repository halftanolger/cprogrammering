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
	
	printf("Spaceinvader_opprett - start\n");

	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}

	s->poeng = 0;
	
	s->resultatliste[0] = 0;
	s->resultatliste[1] = 0;
	s->resultatliste[2] = 0;
	
	s->status = STATUS_PAUSE;
	
	
	/* Initier SDL */
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf ("SDL_Init Error: %s", SDL_GetError());
		return NULL;		
	}
	
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	if ( win == NULL){
		printf ("SDL_CreateWindow Error: %s", SDL_GetError());
		return NULL;		
	}	
	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if (ren == NULL){
		printf ("SDL_CreateRenderer Error: %s", SDL_GetError());
		return NULL;		
	}	

	
	
	
	printf("Spaceinvader_opprett - slutt\n");
	
	return s;
		
}

int Spaceinvader_spill( Spaceinvader * spaceinvader) { 

	while ( spaceinvader->status != STATUS_STOPP) {
	
		SDL_Event e;
		
		while (SDL_PollEvent(&e)){
		//If user closes the window
			if (e.type == SDL_QUIT){
				spaceinvader->status = STATUS_STOPP;
			}
			
		//If user presses any key
			if (e.type == SDL_KEYDOWN){
				spaceinvader->status = STATUS_STOPP;
			}	
			
			//If user clicks the mouse
			if (e.type == SDL_MOUSEBUTTONDOWN){
				spaceinvader->status = STATUS_STOPP;
			}
		}		
		
	}


	/*initier();
	
	while ( status != STATUS_STOPP) {
		sjekk_input();
		oppdater_spillstatus();
		render();
	}
	
	rydd_opp();
	*/
	
	return 0; 
	
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 

	printf("Spaceinvader_slett - start\n");

	SDL_Quit();
	
	assert(*spaceinvader != 0);
	free(*spaceinvader);
	
	printf("Spaceinvader_slett - slutt\n");

	return 0; 
	
}




