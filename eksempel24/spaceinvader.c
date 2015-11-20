/*
    C -programmering, en innføring. 

    Eksempel 24

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <spaceinvader.h>

Spaceinvader * Spaceinvader_opprett() { 
	
	printf("Spaceinvader_opprett - start\n");

	Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
	
	if (s == NULL) {
		return NULL;
	}

	s->poeng = 0;
	s->resultatliste[0] = 0;
	s->resultatliste[1] = 0;
	s->resultatliste[2] = 0;
	s->status = 0;
	
	printf("Spaceinvader_opprett - slutt\n");
	
	return s;
		
}

int Spaceinvader_spill( Spaceinvader * spaceinvader) { 

	printf("Spaceinvader_spill - her skal det skje!\n");

	return 0; 
	
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 

	printf("Spaceinvader_slett - start\n");

	assert(*spaceinvader != 0);
	free(*spaceinvader);
	
	printf("Spaceinvader_slett - slutt\n");

	return 0; 
	
}

