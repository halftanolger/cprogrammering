/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#include <stdlib.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "rektangel.h"
#include "ufo.h"

Ufo * Ufo_opprett(void * spaceinvader, int id) {

    Ufo *ufo = (Ufo*)malloc(sizeof(Ufo));
        
    ufo->spaceinvader = spaceinvader;
    ufo->id = id;
    ufo->status = 0;

    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL_UFO; teller++) {
        ufo->ild[teller] = NULL;
    }
    
    double rad = (double) (id / 11);
    double indeks = (double) (id % 11);
    
    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;    
    
    double d = (double)skjerm->bredde;
    d = (d * 0.8) / 11.0;
    
    int b = (int)(d * 0.7);
    int h = (int)((d / 2.0) * 0.7);        
    int x = (int)(10.0 + d * indeks);    
    int y = (int)(50.0 + (d / 2.0) * rad); 

    ufo->r = Rektangel_opprett(x,y,b,h);        
                        
    return ufo;
    
}

int Ufo_slett (Ufo ** ufo) {

    free(*ufo);
    return 0;
    
}

void Ufo_render (Ufo * ufo) {

    if (ufo->status == 1) {
        return;
    }

    Skjerm * skjerm = ((Spaceinvader*)ufo->spaceinvader)->skjerm;        

    SDL_Rect rect;
    
    rect.x = ufo->r->x;
    rect.y = ufo->r->y;
    rect.w = ufo->r->b;
    rect.h = ufo->r->h;
    
    /* Gi hver rad av ufo'er sin egen farge. */
    
    int rad = ufo->id / 11;
    
    SDL_SetRenderDrawColor (skjerm->ren,  + (rad * 50), 200, 200, 255);
    SDL_RenderFillRect (skjerm->ren, &rect);
        
    /* Render ild- givningen. */
    
    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL_UFO; teller++) {
        if (ufo->ild[teller] != NULL) {
            Prosjektil * prosjektil = ufo->ild[teller];
            Prosjektil_render (prosjektil);
        }
    }
                        
}
    
void Ufo_tikk (Ufo * ufo) {

    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL_UFO; teller++) {
        if (ufo->ild[teller] != NULL) {            
            Prosjektil * prosjektil = ufo->ild[teller];                        
            int r = Prosjektil_tikk (prosjektil);            
            
            /* Om r er lik 1 har prosjektilet gått ut av fokus. */
            
            if ( r == 1) {                                        
                Prosjektil_slett (&prosjektil);
                ufo->ild[teller] = NULL;                
            }            
        }
    }

}    
