/*
    C -programmering, en innføring. 

    Eksempel 36

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
        
    lyd->ufo_treff = Mix_LoadWAV( "alien-hit.wav" ); 
    
    if (lyd->ufo_treff == NULL) {     
        char melding[256];
        sprintf(melding,"SDL_mixer Error: %s", Mix_GetError());        
        Logger_log (logg, FEIL, sign, melding);
        return NULL;        
    }

    lyd->ufo_ild = Mix_LoadWAV( "alien-shot.wav" ); 
    
    if (lyd->ufo_ild == NULL) {     
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
                
        if (Mix_PlayChannel( 0, lyd->kanonild, 0 ) == -1) {
            char melding[256];
            sprintf(melding,"SDL_mixer Error: %s", Mix_GetError());        
            Logger_log (logg, FEIL, sign, melding);            
        }
        
    } else if (type == 2) {
    
        Logger_log (logg, INFO, sign, "ufo_treff");
                
        if (Mix_PlayChannel( 1, lyd->ufo_treff, 0 ) == -1) {
            char melding[256];
            sprintf(melding,"SDL_mixer Error: %s", Mix_GetError());        
            Logger_log (logg, FEIL, sign, melding);            
        }
        
    } else if (type == 3) {
    
        Logger_log (logg, INFO, sign, "ufo_ild");
                
        if (Mix_PlayChannel( 1, lyd->ufo_ild, 0 ) == -1) {
            char melding[256];
            sprintf(melding,"SDL_mixer Error: %s", Mix_GetError());        
            Logger_log (logg, FEIL, sign, melding);            
        }
        
    }
    
    
    Logger_log (logg, INFO, sign, "slutt");
    
}
