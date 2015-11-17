﻿/*
    C -programmering, en introduksjon. 

    Eksempel 24

    Hensikten med eksempelet er å vise hvordan man kan 
    lage et objektorientert design i C

*/

#include <stdio.h>
#include <spill.h>

int main() {

    Spill *spill = Spill_opprett();

    Spill_start(spill);
    Spill_pause(spill);
    Spill_stopp(spill);

    Spill_slett(&spill);
    return 0;

}

