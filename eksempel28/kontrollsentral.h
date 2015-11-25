/*
    C -programmering, en innføring. 

    Eksempel 28

*/

#ifndef _KONTROLLSENTRAL_H_
#define _KONTROLLSENTRAL_H_

typedef struct kontrollsentral_st {

	void * spaceinvader;

} Kontrollsentral;

Kontrollsentral * Kontrollsentral_opprett(void *);

/**
 * Kontrollsentral_er_vi_ferdig
 *
 * Skal gi svaret på spørsmålet: "Er spillet ferdig?"
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 * Returnerer 1 hvis spillet er ferdig.
 * Returnerer 0 hvis spillet ikke er ferdig.
 *
 */
int Kontrollsentral_er_vi_ferdig (Kontrollsentral *);
 
/**
 * Kontrollsentral_avslutt
 *
 * Hensikten med metoden er å avslutte spillet, det vil si gå ut av 
 * spill-løkka (the game loop).
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 */ 
void Kontrollsentral_avslutt (Kontrollsentral *);

void Kontrollsentral_kanon_til_venstre(Kontrollsentral *);	

void Kontrollsentral_kanon_til_hoeyre(Kontrollsentral *);	

int Kontrollsentral_slett (Kontrollsentral ** );

#endif //_KONTROLLSENTRAL_H_