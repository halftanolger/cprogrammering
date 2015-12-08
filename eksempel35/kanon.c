/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "modell.h"
#include "spaceinvader.h"
#include "rektangel.h"
#include "kanon.h"

Kanon * Kanon_opprett(void * spaceinvader) {

    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;    
    
    Kanon *kanon = (Kanon*)malloc(sizeof(Kanon));
        
    kanon->spaceinvader = spaceinvader;
    
    int x = (skjerm->bredde / 2) - 25;
    int y = skjerm->hoeyde - 50;
    int b = 50;
    int h = 20;    
    kanon->r = Rektangel_opprett (x,y,b,h);
                
    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
        kanon->ild[teller] = NULL;
    }
        
    kanon->tiks = SDL_GetTicks();    
        
    return kanon;
    
}

int Kanon_slett (Kanon ** kanon) {

    free(*kanon);
    return 0;
    
}

void Kanon_render (Kanon * kanon) {

    Skjerm * skjerm = ((Spaceinvader*)kanon->spaceinvader)->skjerm;        

    SDL_Rect rect;
    
    rect.x = kanon->r->x;
    rect.y = kanon->r->y;
    rect.w = kanon->r->b;
    rect.h = kanon->r->h;
        
    SDL_SetRenderDrawColor (skjerm->ren, 200, 200, 200, 255);
    SDL_RenderFillRect (skjerm->ren, &rect);
    
    /* Render ild- givningen. */
    
    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
        if (kanon->ild[teller] != NULL) {
            Prosjektil * prosjektil = kanon->ild[teller];
            Prosjektil_render (prosjektil);
        }
    }
    
}
    
void Kanon_flytt_til_venstre (Kanon * kanon) {

    int d = 5;

    if (kanon->r->x > (d + 10)) {
        kanon->r->x -= d;
    }

}

void Kanon_flytt_til_hoeyre (Kanon * kanon) {

    Spaceinvader * spaceinvader = (Spaceinvader*)kanon->spaceinvader;
    Skjerm * skjerm = spaceinvader->skjerm;

    int d = 5;

    if ((kanon->r->x + kanon->r->b) < (skjerm->bredde - d - 10)) {
        kanon->r->x += d;
    }

}

void Kanon_fyr_av_et_prosjektil (Kanon * kanon) {

    Spaceinvader * spaceinvader = (Spaceinvader*)kanon->spaceinvader;    

    /*
    Uint32 t = SDL_GetTicks();        
    Uint32 d = 150;
    Uint32 g = kanon->tiks + d;
    if ( g > t) {
        return;
    }     
    kanon->tiks = t;
    */
    
    
    /* Finn neste ledige plass i ild- givningen. */
    
    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
        if (kanon->ild[teller] == NULL) {
            break;
        }
    }

    if (teller == MAX_ANTALL_PROSJEKTIL) {
        return;
    }
        
    /* Opprett et nytt prosjektilobjekt, og plasser dette i ild- givningen. */

    int type = 0;
    int x = kanon->r->x + (kanon->r->b / 2);
    int y = kanon->r->y;
    
    kanon->ild[teller] = Prosjektil_opprett (spaceinvader,type,x,y);
    
}

void Kanon_tikk (Kanon * kanon) {

    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
    
        if (kanon->ild[teller] != NULL) {    
        
            Prosjektil * prosjektil = kanon->ild[teller];            
            
            int r = Prosjektil_tikk (prosjektil);            
            
            /* Om r er lik 1 har prosjektilet gått ut av fokus. */
            
            if ( r == 1) {                                        
                Prosjektil_slett (&prosjektil);
                kanon->ild[teller] = NULL;              
            }
            
        }
        
    }

}

void Kanon_sjekk_treff (Kanon * kanon) {

    Spaceinvader * spaceinvader = (Spaceinvader*)kanon->spaceinvader;
    Modell * modell = spaceinvader->modell;

    int teller;
    for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL; teller++) {
    
        if (kanon->ild[teller] != NULL) {    
        
            Prosjektil * prosjektil = kanon->ild[teller];            
            if (prosjektil->status == 1) {
                continue;
            }
            
            /* Såfremt prosjektilet er kommet opp til nederste ufo, må 
               vi begynne å sjekke etter mulige kolisjoner. */    
            
            if (prosjektil->r->y <= modell->ufo_nivaa) {           
                Ufoer * ufoer = modell->ufoer;                                
                int teller2;
                for (teller2 = 54; teller2 >= 0; teller2 --) {
                    Ufo * ufo = ufoer->ufo[teller2];
                    if (ufo->status == 0) {
                        Rektangel * r1 = ufo->r;
                        Rektangel * r2 = prosjektil->r;
                        int b;
                        b = Rektangel_overlapp (r1,r2);
                        if (b == 1) {
                            ufo->status = 1;
                            prosjektil->status = 1;

                            if (ufo->id < 20)
                                modell->poeng+=2;    
                            else 
                                modell->poeng+=1;    
                                
                            break;
                        }
                    }                    
                }      
            }                                    
        }           
    }    
}
