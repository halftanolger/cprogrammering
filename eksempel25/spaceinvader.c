/*
    C -programmering, en innføring. 

    Eksempel 25

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <spaceinvader.h>


static int initier();
static int sjekk_input();
static int oppdater_spillstatus();
static int render();
static int rydd_opp();

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
	
	s->status = STATUS_PAUSE;
	
	printf("Spaceinvader_opprett - slutt\n");
	
	return s;
		
}

int Spaceinvader_spill( Spaceinvader * spaceinvader) { 

	initier();
	
	while ( status != STATUS_STOPP) {
		sjekk_input();
		oppdater_spillstatus();
		render();
	}
	
	rydd_opp();
	
	return 0; 
	
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 

	printf("Spaceinvader_slett - start\n");

	assert(*spaceinvader != 0);
	free(*spaceinvader);
	
	printf("Spaceinvader_slett - slutt\n");

	return 0; 
	
}




static int initier() { return 0;}
static int sjekk_input() { return 0;}
static int oppdater_spillstatus() { return 0;}
static int render() { return 0;}
static int rydd_opp() { return 0;}


