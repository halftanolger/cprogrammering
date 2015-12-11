/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _LYD_H_
#define _LYD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct lyd_st {
    
    void * spaceinvader;
       
} Lyd;

Lyd * Lyd_opprett (void *);

int Lyd_slett (Lyd **);

#endif // _LYD_H_