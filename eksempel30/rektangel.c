/*
    C -programmering, en innføring. 

    Eksempel 30

*/

#include <stdlib.h>
#include <stdio.h>
#include "rektangel.h"

Rektangel * Rektangel_opprett(int x, int y, int b, int h) {

	Rektangel * rektangel = (Rektangel*)malloc(sizeof(Rektangel));
		
	rektangel->x = x;
	rektangel->y = y;
	rektangel->b = b;
	rektangel->h = h;
			
	return rektangel;
	
}

int Rektangel_slett (Rektangel ** rektangel) {

	free(*rektangel);
	return 0;
	
}

