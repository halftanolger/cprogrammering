/*
    C -programmering, en innføring. 

    Eksempel 33

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "prosjektil.h"

Prosjektil * Prosjektil_opprett(void * spaceinvader, int type, int x, int y) {

    Prosjektil *prosjektil = (Prosjektil*)malloc(sizeof(Prosjektil));
        
    prosjektil->spaceinvader = spaceinvader;
    prosjektil->type = type;
    prosjektil->r = Rektangel_opprett(x,y,4,8);
        
    return prosjektil;
    
}

int Prosjektil_slett (Prosjektil ** prosjektil) {
    
    Rektangel_slett(&(*prosjektil)->r);
    free(*prosjektil);
    
    return 0;
    
}

void Prosjektil_render (Prosjektil * prosjektil) {

    if (prosjektil->status == 1) {
        return;
    }

    Spaceinvader * spaceinvader = (Spaceinvader*)prosjektil->spaceinvader;
    Skjerm * skjerm = spaceinvader->skjerm;        

    SDL_Rect rect;
    
    rect.x = prosjektil->r->x;
    rect.y = prosjektil->r->y;
    rect.w = prosjektil->r->b;
    rect.h = prosjektil->r->h;
        
    SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
    SDL_RenderFillRect (skjerm->ren, &rect);
    
}
    
int Prosjektil_tikk (Prosjektil * prosjektil) {
        
    Spaceinvader * spaceinvader = (Spaceinvader*)prosjektil->spaceinvader;    
    Modell * modell = spaceinvader->modell;        
            
    int d = 3;
    
    /* Et prosjektil kan bevege seg oppover, type = 0 eller nedover, type = 1*/
    
    if (prosjektil->type == 0) {
    
        prosjektil->r->y -= d; 
        
        if ( prosjektil->r->y < 10) {
            return 1; /* Ute av fokus. */
        }
        
    } else if (prosjektil->type == 1){
    
        prosjektil->r->y += d; 

        if ( prosjektil->r->y > modell->jord_nivaa) {
            return 1; /* Ute av fokus. */
        }
                
    } 
        
    return 0;
}