/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "spaceinvader.h"
#include "logger.h"
#include "lyd.h"

extern Logger * logg;

Lyd * Lyd_opprett() {

    const char * sign = "Lyd_opprett()";

    Lyd * lyd = (Lyd*)malloc(sizeof(Lyd));
                 
    lyd->kanonild = Mix_LoadWAV( "shot.wav" ); 
    
    if (lyd->kanonild == NULL) { 
    
        char melding[256];
        sprintf(melding,"SDL_mixer Error: %s", Mix_GetError());        
        Logger_log (logg, FEIL, sign, melding);
        return NULL;
        
    }
                 
    return lyd;
    
}

int Lyd_slett (Lyd ** lyd) {
    
    Mix_FreeChunk( (*lyd)->kanonild );
    
    free(*lyd);
    
    return 0;
    
}

void Lyd_generer(Lyd * lyd, int type) {

    const char * sign = "Lyd_generer()";

    Logger_log (logg, INFO, sign, "start");
    
    if (type == 1) {
    
        Logger_log (logg, INFO, sign, "kanonild");
        
        Mix_PlayChannel( -1, lyd->kanonild, 0 );
        
    }

    Logger_log (logg, INFO, sign, "slutt");
    
}
