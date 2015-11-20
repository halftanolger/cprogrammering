/*
    C -programmering, en innføring. 

    Eksempel 21

    Hensikten med eksempelet er å vise hvordan man kan 
    lage et objektorientert design i C

*/

#include <stdio.h>
#include <spill.h>

int main() {

    Spill *spill = Spill_opprett();

    Spill_start(spill);
    Spill_pause(spill);
    Spill_stop(spill);

    Spill_slett(&spill);
    return 0;

}

