﻿/*
    C -programmering, en innføring. 

    Eksempel 26

*/

#ifndef _KONTROLLSENTRAL_H_
#define _KONTROLLSENTRAL_H_

typedef struct kontrollsentral_st {

	void * spaceinvader;

} Kontrollsentral;

Kontrollsentral * Kontrollsentral_opprett(void *);
int Kontrollsentral_slett( Kontrollsentral ** );

#endif //_KONTROLLSENTRAL_H_