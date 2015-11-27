/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#ifndef _SPACEINVADER_H_
#define _SPACEINVADER_H_

#include "skjerm.h"
#include "modell.h"
#include "kontrollsentral.h"

typedef struct spaceinvader_st {
	
	Modell * modell;
	Skjerm * skjerm;
	Kontrollsentral * kontrollsentral;	
	
} Spaceinvader;

Spaceinvader * Spaceinvader_opprett();
int Spaceinvader_spill( Spaceinvader * );
int Spaceinvader_slett( Spaceinvader ** );

#endif // _SPACEINVADER_H_
