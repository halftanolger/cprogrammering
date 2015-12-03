/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "kanon.h"

Kanon * Kanon_opprett(void * spaceinvader) {

	Kanon *kanon = (Kanon*)malloc(sizeof(Kanon));
		
	kanon->spaceinvader = spaceinvader;
	
	Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;	
	
	kanon->bredde = 50;
	kanon->hoeyde = 20;
	
	kanon->x_pos = skjerm->bredde / 2;	
	kanon->x_pos_max = skjerm->bredde - (kanon->bredde / 2);	
	kanon->x_pos_min = kanon->bredde / 2;	
			
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		kanon->ild[teller] = NULL;
	}
		
	return kanon;
	
}

int Kanon_slett (Kanon ** kanon) {

	free(*kanon);
	return 0;
	
}

void Kanon_render (Kanon * kanon) {

	Skjerm * skjerm = ((Spaceinvader*)kanon->spaceinvader)->skjerm;		

	SDL_Rect rect;
	
	rect.x = kanon->x_pos - (kanon->bredde/2);
	rect.y = skjerm->hoeyde - 50;
	rect.w = kanon->bredde;
	rect.h = kanon->hoeyde;
		
	SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
	SDL_RenderFillRect (skjerm->ren, &rect);
	
	/* Render ild- givningen. */
	
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		if (kanon->ild[teller] != NULL) {
			Prosjektil * prosjektil = kanon->ild[teller];
			Prosjektil_render (prosjektil);
		}
	}
	
}
	
void Kanon_flytt_til_venstre (Kanon * kanon) {

	int d = 5;

	if (kanon->x_pos > kanon->x_pos_min + d) {
		kanon->x_pos -= d;
	}

}

void Kanon_flytt_til_hoeyre (Kanon * kanon) {

	int d = 5;

	if (kanon->x_pos < (kanon->x_pos_max - d)) {
		kanon->x_pos += d;
	}

}

void Kanon_fyr_av_et_prosjektil (Kanon * kanon) {

	/* Finn neste ledige plass i ild- givningen. */
	
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		if (kanon->ild[teller] == NULL) {
			break;
		}
	}

	if (teller == MAX_ANTALL_PROSJEKTIL) {
		return;
	}
		
	/* Opprett et nytt prosjektilobjekt, og plasser dette i ild- givningen. */

	Spaceinvader * spaceinvader = (Spaceinvader*)kanon->spaceinvader;
	Skjerm * skjerm = spaceinvader->skjerm;	
	int type = 0;
	int x = kanon->x_pos;
	int y = skjerm->hoeyde - 50;
	
	kanon->ild[teller] = Prosjektil_opprett (spaceinvader,type,x,y);
	
}

void Kanon_tikk (Kanon * kanon) {

	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
	
		if (kanon->ild[teller] != NULL) {	
		
			Prosjektil * prosjektil = kanon->ild[teller];			
			
			int r = Prosjektil_tikk (prosjektil);			
			
			/* Om r er lik 1 har prosjektilet gått ut av fokus. */
			
			if ( r == 1) {			
							
				Prosjektil_slett (&prosjektil);
				kanon->ild[teller] = NULL;
				
			}
			
		}
        
	}

}
