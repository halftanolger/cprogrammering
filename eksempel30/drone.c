/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "drone.h"

Drone * Drone_opprett(void * spaceinvader) {

	Drone *drone = (Drone*)malloc(sizeof(Drone));
		
	drone->spaceinvader = spaceinvader;
	
	Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;	
	
	drone->bredde = 50;
	drone->hoeyde = 20;
	
	drone->x_pos = skjerm->bredde / 2;	
	drone->x_pos_max = skjerm->bredde - (drone->bredde / 2);	
	drone->x_pos_min = drone->bredde / 2;	
			
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		drone->ild[teller] = NULL;
	}
		
	return drone;
	
}

int Drone_slett (Drone ** drone) {

	free(*drone);
	return 0;
	
}

void Drone_render (Drone * drone) {

	Skjerm * skjerm = ((Spaceinvader*)drone->spaceinvader)->skjerm;		

	SDL_Rect rect;
	
	rect.x = drone->x_pos - (drone->bredde/2);
	rect.y = skjerm->hoeyde - 50;
	rect.w = drone->bredde;
	rect.h = drone->hoeyde;
		
	SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
	SDL_RenderFillRect (skjerm->ren, &rect);
	
	/* Render ild- givningen. */
	
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		if (drone->ild[teller] != NULL) {
			Prosjektil * prosjektil = drone->ild[teller];
			Prosjektil_render (prosjektil);
		}
	}
	
}
	
void Drone_flytt_til_venstre (Drone * drone) {

	int d = 5;

	if (drone->x_pos > drone->x_pos_min + d) {
		drone->x_pos -= d;
	}

}

void Drone_flytt_til_hoeyre (Drone * drone) {

	int d = 5;

	if (drone->x_pos < (drone->x_pos_max - d)) {
		drone->x_pos += d;
	}

}

void Drone_fyr_av_et_prosjektil (Drone * drone) {

	/* Finn neste ledige plass i ild- givningen. */
	
	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
		if (drone->ild[teller] == NULL) {
			break;
		}
	}

	if (teller == MAX_ANTALL_PROSJEKTIL) {
		return;
	}
		
	/* Opprett et nytt prosjektilobjekt, og plasser dette i ild- givningen. */

	Spaceinvader * spaceinvader = (Spaceinvader*)drone->spaceinvader;
	Skjerm * skjerm = spaceinvader->skjerm;	
	int type = 0;
	int x = drone->x_pos;
	int y = skjerm->hoeyde - 50;
	
	drone->ild[teller] = Prosjektil_opprett (spaceinvader,type,x,y);
	
}
