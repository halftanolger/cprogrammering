/*
    C -programmering, en innføring. 

    Eksempel 24

*/

#include <stdlib.h>
#include <spaceinvader.h>

Spaceinvader * Spaceinvader_opprett() { 
	
	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}

	s->status = 0;
		
	return s;
		
}

void Spaceinvader_spill( Spaceinvader * spaceinvader) { 
		
}

void Spaceinvader_slett( Spaceinvader ** spaceinvader) { 

	free(*spaceinvader);
			
}

