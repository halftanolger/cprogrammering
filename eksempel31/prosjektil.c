/*
    C -programmering, en innføring. 

    Eksempel 31

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "prosjektil.h"

Prosjektil * Prosjektil_opprett(void * spaceinvader, int type, int x, int y) {

	Prosjektil *prosjektil = (Prosjektil*)malloc(sizeof(Prosjektil));
		
	prosjektil->spaceinvader = spaceinvader;
	prosjektil->type = type;
	
	Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;	
	
	prosjektil->bredde = 5;
	
	prosjektil->x_pos = x;
	prosjektil->y_pos = y;
	prosjektil->y_pos_max = skjerm->hoeyde;
	prosjektil->y_pos_min = 0;
		
	return prosjektil;
	
}

int Prosjektil_slett (Prosjektil ** Prosjektil) {

	free(*Prosjektil);
	return 0;
	
}

void Prosjektil_render (Prosjektil * prosjektil) {

	Skjerm * skjerm = ((Spaceinvader*)prosjektil->spaceinvader)->skjerm;		

	SDL_Rect rect;
	
	rect.x = prosjektil->x_pos;
	rect.y = prosjektil->y_pos;
	rect.w = 4;
	rect.h = 8;
		
	SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
	SDL_RenderFillRect (skjerm->ren, &rect);
	
}
	
int Prosjektil_tikk (Prosjektil * prosjektil) {
		
	Skjerm * skjerm = ((Spaceinvader*)prosjektil->spaceinvader)->skjerm;		
	
	int d = 3;
	
	/* Et prosjektil kan bevege seg oppover, type = 0 eller nedover, type = 1*/
	
	if (prosjektil->type == 0) {
	
		prosjektil->y_pos -= d; 
		
		if ( prosjektil->y_pos < 50) {
			return 1; /* Ute av fokus. */
		}
		
	} else if (prosjektil->type == 1){
	
		prosjektil->y_pos += d; 

		if ( prosjektil->y_pos > (skjerm->hoeyde - 50)) {
			return 1; /* Ute av fokus. */
		}
				
	} 
		
	return 0;
}