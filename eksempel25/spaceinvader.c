/*
    C -programmering, en innføring. 

    Eksempel 25

*/

#include <stdio.h>
#include <stdlib.h>
#include <spaceinvader.h>

Spaceinvader * Spaceinvader_opprett() { 
	
	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}

	s->poeng = 0;	
	s->status = STATUS_PAUSE;
		
	return s;
		
}

int Spaceinvader_spill( Spaceinvader * spaceinvader) { 
		
	while ( spaceinvader->status != STATUS_STOPP) {
	
		/* Sjekk input */
		
		/* Oppdater spillstatus */
		
		/* Render */
		
	}
	
	return 0; 
	
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 
	
	free(*spaceinvader);
	
	return 0; 
	
}


