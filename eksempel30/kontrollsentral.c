/*
    C -programmering, en innføring. 

    Eksempel 29

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

	/*
     *	
	 * Eksisterende ild- givning fra kanonen skal tikkes ett steg frem. 
	 *
	 */

	Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
	Modell * modell = spaceinvader->modell;
	Skjerm * skjerm = spaceinvader->skjerm;
	Kanon * kanon = modell->kanon;

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
	 *
	 * Eksisterende ufo'er skal tikkes ett steg frem. 
	 *
	 */

	/* Ufo'ene har varierende fart avhengig av hvor langt vi er kommet. */
	
	if (kontrollsentral->ufo_tikk_timer > 0) {
		kontrollsentral->ufo_tikk_timer--;
		return;
	}	
	kontrollsentral->ufo_tikk_timer = kontrollsentral->ufo_fart;
		
	/* Oppdater plassering */
	
	for (teller = 0; teller < 55; teller++) {		
		Ufo * ufo = modell->ufo[teller];		
		if (kontrollsentral->ufo_retning == 1) {		
			ufo->r->x += 5;						
		} else if (kontrollsentral->ufo_retning == 2) {		
			ufo->r->y += ufo->r->h;									
		} else if (kontrollsentral->ufo_retning == 3) {		
			ufo->r->x -= 5;			
		} else if (kontrollsentral->ufo_retning == 4) {		
			ufo->r->y += ufo->r->h;								
		}			
	}
	
	/* Oppdater retning */
	
	if (kontrollsentral->ufo_retning == 1) {	
		for (teller = 0; teller < 55; teller++) {
			Ufo * ufo = modell->ufo[teller];
			if ((ufo->r->x + ufo->r->b) > (skjerm->bredde - 10) ) {
				kontrollsentral->ufo_retning = 2;
				kontrollsentral->ufo_fart--;
				break;
			}
		}
	} else if (kontrollsentral->ufo_retning == 2) {	
		kontrollsentral->ufo_retning = 3;		
	} else if (kontrollsentral->ufo_retning == 3) {
		for (teller = 0; teller < 55; teller++) {
			Ufo * ufo = modell->ufo[teller];
			if ((ufo->r->x < 10) ) {
				kontrollsentral->ufo_retning = 4;
				kontrollsentral->ufo_fart--;
				break;
			}
		}						
	} else if (kontrollsentral->ufo_retning == 4) {	
		kontrollsentral->ufo_retning = 1;		
	}	
		
		
	//TODO: detekter treff. Detekter kontakt med jorden.
	
	
	/* Generer tilfeldig ild- givning fra eksisterende ufo'er. */
	
	//TODO: alt
}



