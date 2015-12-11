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
#include "lyd.h"

Lyd * Lyd_opprett() {

    Lyd * lyd = (Lyd*)malloc(sizeof(Lyd));
                 
                 /*
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) { 
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ); 
        return NULL;
    }*/
                    
    return lyd;
    
}

int Lyd_slett (Lyd ** lyd) {
    
    free(*lyd);
    
    return 0;
    
}

void Lyd_generer(int type) {

}
