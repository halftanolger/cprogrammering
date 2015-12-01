/*
    C -programmering, en innføring. 

    Eksempel 31

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "rektangel.h"
#include "ufo.h"
#include "ufoer.h"

Ufoer * Ufoer_opprett(void * spaceinvader) {

	Ufoer *ufoer = (Ufoer*)malloc(sizeof(Ufoer));
		
	ufoer->spaceinvader = spaceinvader;
	
	/* Opprett de 55 ufo'ene */
	
	int teller = 0;
	for (teller = 0; teller < ANTALL_UFOER; teller++) {
		ufoer->ufo[teller] = Ufo_opprett (spaceinvader,teller);
	}
					
	return ufoer;
	
}

int Ufoer_slett (Ufoer ** ufoer) {

	int teller = 0;
	for (teller = 0; teller < ANTALL_UFOER; teller++) {
		Ufo * ufo = (*ufoer)->ufo[teller];
		Ufo_slett (&ufo);
	}

	free(*ufoer);
	return 0;
	
}

void Ufoer_render (Ufoer * ufoer) {

	int teller;
	for (teller = 0; teller < 55; teller++) {		
		Ufo * ufo = ufoer->ufo[teller];		
		Ufo_render (ufo);
	}
		
}

int Ufoer_tikk (Ufoer * ufoer) {

	/*
	 * I denne metoden skjer følgende.	 
	 *	 
	 *
	 * 1. Kontroller hastigheten til ufoene.
	 *
	 * Ufoer_tikk kalles opp ca 60 ganger i sekundet. Ved hjelp av variabelen
	 * kontrollsentral->ufo_tikk_timer reguleres hastigheten mht hvor ofte vi
	 * oppdaterer ufoene.
	 *
	 *
	 * 2. Oppdater plasseringen til ufoene.
	 *
	 * Det er opptil 55 ufoer som skal ha en oppdatert plassering. Hvordan vi 
	 * skal oppdatere plasseringen, er avhengig av hvilken retning ufoene
	 * beveger seg i.
	 *
	 *
	 * 3. Oppdater retningen ufoene beveger seg i.
	 *
	 * Ufoene kan bevege seg mot høyre eller venstre eller nedover. Når ufoene
	 * beveger seg ett nivå ned, skal farten økes. 
	 * 
	 *
	 * Om metoden returnerer 1 har en eller flere ufo nådd jorden, dvs spillet
	 * er slutt. Ellers returneres 0;
	 */


	Spaceinvader *spaceinvader = (Spaceinvader*)ufoer->spaceinvader;
	Kontrollsentral * kontrollsentral = spaceinvader->kontrollsentral;
	Modell * modell = spaceinvader->modell;
	Skjerm * skjerm = spaceinvader->skjerm;


	/* Ufo'ene har varierende fart avhengig av hvor langt vi er kommet. */
	
	if (kontrollsentral->ufo_tikk_timer > 0) {
		kontrollsentral->ufo_tikk_timer--;
		return 0;
	}	
	
	kontrollsentral->ufo_tikk_timer = kontrollsentral->ufo_fart;
		
	/* Oppdater plassering */
	
	int teller;
	for (teller = 0; teller < 55; teller++) {		
		Ufo * ufo = ufoer->ufo[teller];		
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
	
	/* Oppdater retning og eventuelt fart */
	
	if (kontrollsentral->ufo_retning == 1) {	
		for (teller = 0; teller < 55; teller++) {
			Ufo * ufo = ufoer->ufo[teller];
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
			Ufo * ufo = ufoer->ufo[teller];
			if ((ufo->r->x < 10) ) {
				kontrollsentral->ufo_retning = 4;
				kontrollsentral->ufo_fart--;
				break;
			}
		}						
	} else if (kontrollsentral->ufo_retning == 4) {	
		kontrollsentral->ufo_retning = 1;		
	}	


	/* Har noen ufoer nådd jorden? */
	
	for (teller = 0; teller < 55; teller++) {		
		Ufo * ufo = ufoer->ufo[teller];				
		if (ufo->r->y > kontrollsentral->jord_nivaa) {
			kontrollsentral->ufo_jord_kontakt = 1;
			break;
		}		
	}

    return kontrollsentral->ufo_jord_kontakt == 0 ? 0 : 1;
}
	
