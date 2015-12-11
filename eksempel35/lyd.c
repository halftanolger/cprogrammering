/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "spaceinvader.h"
#include "lyd.h"

Lyd * Lyd_opprett(void * spaceinvader) {

    Lyd * lyd = (Lyd*)malloc(sizeof(Lyd));
                 
    lyd->spaceinvader = spaceinvader;
                    
    return lyd;
    
}

int Lyd_slett (Lyd ** lyd) {
    
    free(*lyd);
    
    return 0;
    
}

