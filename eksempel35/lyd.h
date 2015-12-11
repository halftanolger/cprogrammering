/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _LYD_H_
#define _LYD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct lyd_st {
    
    Mix_Chunk * kanonild;
       
} Lyd;

Lyd * Lyd_opprett ();

int Lyd_slett (Lyd **);

void Lyd_generer(int type);

#endif // _LYD_H_