/*
    C -programmering, en innføring. 

    Eksempel 28

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "kanon.h"

Kanon * Kanon_opprett(void * spaceinvader) {

	Kanon *k = (Kanon*)malloc(sizeof(Kanon));
	
	if (k == NULL) {
		return NULL;
	}
	
	k->spaceinvader = spaceinvader;
	
	Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;	
	
	k->bredde = 50;
	
	k->x_pos = skjerm->bredde / 2;	
	k->x_pos_max = skjerm->bredde - (k->bredde / 2);	
	k->x_pos_min = k->bredde / 2;	
		
	return k;
	
}

int Kanon_slett (Kanon ** kanon) {

	free(*kanon);
	return 0;
	
}

void Kanon_render (Kanon * kanon) {

	Skjerm * skjerm = ((Spaceinvader*)kanon->spaceinvader)->skjerm;		

	SDL_Rect rect;
	
	rect.x = kanon->x_pos - (kanon->bredde/2);
	rect.y =  skjerm->hoeyde - 50;
	rect.w = kanon->bredde;
	rect.h = 20;
		
	SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
	SDL_RenderFillRect (skjerm->ren, &rect);
	
}
	
void Kanon_flytt_til_venstre (Kanon * kanon) {

	int d = 3;

	if (kanon->x_pos > kanon->x_pos_min + d) {
		kanon->x_pos -= d;
	}

}

void Kanon_flytt_til_hoeyre (Kanon * kanon) {

	int d = 3;

	if (kanon->x_pos < (kanon->x_pos_max - d)) {
		kanon->x_pos += d;
	}

}
