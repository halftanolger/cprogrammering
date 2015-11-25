/*
    C -programmering, en innføring. 

    Eksempel 29

*/

#include <stdlib.h>
#include "modell.h"

Modell * Modell_opprett(void * spaceinvader) {

	Modell *m = (Modell*)malloc(sizeof(Modell));
	
	if (m == NULL) {
		return NULL;
	}
	
	m->spaceinvader = spaceinvader;
	m->status = STATUS_PAUSE;
	
	m->kanon = Kanon_opprett (spaceinvader);
	
	return m;
	
}

int Modell_slett (Modell ** modell) {

	free(*modell);
	return 0;
	
}
	
