/*
    C -programmering, en innføring. 

    Eksempel 31

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "modell.h"
#include "spaceinvader.h"
#include "kontrollsentral.h"

Kontrollsentral * Kontrollsentral_opprett(void * spaceinvader) {

	Kontrollsentral *k = (Kontrollsentral*)malloc(sizeof(Kontrollsentral));
		
	k->spaceinvader = spaceinvader;
	
	k->ufo_retning = 1;
		
	k->ufo_tikk_timer = 0;
	
	k->ufo_fart = 20;
	
	k->ufo_jord_kontakt = 0;
	
	k->ufoer_ild_timer = 0;
	
	Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;
    k->jord_nivaa = skjerm->hoeyde - 100;
	
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

void Kontrollsentral_kanon_fyr_av_et_prosjektil(Kontrollsentral * kontrollsentral) {

	Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Kanon * kanon = modell->kanon;
	
	Kanon_fyr_av_et_prosjektil (kanon);

}

void Kontrollsentral_tikk (Kontrollsentral * kontrollsentral) {

	Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Skjerm * skjerm = spaceinvader->skjerm;
	Kanon * kanon = modell->kanon;
	Ufoer * ufoer = modell->ufoer;
	
	/*
	 * Eksisterende ild- givning fra kanonen skal tikkes ett steg frem. 
	 */

	int teller;
	for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
	
		if (kanon->ild[teller] != NULL) {	
		
			Prosjektil * prosjektil = kanon->ild[teller];			
			
			int r = Prosjektil_tikk (prosjektil);			
			
			/* Om r er lik 1 har prosjektilet gått ut av fokus. */
			
			if ( r == 1) {			
							
				Prosjektil_slett (&prosjektil);
				kanon->ild[teller] = NULL;
				
			}
			
		}
	}
						
	/* 
	 * Eksisterende ufo'er skal tikkes ett steg frem. 
	 */

	 int r = Ufoer_tikk (ufoer);
	 
	 /* Om r er lik 1 har en eller flere ufoer nådd jorden. */
	 
	 if (r == 1) {
		modell->status = STATUS_STOPP;
		return;
	 }
	
 	/* 
	 * Generer tilfeldig ild- givning fra eksisterende ufo'er. 
	 */

	 Ufoer_fyr_av_et_prosjektil (ufoer);
		
	/*
	 * Sjekk om noen prosjektiler fra kanonen har truffet en eller flere ufoer.
	 */

	//TODO: 
	 
	/*
	 * Sjekk om noen prosjektiler fra en eller flere ufoer har truffet kanonen.
	 */
	
	//TODO:
		
}



