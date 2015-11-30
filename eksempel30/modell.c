/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#include <stdlib.h>
#include "modell.h"

Modell * Modell_opprett(void * spaceinvader) {

	Modell *m = (Modell*)malloc(sizeof(Modell));
	
	m->spaceinvader = spaceinvader;
	m->status = STATUS_PAUSE;

    /*	Opprett kanonen. */
	
	m->kanon = Kanon_opprett (spaceinvader);
	
	/* Opprett de 55 ufo'ene */
	
	int teller = 0;
	for (teller = 0; teller < 55; teller++) {
		m->ufo[teller] = Ufo_opprett (spaceinvader,teller);
	}
	
	return m;
	
}

int Modell_slett (Modell ** modell) {

	free(*modell);
	return 0;
	
}
	
