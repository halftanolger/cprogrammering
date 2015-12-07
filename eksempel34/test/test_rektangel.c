/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#include "../rektangel.h"
#include "test_rektangel.h"

int test_rektangel_overlapp() {

    /* Disse overlapper hverandre */
    
    Rektangel * r1 = Rektangel_opprett (1,1,10,10);
    Rektangel * r2 = Rektangel_opprett (1,1,5,5);

    int b = Rektangel_overlapp (r1, r2);
    
    if (b != 1) {
        return 1;
    }

    Rektangel_slett(&r1);
    Rektangel_slett(&r2);
    
    /* Disse overlapper ikke hverandre */
    
    r1 = Rektangel_opprett (8,8,10,10);
    r2 = Rektangel_opprett (1,1,5,5);

    b = Rektangel_overlapp (r1, r2);
    
    if (b != 0) {
        return 1;
    }
    
    Rektangel_slett(&r1);
    Rektangel_slett(&r2);
    
    /* Disse overlapper ikke hverandre */
    
    r1 = Rektangel_opprett (8,8,10,10);
    r2 = Rektangel_opprett (1,1,6,6);

    b = Rektangel_overlapp (r1, r2);
    
    if (b != 0) {
        return 1;
    }
    
    Rektangel_slett(&r1);
    Rektangel_slett(&r2);

    /* Disse overlapper hverandre */
    
    r1 = Rektangel_opprett (8,8,10,10);
    r2 = Rektangel_opprett (1,1,7,7);

    b = Rektangel_overlapp (r1, r2);
    
    if (b != 1) {
        return 1;
    }
    
    Rektangel_slett(&r1);
    Rektangel_slett(&r2);
    
    return 0;

}




