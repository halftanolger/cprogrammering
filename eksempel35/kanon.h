/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _KANON_H_
#define _KANON_H_

#define MAX_ANTALL_PROSJEKTIL 10

#include "prosjektil.h"
#include "rektangel.h"

typedef struct kanon_st {

    void * spaceinvader;
    
    /* Rektanglet definerer omkretsen til kanonen. */
    
    Rektangel * r;
    
    /* En kanon kan ha en rekke skudd fyrt av. Disse lever sitt eget liv
	   helt til de treffer en ufo, eller går ut av fokus. */	

    Prosjektil * ild[MAX_ANTALL_PROSJEKTIL];
    
    Uint32 tiks;
    
} Kanon;

Kanon * Kanon_opprett (void *);

int Kanon_slett (Kanon **);

void Kanon_render (Kanon *);

void Kanon_flytt_til_venstre (Kanon *);

void Kanon_flytt_til_hoeyre (Kanon *);

int Kanon_fyr_av_et_prosjektil (Kanon *);

void Kanon_tikk (Kanon *);

void Kanon_sjekk_treff (Kanon *);

#endif // _KANON_H_