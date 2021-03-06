﻿/*
    C -programmering, en innføring. 

    Eksempel 25

    Hensikten med eksempelet er å vise hvordan man kan 
    lage et objektorientert design i C

*/

#include <stdio.h>
#include <spaceinvader.h>

int main() {

    Spaceinvader *spaceinvader = Spaceinvader_opprett();
	
    if (spaceinvader == NULL) {
        return 1;
    }
    
    Spaceinvader_spill(spaceinvader);
	    
    Spaceinvader_slett(&spaceinvader);
	
    return 0;

}

