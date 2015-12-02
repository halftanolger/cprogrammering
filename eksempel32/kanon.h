/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#ifndef _KANON_H_
#define _KANON_H_

#define MAX_ANTALL_PROSJEKTIL 100

#include "prosjektil.h"

typedef struct kanon_st {

	void * spaceinvader;
	
	/* Bredden til kanonen. */
	int bredde;
	
	/* Høyden til kanonen. */
	int hoeyde;
	
	/* x- posisjon for midten av kanonen */
	int x_pos;	
	
	/* x- pos. max for midten av kanonen */
	int x_pos_max;
	
	/* x- pos. min for midten av kanonen */
	int x_pos_min;

	Prosjektil * ild[MAX_ANTALL_PROSJEKTIL];
	
} Kanon;

Kanon * Kanon_opprett (void *);

int Kanon_slett (Kanon **);

void Kanon_render (Kanon *);

void Kanon_flytt_til_venstre (Kanon *);

void Kanon_flytt_til_hoeyre (Kanon *);

void Kanon_fyr_av_et_prosjektil (Kanon *);

#endif // _KANON_H_