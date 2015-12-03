/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#include "../rektangel.h"
#include "test_rektangel.h"

int test_rektangel_overlapp() {

	Rektangel * r1 = Rektangel_opprett (1,1,10,10);
	
	Rektangel * r2 = Rektangel_opprett (1,1,5,5);
	
	int b = Rektangel_overlapp (r1, r2);

	return b == 1 ? 0 : 1;
	
}




