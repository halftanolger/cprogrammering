﻿/*
    C -programmering, en innføring. 

    Eksempel 27

*/

#ifndef _KONTROLLSENTRAL_H_
#define _KONTROLLSENTRAL_H_

typedef struct kontrollsentral_st {

	void * spaceinvader;

} Kontrollsentral;

Kontrollsentral * Kontrollsentral_opprett(void *);

/*
 * Medtodenavn: ferdig
 * Hensikt    : Skal gi svaret på spørsmålet: "Er spillet ferdig?"
 * Returnerer : 1 hvis spillet er ferdig, ellers 0.
 */
int Kontrollsentral_ferdig (Kontrollsentral *);

int Kontrollsentral_slett (Kontrollsentral ** );

#endif //_KONTROLLSENTRAL_H_