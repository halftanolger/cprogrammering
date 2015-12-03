/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "spaceinvader.h"
#include "test/test.h"

int main(int argc, char *argv[]) {

    if (argc == 2) {
        char * p = argv[1];
        if (strcmp(p,"-t") == 0){
            return test_main();
        }
    }

    Spaceinvader *spaceinvader = Spaceinvader_opprett();

    Spaceinvader_spill(spaceinvader);
    
    Spaceinvader_slett(&spaceinvader);

    return 0;

}

