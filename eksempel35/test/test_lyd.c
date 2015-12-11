/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../logger.h"
#include "../lyd.h"
#include "test_lyd.h"

extern Logger * logg;

int test_lyd() {

    const char * sign = "test_lyd()";
    
    Logger_log (logg, INFO, sign, "start");

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0){
    
        char melding[512];
        sprintf(melding,"SDL_Init Error: %s", SDL_GetError());
        Logger_log (logg, FEIL, sign, melding);        
        return 1;        
        
    }    

    
    Logger_log (logg, INFO, sign, "SDL_Init(SDL_INIT_AUDIO) ok");

    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
    
        char melding[512];
        sprintf(melding,"Mix_OpenAudio: %s", Mix_GetError());        
        Logger_log (logg, FEIL, sign, melding);
		return 1;
        
	}

    
    Lyd *lyd = Lyd_opprett();
    
    Lyd_generer(1);
        
    Lyd_slett(&lyd);
    
    Logger_log (logg, INFO, sign, "slutt");
    
    return 0;

}




