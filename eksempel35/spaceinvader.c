/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "logger.h"
#include "spaceinvader.h"

extern Logger *logg;

Spaceinvader * Spaceinvader_opprett() { 
    
    /* Opprett Spaceinvader-objekt. */
    
    Spaceinvader *spaceinvader = (Spaceinvader*)malloc(sizeof(Spaceinvader));
                    
    if (spaceinvader == NULL) {
        fprintf (stderr, "malloc feilet.");
        return NULL;    
    }
                    
    /* Initier SDL */
    
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        fprintf (stderr, "SDL_Init Error: %s", SDL_GetError());
        return NULL;        
    }
    
    /* Initier TTF */
    
    if (TTF_Init() != 0) {
        printf ("TTF_Init Error: %s", TTF_GetError());
        return NULL;        
    }
    
    /* Opprett skjerm-objekt. */
    
    spaceinvader->skjerm = Skjerm_opprett(spaceinvader);
    
    if (spaceinvader->skjerm == NULL) {
        fprintf (stderr, "Skjerm_opprett feilet.");
        return NULL;
    }

    /* Opprett modell-objekt. */
    
    spaceinvader->modell = Modell_opprett(spaceinvader);
            
    if (spaceinvader->modell == NULL) {
        fprintf (stderr, "Modell_opprett feilet.");
        return NULL;
    }
            
    /* Opprett kontrollsentral-objekt. */            
    
    spaceinvader->kontrollsentral = Kontrollsentral_opprett(spaceinvader);                        

    if (spaceinvader->kontrollsentral == NULL) {
        fprintf (stderr, "Kontrollsentral_opprett() feilet.");
        return NULL;
    }
        
    Kontrollsentral_les_data (spaceinvader->kontrollsentral);    
        
    return spaceinvader;
        
}

int Spaceinvader_spill(Spaceinvader * spaceinvader) { 

    const char * sign = "Spaceinvader_spill(Spaceinvader*)";

    Logger_log (logg, INFO, sign, "start");
    
    Skjerm *s = spaceinvader->skjerm;
    Kontrollsentral *k = spaceinvader->kontrollsentral;
    
    int x = 0;        
    int f = 0;
    SDL_Event e;
    
    while (Kontrollsentral_er_vi_ferdig(k) != 1) {
                    
        /* Sjekk input*/
                        
        while (SDL_PollEvent(&e)){
        
            if (e.type == SDL_QUIT){
                Kontrollsentral_avslutt(k);                
            }
                               
            if (e.type == SDL_KEYDOWN){
            
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        x = -1;
                        break;
                    case SDLK_RIGHT:
                        x = 1;
                        break;        
                    case SDLK_SPACE:
                        f = 1;
                        break;                        
                }
                                                
            } else if (e.type == SDL_KEYUP) {

                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (x == -1) x = 0;
                        break;
                    case SDLK_RIGHT:
                        if (x == 1) x = 0;
                        break;                           
                    case SDLK_SPACE:
                        if (f == 1) f = 0;
                        break;                                                
                }
                       
            }
            
            if (e.type == SDL_MOUSEBUTTONDOWN){
                Kontrollsentral_avslutt(k);                
            }
            
        }        

        if (x == 1) {
            Kontrollsentral_kanon_til_hoeyre(k);                
        } else if (x == -1) {
            Kontrollsentral_kanon_til_venstre(k);                
        }

        if (f == 1) {
            Kontrollsentral_kanon_fyr_av_et_prosjektil(k);
        }

       
        /* Oppdater status */
        
        Kontrollsentral_tikk(k);
                
        /* Rendrer */
    
        Skjerm_render (s);
    
    }
    
    
    Kontrollsentral_skriv_data (k);
    
    /*
    int r = 1;
    while (r) {
        if (SDL_PollEvent(&e)){        
            if (e.type == SDL_QUIT){
                r = 0;                
            }
        }
    }
    */
    
    Logger_log (logg, INFO, sign, "slutt");
    
    return 0; 
    
}

int Spaceinvader_slett( Spaceinvader ** spaceinvader) { 
        
    Skjerm_slett(&((*spaceinvader)->skjerm));
    
    Modell_slett(&((*spaceinvader)->modell));
    
    Kontrollsentral_slett(&((*spaceinvader)->kontrollsentral));
    
    TTF_Quit();
    
    SDL_Quit();
    
    free(*spaceinvader);

    return 0; 
    
}




