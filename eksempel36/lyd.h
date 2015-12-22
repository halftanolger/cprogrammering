/*
    C -programmering, en innføring. 

    Eksempel 36

*/

#ifndef _LYD_H_
#define _LYD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct lyd_st {
    
    Mix_Chunk * kanonild;
    Mix_Chunk * ufo_treff;
    Mix_Chunk * ufo_ild;
       
} Lyd;

Lyd * Lyd_opprett ();

int Lyd_slett (Lyd **);

void Lyd_generer(Lyd *, int type);

#endif // _LYD_H_