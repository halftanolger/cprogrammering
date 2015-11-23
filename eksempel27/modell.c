/*
    C -programmering, en innføring. 

    Eksempel 27

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
	
	return m;
	
}

int Modell_slett (Modell ** modell) {

	free(*modell);
	return 0;
	
}
	
