/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#ifndef _REKTANGEL_H_
#define _REKTANGEL_H_

typedef struct rectangel_st {
    
    int x;
    
    int y;
    
    int b;
    
    int h;
    
} Rektangel;

Rektangel * Rektangel_opprett (int, int, int ,int);

int Rektangel_slett (Rektangel **);

/**
 * Rektangel_overlapp
 *
 * Skal gi svaret på spørsmålet om to rektangler overlapper hverandre.
 *
 * Parameter Rektangel* peker til rektangel 1
 * Parameter Rektangel* peker til rektangel 2 
 *
 * Returnerer 1 såfremt de overlapper hverandre.
 * Returnerer 0 såfremt de ikke overlapper hverandre.
 *
 */
int Rektangel_overlapp (Rektangel *, Rektangel *);

#endif // _REKTANGEL_H_