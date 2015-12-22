/*
    C -programmering, en innføring. 

    Eksempel 36

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "spaceinvader.h"
#include "skjerm.h"
#include "tekst.h"

Tekst * Tekst_opprett(void * spaceinvader, char * font_navn, int size) {

    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;

    Tekst * tekst = (Tekst*)malloc(sizeof(Tekst));
                 
    tekst->spaceinvader = spaceinvader;

    tekst->font=TTF_OpenFont(font_navn, size);
    
    if(!tekst->font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return NULL;
    }    

    strcpy(tekst->melding,"nop");
    
    tekst->x = 0;
    
    tekst->y = 0;
    
    SDL_Color farge = {0,255,0};
    SDL_Surface* surface = TTF_RenderText_Solid( tekst->font, tekst->melding, farge );
    
    if (surface == NULL) {
        printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
        return NULL;        
    }
    
    tekst->bredde = surface->w;
    
    tekst->hoeyde = surface->h;
    
    tekst->texture = SDL_CreateTextureFromSurface( skjerm->ren, surface );
    
    if (tekst->texture == NULL) {
        printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
        return NULL;               
    }
            
    SDL_FreeSurface (surface );
                    
    return tekst;
    
}

int Tekst_slett (Tekst ** tekst) {

    TTF_CloseFont ((*tekst)->font);    

    free(*tekst);
    
    return 0;
    
}

void Tekst_set_melding (Tekst * tekst, char * melding)  {

    Spaceinvader * spaceinvader = (Spaceinvader*)tekst->spaceinvader;
    Skjerm * skjerm = spaceinvader->skjerm;

    strcpy(tekst->melding, melding);
    
    SDL_Color farge = {0,255,0};
    SDL_Surface* surface = TTF_RenderText_Solid( tekst->font, tekst->melding, farge );
    
    if (surface == NULL) {
        printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
        return;        
    }
    
    tekst->bredde = surface->w;    
    
    tekst->hoeyde = surface->h;    
    
	if (tekst->texture != NULL) 
		SDL_DestroyTexture(tekst->texture);

    tekst->texture = SDL_CreateTextureFromSurface( skjerm->ren, surface );
    
    if (tekst->texture == NULL) {
        printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
        return;               
    }            
    
    SDL_FreeSurface (surface );
                            
}

void Tekst_render (Tekst * tekst) {

    Spaceinvader * spaceinvader = (Spaceinvader*)tekst->spaceinvader;
    Skjerm * skjerm = spaceinvader->skjerm;
        
    SDL_Rect rec = {tekst->x,tekst->y,tekst->bredde, tekst->hoeyde};       
    SDL_RenderCopyEx(skjerm->ren, tekst->texture, NULL, &rec, 0, NULL, SDL_FLIP_NONE );
    
}
