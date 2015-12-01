/*
    C -programmering, en innføring. 

    Eksempel 31

*/

#ifndef _PROSJEKTIL_H_
#define _PROSJEKTIL_H_

typedef struct prosjektil_st {

	void * spaceinvader;
	
	/* Opp (0 - fra kanon) eller ned (1 - fra ufo) */
	int type;
	
	/* Bredden til prosjektilet. */
	int bredde;

	int x_pos;
		
	int y_pos;

	int y_pos_max;

	int y_pos_min;
	

} Prosjektil;

Prosjektil * Prosjektil_opprett (void *, int, int, int);

int Prosjektil_slett (Prosjektil **);

void Prosjektil_render (Prosjektil *);

/**
 * Prosjektil_tikk
 *
 * Hensikten med metoden er å tikke tiden (med sine hendelser) ett steg frem.
 *
 * Parameter Prosjektil* peker til prosjektilobjekt.
 *
 * Returnerer 0 - ok
 * Returnerer 1 - ute av fokus/skjerm
 */ 
int Prosjektil_tikk (Prosjektil *);

#endif // _PROSJEKTIL_H_