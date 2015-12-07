/*
    C -programmering, en innføring. 

    Eksempel 33

*/

#include <stdlib.h>
#include "skjerm.h"
#include "spaceinvader.h"
#include "modell.h"

Modell * Modell_opprett(void * spaceinvader) {

    Modell *m = (Modell*)malloc(sizeof(Modell));
    
    m->spaceinvader = spaceinvader;
    
    m->status = STATUS_PAUSE;
    
    m->poeng = 0;    
    m->tekst_poeng = Tekst_opprett (spaceinvader, "VCR_OSD_MONO.ttf", 18);
    m->tekst_poeng->x = 10;
    m->tekst_poeng->y = 10;
    
    m->ufo_retning = 1;
        
    m->ufo_tikk_timer = 0;
    
    m->ufo_fart = 20;
        
    m->ufoer_ild_timer = 0;
    
    Skjerm * skjerm = ((Spaceinvader*)spaceinvader)->skjerm;
    m->jord_nivaa = skjerm->hoeyde - 50;
        
    m->kanon = Kanon_opprett (spaceinvader);
    
    m->ufoer = Ufoer_opprett (spaceinvader);
            
    return m;
    
}

int Modell_slett (Modell ** modell) {
    
    Kanon_slett(&(*modell)->kanon);
    
    Ufoer_slett(&(*modell)->ufoer);
    
    free(*modell);
    
    return 0;
    
}
    
