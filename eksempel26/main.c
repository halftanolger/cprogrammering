/*
    C -programmering, en innføring. 

    Eksempel 26

*/

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <spaceinvader.h>

int main(int argc, char *argv[]) {

    Spaceinvader *spaceinvader = Spaceinvader_opprett();
		
    Spaceinvader_spill(spaceinvader);
	    
    Spaceinvader_slett(&spaceinvader);
	
    return 0;

}

