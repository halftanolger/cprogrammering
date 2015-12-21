/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _PROSJEKTIL_H_
#define _PROSJEKTIL_H_

#include "rektangel.h"

typedef struct prosjektil_st {

    void * spaceinvader;
    
    /* Opp (0 - fra kanon) eller ned (1 - fra ufo) */
    
    int type;
    
    /* Status forteller noe om et prosjektil er 'oppbrukt' eller ikke. 
       0 - ok, 1 - oppbrukt */
    
    int status;
    
    /* Rektanglet definerer omkretsen til prosjektilet. */
    
    Rektangel * r;
    
} Prosjektil;

Prosjektil * Prosjektil_opprett (void *, int, int, int);

int Prosjektil_slett (Prosjektil **);

void Prosjektil_render (Prosjektil *);

/**
 * Prosjektil_tikk
 *
 * Hensikten med metoden er å tikke tiden (med sine hendelser) ett steg frem.
 *
 * Parameter Prosjektil* peker til prosjektilobjekt.
 *
 * Returnerer 0 - ok
 * Returnerer 1 - ute av fokus/skjerm
 */ 
int Prosjektil_tikk (Prosjektil *);

#endif // _PROSJEKTIL_H_