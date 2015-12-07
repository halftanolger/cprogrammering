/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "spaceinvader.h"


Spaceinvader * Spaceinvader_opprett() { 
    
    /* Opprett Spaceinvader-objekt. */
    
    Spaceinvader *s = (Spaceinvader*)malloc(sizeof(Spaceinvader));
                    
    /* Initier SDL */
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf ("SDL_Init Error: %s", SDL_GetError());
        return NULL;        
    }
    
    /* Initier TTF */
    
    if (TTF_Init() != 0) {
        printf ("TTF_Init Error: %s", TTF_GetError());
        return NULL;        
    }
    
    /* Opprett skjerm-objekt. */
    
    s->skjerm = Skjerm_opprett(s);
    
    if (s->skjerm == NULL) {
        printf ("Skjerm_opprett Error: Systemfeil.");
        return NULL;
    }
    
    s->modell = Modell_opprett(s);
            
    s->kontrollsentral = Kontrollsentral_opprett(s);                        

    return s;
        
}

int Spaceinvader_spill(Spaceinvader * spaceinvader) { 

    if (spaceinvader == NULL) {
        return 1;
    }

    Skjerm *s = spaceinvader->skjerm;
    Kontrollsentral *k = spaceinvader->kontrollsentral;
    
    while (Kontrollsentral_er_vi_ferdig(k) != 1) {
    
        SDL_Event e;
        
        /* Sjekk input*/
        
        while (SDL_PollEvent(&e)){
        
            if (e.type == SDL_QUIT){
                Kontrollsentral_avslutt(k);                
            }
              
            //DENNE LOGIKKEN ER FEIL, REF:
            //https://www.libsdl.org/release/SDL-1.2.15/docs/html/guideinputkeyboard.html
                 
            if (e.type == SDL_KEYDOWN){
            
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        Kontrollsentral_kanon_til_venstre(k);                
                        break;
                    case SDLK_RIGHT:
                        Kontrollsentral_kanon_til_hoeyre(k);                
                        break;        
                    case SDLK_SPACE:
                        Kontrollsentral_kanon_fyr_av_et_prosjektil(k);
                        break;                        
                }
                                                
            }    
                    
            if (e.type == SDL_MOUSEBUTTONDOWN){
                Kontrollsentral_avslutt(k);                
            }
            
        }        
        
        /* Oppdater status */
        
        Kontrollsentral_tikk(k);
                
        /* Rendrer */
    
        Skjerm_render (s);
    
    }

    return 0; 
    
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 
    
    if (*spaceinvader == NULL) {
        return 1;
    }
    
    Skjerm_slett(&((*spaceinvader)->skjerm));
    
    TTF_Quit();
    SDL_Quit();
    
    free(*spaceinvader);

    return 0; 
    
}




