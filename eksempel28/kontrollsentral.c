/*
    C -programmering, en innføring. 

    Eksempel 28

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

int Kontrollsentral_er_vi_ferdig (Kontrollsentral * kontrollsentral) {

	Spaceinvader *s = (Spaceinvader*)kontrollsentral->spaceinvader;

	Modell *m = s->modell;
	
	if (m->status == STATUS_STOPP) {
		return 1;
	} else {
		return 0;
	}
	
}

void Kontrollsentral_avslutt (Kontrollsentral * kontrollsentral) {

	Spaceinvader *s = (Spaceinvader*)kontrollsentral->spaceinvader;

	Modell *m = s->modell;
	
	m->status = STATUS_STOPP;

}

void Kontrollsentral_kanon_til_venstre(Kontrollsentral * kontrollsentral) {

	Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Kanon * kanon = modell->kanon;
	
	Kanon_flytt_til_venstre (kanon);
	
}

void Kontrollsentral_kanon_til_hoeyre(Kontrollsentral * kontrollsentral) {

	Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Kanon * kanon = modell->kanon;
	
	Kanon_flytt_til_hoeyre (kanon);

}




