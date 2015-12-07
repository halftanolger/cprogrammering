/*
    C -programmering, en innføring. 

    Eksempel 33

*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "kanon.h"
#include "spaceinvader.h"
#include "tekst.h"
#include "skjerm.h"

Skjerm * Skjerm_opprett(void * spaceinvader) {

    Skjerm *skjerm = (Skjerm*)malloc(sizeof(Skjerm));
        
    skjerm->spaceinvader = spaceinvader;
    
    skjerm->bredde = 640;
    skjerm->hoeyde = 480;
    
    skjerm->win = SDL_CreateWindow("SpaceInvaders", 100, 100, skjerm->bredde, skjerm->hoeyde, SDL_WINDOW_SHOWN);
    
    if (skjerm->win == NULL){
        printf ("SDL_CreateWindow Error: %s", SDL_GetError());
        return NULL;        
    }    
    
    skjerm->ren = SDL_CreateRenderer(skjerm->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (skjerm->ren == NULL){
        printf ("SDL_CreateRenderer Error: %s", SDL_GetError());
        return NULL;        
    }    
        
    SDL_SetRenderDrawColor (skjerm->ren, 0, 0, 0, 255);
    SDL_RenderClear (skjerm->ren);        
    SDL_RenderPresent (skjerm->ren);        
                
    return skjerm;

}

int Skjerm_slett (Skjerm ** skjerm) {
    
    free(*skjerm);
    
    return 0;
    
}


void Skjerm_render (Skjerm * skjerm) {

    Spaceinvader * spaceinvader = skjerm->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    Ufoer * ufoer = modell->ufoer;

    SDL_SetRenderDrawColor (skjerm->ren, 0, 0, 0, 255);
    SDL_RenderClear (skjerm->ren);        

    /* Render kanonen med eventuelle tilhørene prosjektiler. */
    
    Kanon_render (kanon);
    
    /* Render ufo'er med eventuelle tilhørene prosjektiler. */
    
    Ufoer_render (ufoer);
        
        
    Tekst_render (modell->tekst_poeng);    
        
    SDL_RenderPresent(skjerm->ren);
    
}
