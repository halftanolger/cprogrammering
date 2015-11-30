/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#ifndef _UFO_H_
#define _UFO_H_

#include "prosjektil.h"
#include "rektangel.h"

typedef struct ufo_st {

	void * spaceinvader;
	
	/* Hver ufo har en unike id som er med på å definere dens egenskaper
       med hensyn til initiell plassering samt antall poeng ved treff. */
	int id;
	
	Rektangel * r;
			
} Ufo;

Ufo * Ufo_opprett (void *, int);

int Ufo_slett (Ufo **);

void Ufo_render (Ufo *);

#endif // _Ufo_H_