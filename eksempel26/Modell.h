﻿/*
    C -programmering, en innføring. 

    Eksempel 26

*/

#ifndef _MODELL_H_
#define _MODELL_H_

typedef struct modell_st {

	void * spaceinvader;

} Modell;

Modell * Modell_opprett(void *);
int Modell_slett( Modell ** );

#endif // _MODELL_H_