/*
    C -programmering, en innføring. 

    Eksempel 21

*/

#include <stdio.h>
#include "spaceinvader.h"

int main() {

    Spaceinvader *spaceinvader = Spaceinvader_opprett();

    Spaceinvader_spill(spaceinvader);
	    
    Spaceinvader_slett(&spaceinvader);
	
    return 0;

}

