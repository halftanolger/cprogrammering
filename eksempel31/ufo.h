/*
    C -programmering, en innføring. 

    Eksempel 31

*/

#ifndef _UFO_H_
#define _UFO_H_

#define MAX_ANTALL_PROSJEKTIL_UFO 10

#include "prosjektil.h"
#include "rektangel.h"

typedef struct ufo_st {

	void * spaceinvader;
	
	/* Hver ufo har en unike id som er med på å definere dens egenskaper
       med hensyn til initiell plassering samt antall poeng ved treff. */
	   
	int id;
	
	/* 0 - ok, 1 - skadet */
	
	int status;
	
	Rektangel * r;
			
	Prosjektil * ild[MAX_ANTALL_PROSJEKTIL_UFO];			
			
} Ufo;

Ufo * Ufo_opprett (void *, int);

int Ufo_slett (Ufo **);

void Ufo_render (Ufo *);

#endif // _Ufo_H_