/*
    C -programmering, en innføring. 

    Eksempel 33

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

void Ufoer_sjekk_treff (Ufoer *);

#endif // _UFOER_H_