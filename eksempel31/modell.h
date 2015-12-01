/*
    C -programmering, en innføring. 

    Eksempel 31

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

	Kanon * kanon;
	Ufoer * ufoer;
	
} Modell;

Modell * Modell_opprett(void *);

int Modell_slett( Modell ** );

#endif // _MODELL_H_