/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdlib.h>
#include <string.h>
#include "skjerm.h"
#include "spaceinvader.h"
#include "modell.h"

Modell * Modell_opprett(void * spaceinvader) {

    Modell *modell = (Modell*)malloc(sizeof(Modell));
    
    modell->spaceinvader = spaceinvader;
    
    modell->status = STATUS_PAUSE;
    
    modell->poeng = 0;    
    modell->tekst_poeng = Tekst_opprett (spaceinvader, "font.ttf", 18);
    modell->tekst_poeng->x = 10;
    modell->tekst_poeng->y = 10;
               
    modell->ufo_retning = 1;
        
    modell->ufo_tikk_timer = 0;
    
    modell->ufo_fart = 20;
        
    modell->ufoer_ild_timer = 0;
    
    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;
    modell->jord_nivaa = skjerm->hoeyde - 50;
        
    modell->kanon = Kanon_opprett (spaceinvader);
    
    modell->ufoer = Ufoer_opprett (spaceinvader);
            
    modell->datafil = strdup("toppresultat.dat");        
    
    return modell;
    
}

int Modell_slett (Modell ** modell) {
    
    Kanon_slett(&(*modell)->kanon);
    
    Ufoer_slett(&(*modell)->ufoer);
    
    free(*modell);
    
    return 0;
    
}
    
