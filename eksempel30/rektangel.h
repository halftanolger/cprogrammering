/*
    C -programmering, en innføring. 

    Eksempel 30

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

#endif // _REKTANGEL_H_