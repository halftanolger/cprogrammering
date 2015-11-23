/*
    C -programmering, en innføring. 

    Eksempel 26

*/

#ifndef _SPACEINVADER_H_
#define _SPACEINVADER_H_

#define STATUS_SPILL 1
#define STATUS_PAUSE 2
#define STATUS_STOPP 3

#include "skjerm.h"
#include "modell.h"
#include "kontrollsentral.h"

typedef struct spaceinvader_st {

    int status;	
	
	Modell * modell;
	Skjerm * skjerm;
	Kontrollsentral * kontrollsentral;	
	
} Spaceinvader;

Spaceinvader * Spaceinvader_opprett();
int Spaceinvader_spill( Spaceinvader * );
int Spaceinvader_slett( Spaceinvader ** );

#endif // _SPACEINVADER_H_
