/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#ifndef _UFO_H_
#define _UFO_H_

#define MAX_ANTALL_PROSJEKTIL_UFO 10
#define ANTALL_UFOER 55 /* 5 rader à 11 stykker */

#include "prosjektil.h"
#include "rektangel.h"

typedef struct ufo_st {

    void * spaceinvader;
    
    /* Hver ufo har en unike id som er med på å definere dens egenskaper
       med hensyn til initiell plassering samt antall poeng ved treff. */
       
    int id;
            
    /* Status forteller noe om en ufo er skutt ned eller ikke. 
       0 - ok, 1 - skadet */
    
    int status;
    
    /* Rektanglet definerer omkretsen til ufoen. */
    
    Rektangel * r;
    
    /* En ufo kan ha en rekke skudd fyrt av. Disse lever sitt eget liv
       helt til de treffer kanonen, eller går ut av fokus. */    
    
    Prosjektil * ild[MAX_ANTALL_PROSJEKTIL_UFO];            
            
} Ufo;

Ufo * Ufo_opprett (void *, int);

int Ufo_slett (Ufo **);

void Ufo_render (Ufo *);

void Ufo_tikk (Ufo *);

void Ufo_tilbakestill (Ufo *, int);

#endif // _Ufo_H_