/*
    C -programmering, en innføring. 

    Eksempel 26

*/

//#define SDL_MAIN_HANDLED

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

