/*
    C -programmering, en innføring. 

    Eksempel 27

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "modell.h"
#include "spaceinvader.h"
#include "kontrollsentral.h"

Kontrollsentral * Kontrollsentral_opprett(void * spaceinvader) {

	Kontrollsentral *k = (Kontrollsentral*)malloc(sizeof(Kontrollsentral));
	
	if (k == NULL) {
		return NULL;
	}
	
	k->spaceinvader = spaceinvader;
		
	return k;
	
}

int Kontrollsentral_slett (Kontrollsentral ** Kontrollsentral) {

	free(*Kontrollsentral);
	return 0;
	
}

int Kontrollsentral_ferdig (Kontrollsentral * kontrollsentral) {

	Spaceinvader *s = (Spaceinvader*)kontrollsentral->spaceinvader;

	Modell *m = s->modell;
	
	if (m->status == STATUS_STOPP) {
		return 1;
	} else {
		return 0;
	}
	
}