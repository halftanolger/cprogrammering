/*
    C -programmering, en innføring. 

    Eksempel 28

*/

#ifndef _KANON_H_
#define _KANON_H_

typedef struct kanon_st {

	void * spaceinvader;
	
	/* Bredden til kanonen. */
	int bredde;
	
	/* x- posisjon for midten av kanonen */
    int x_pos;	
	
	/* x- pos. max for midten av kanonen */
	int x_pos_max;
	
	/* x- pos. min for midten av kanonen */
	int x_pos_min;

} Kanon;

Kanon * Kanon_opprett (void *);

int Kanon_slett (Kanon **);

void Kanon_render (Kanon *);

void Kanon_flytt_til_venstre (Kanon *);

void Kanon_flytt_til_hoeyre (Kanon *);

#endif // _KANON_H_