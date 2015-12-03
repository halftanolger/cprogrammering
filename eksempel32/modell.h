/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#ifndef _MODELL_H_
#define _MODELL_H_

#define STATUS_SPILL 1
#define STATUS_PAUSE 2
#define STATUS_STOPP 3

#include "kanon.h"
#include "ufoer.h"

typedef struct modell_st {

	void * spaceinvader;

        int status;
	int poeng;
	int resultatliste[3];

	/*
         * ufo_retning
         *
         * Dette er et flagg som benyttes for å vise hvilken retning ufoene 
         * beveger seg i. Mulige verdier:
         *
         *   1 - høyre 
         *   2 - ned og deretter til venstre
         *   3 - venstre 
         *   4 - ned od deretter til høyre 
         */

	int ufo_retning;

	/*
         * ufo_tikk_timer
         *
         * Ufoene skal bevege seg litt saktere enn prosjektilene. Dette fikser vi
         * ved at vi oppdaterer, eller 'tikker', ufoene færre ganger. Denne 
         * variabelen holder rede på hvor lenge det er igjen til neste gang vi 
         * skal 'tikke frem' ufoene.
         */

	int ufo_tikk_timer;

	/*
         * ufo_fart
         *
         * Ufoene skal også bevege seg hurtigere jo lengre ned de kommer. Denne 
         * variabelen benyttes til å holde rede på den aktuelle farten.
         */

	int ufo_fart;

	int ufoer_ild_timer;

        int jord_nivaa;


	Kanon * kanon;

	Ufoer * ufoer;

} Modell;

Modell * Modell_opprett(void *);

int Modell_slett( Modell ** );

#endif // _MODELL_H_
