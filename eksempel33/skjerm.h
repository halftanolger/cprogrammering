﻿/*
    C -programmering, en innføring. 

    Eksempel 33

*/

#ifndef _SKJERM_H_
#define _SKJERM_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct skjerm_st {

    void * spaceinvader;

    int bredde;
    
    int hoeyde;
    
    SDL_Window * win;
    
    SDL_Renderer * ren;
    
    SDL_Texture * tex;         
    
    TTF_Font * font;
    
} Skjerm;

Skjerm * Skjerm_opprett (void *);

void Skjerm_render( Skjerm * );

int Skjerm_slett( Skjerm ** );

#endif // _SKJERM_H_