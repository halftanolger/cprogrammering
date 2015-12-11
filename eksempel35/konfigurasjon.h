/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _KONFIGURASJON_H_
#define _KONFIGURASJON_H_

typedef struct konfigurasjon_st {
    
    char * filnavn;
    
    char * logg_aktiv;

    char * logg_nivaa;

    char * logg_filnavn;

    char * test_aktiv;
    
} Konfigurasjon;

Konfigurasjon * Konfigurasjon_opprett (const char *);

void Konfigurasjon_slett (Konfigurasjon **);

#endif // _KONFIGURASJON_H_