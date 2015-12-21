/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _KONTROLLSENTRAL_H_
#define _KONTROLLSENTRAL_H_

typedef struct kontrollsentral_st {

    void * spaceinvader;
    
} Kontrollsentral;

Kontrollsentral * Kontrollsentral_opprett(void *);

int Kontrollsentral_slett (Kontrollsentral ** );

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

/**
 * Kontrollsentral_kanon_til_venstre
 *
 * Hensikten med metoden er å flytte kanonen et steg til venstre.
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 */ 
void Kontrollsentral_kanon_til_venstre(Kontrollsentral *);    

/**
 * Kontrollsentral_kanon_til_hoeyre
 *
 * Hensikten med metoden er å flytte kanonen et steg til høyre.
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 */ 
void Kontrollsentral_kanon_til_hoeyre(Kontrollsentral *);    

/**
 * Kontrollsentral_kanon_fyr_av_et_prosjektil
 *
 * Hensikten med metoden er å fyre av et skudd fra kanonen.
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 */ 
void Kontrollsentral_kanon_fyr_av_et_prosjektil(Kontrollsentral *);    

/**
 * Kontrollsentral_tikk
 *
 * Hensikten med metoden er å tikke tiden (med sine hendelser) ett steg frem.
 *
 * Parameter Kontrollsentral* peker til kontrollobjekt.
 *
 */ 
void Kontrollsentral_tikk (Kontrollsentral *);    

void Kontrollsentral_les_data (Kontrollsentral *);    

void Kontrollsentral_skriv_data (Kontrollsentral *);    

#endif //_KONTROLLSENTRAL_H_