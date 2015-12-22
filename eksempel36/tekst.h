/*
    C -programmering, en innføring. 

    Eksempel 36

*/

#ifndef _TEKST_H_
#define _TEKST_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct tekst_st {
    
    void * spaceinvader;
    
    TTF_Font * font;
        
    SDL_Texture * texture;        
   
    int bredde;
    
    int hoeyde;
    
    int x;
    
    int y;
    
    char melding[256];
   
} Tekst;

Tekst * Tekst_opprett (void *, char *, int);

int Tekst_slett (Tekst **);

void Tekst_set_melding (Tekst *, char *);

void Tekst_render (Tekst *);

#endif // _TEKST_H_