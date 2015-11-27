/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#ifndef _DRONE_H_
#define _DRONE_H_

#define MAX_ANTALL_PROSJEKTIL 100

#include "prosjektil.h"

typedef struct drone_st {

	void * spaceinvader;
	
	/* Bredden til dronen. */
	int bredde;
	
	/* Høyden til dronen. */
	int hoeyde;
	
	/* x- posisjon for midten av dronen */
	int x_pos;	
	
	/* x- pos. max for midten av dronen */
	int x_pos_max;
	
	/* x- pos. min for midten av dronen */
	int x_pos_min;

	Prosjektil * ild[MAX_ANTALL_PROSJEKTIL];
	
} Drone;

Drone * Drone_opprett (void *);

int Drone_slett (Drone **);

void Drone_render (Drone *);

void Drone_flytt_til_venstre (Drone *);

void Drone_flytt_til_hoeyre (Drone *);

void Drone_fyr_av_et_prosjektil (Drone *);


#endif // _DRONE_H_