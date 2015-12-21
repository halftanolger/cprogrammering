/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdlib.h>
#include <string.h>
#include "skjerm.h"
#include "spaceinvader.h"
#include "lyd.h"
#include "modell.h"

Modell * Modell_opprett(void * spaceinvader) {

    Modell *modell = (Modell*)malloc(sizeof(Modell));
    
    if (modell == NULL) 
        return NULL;
    
    modell->spaceinvader = spaceinvader;
    
    modell->status = STATUS_PAUSE;
    
    modell->poeng = 0;    
    
    modell->ledigeprosjektil = 0;
    
    modell->tekst_poeng = Tekst_opprett (spaceinvader, "font.ttf", 18);
    
    if (modell->tekst_poeng == NULL) 
        return NULL;
    
    modell->tekst_poeng->x = 10;
    
    modell->tekst_poeng->y = 10;
               
    modell->lyd = Lyd_opprett();
    
    if (modell->lyd == NULL) 
        return NULL;
                  
    modell->ufo_retning = 1;
        
    modell->ufo_tikk_timer = 0;
    
    modell->ufo_fart = 20;
        
    modell->ufoer_ild_timer = 0;
    
    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;
    
    if (skjerm == NULL)
        return NULL;
        
    modell->jord_nivaa = skjerm->hoeyde - 50;
        
    modell->kanon = Kanon_opprett (spaceinvader);
    
    if (modell->kanon == NULL)
        return NULL;
    
    modell->ufoer = Ufoer_opprett (spaceinvader);
    
    if (modell->ufoer == NULL)
        return NULL;
            
    modell->datafil = strdup("toppresultat.dat");        
    
    return modell;
    
}

int Modell_slett (Modell ** modell) {
    
    Kanon_slett(&(*modell)->kanon);
    
    Ufoer_slett(&(*modell)->ufoer);
    
    Lyd_slett(&(*modell)->lyd);
    
    free(*modell);
    
    return 0;
    
}
    
