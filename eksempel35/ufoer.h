/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _UFOER_H_
#define _UFOER_H_

#define ANTALL_UFOER 55 /* 5 rader à 11 stykker */

#include "ufo.h"

typedef struct ufoer_st {

    void * spaceinvader;
        
    Ufo *ufo[ANTALL_UFOER];
            
} Ufoer;

Ufoer * Ufoer_opprett (void *);

int Ufoer_slett (Ufoer **);

int Ufoer_tikk (Ufoer *);

void Ufoer_fyr_av_et_prosjektil (Ufoer *);
 
void Ufoer_render (Ufoer *);

int Ufoer_sjekk_treff (Ufoer *);

/**
 * Ufoer_sjekk_ny_sverm
 *
 * Om alle ufoene er skutt ned, skal vi generere en ny runde med ufoer. Denne
 * metoden sjekker om alle ufoene er skutt ned eller ikke.
 *
 * Parameter Ufoer* peker til ufo-sverm.
 *
 * Returnerer 1 hvis alle ufoene er skutt ned.
 * Returnerer 0 hvis det eksisterer en eller flere aktive ufoer.
 *
 */
int Ufoer_sjekk_ny_sverm (Ufoer *);

/**
 * Ufoer_ny_sverm
 *
 * Oppretter en ny sverm med ufoer.  
 *
 * Parameter Ufoer* peker til ufo-sverm-objekt.
 *
 */
 void Ufoer_ny_sverm (Ufoer *);


#endif // _UFOER_H_