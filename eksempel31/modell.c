/*
    C -programmering, en innføring. 

    Eksempel 31

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
	
	m->ufoer = Ufoer_opprett (spaceinvader);
	
	return m;
	
}

int Modell_slett (Modell ** modell) {

	free(*modell);
	return 0;
	
}
	
