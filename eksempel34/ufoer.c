/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "modell.h"
#include "kanon.h"
#include "spaceinvader.h"
#include "rektangel.h"
#include "ufo.h"
#include "ufoer.h"

Ufoer * Ufoer_opprett(void * spaceinvader) {

    Ufoer *ufoer = (Ufoer*)malloc(sizeof(Ufoer));
        
    ufoer->spaceinvader = spaceinvader;
    
    /* Opprett de 55 ufo'ene */
    
    int teller = 0;
    for (teller = 0; teller < ANTALL_UFOER; teller++) {
        ufoer->ufo[teller] = Ufo_opprett (spaceinvader,teller);
    }
    
    /* Benyttes ifm generering av tilfeldig ild-givning fra ufoene. */
    
    time_t t;
    srand((unsigned) time(&t));
    
    return ufoer;
    
}

int Ufoer_slett (Ufoer ** ufoer) {

    int teller = 0;
    for (teller = 0; teller < ANTALL_UFOER; teller++) {
        Ufo * ufo = (*ufoer)->ufo[teller];
        Ufo_slett (&ufo);
    }

    free(*ufoer);
    return 0;
    
}

void Ufoer_render (Ufoer * ufoer) {

    int teller;
    for (teller = 0; teller < 55; teller++) {        
        Ufo * ufo = ufoer->ufo[teller];        
        Ufo_render (ufo);
    }
        
}

int Ufoer_tikk (Ufoer * ufoer) {

    /*
     * I denne metoden skjer følgende.     
     *     
     *
     * 1. Kontroller hastigheten til ufoene.
     *
     * Ufoer_tikk kalles opp ca 60 ganger i sekundet. Ved hjelp av variabelen
     * kontrollsentral->ufo_tikk_timer reguleres hastigheten mht hvor ofte vi
     * oppdaterer ufoene.
     *
     *
     * 2. Oppdater plasseringen til ufoene.
     *
     * Det er opptil 55 ufoer som skal ha en oppdatert plassering. Hvordan vi 
     * skal oppdatere plasseringen, er avhengig av hvilken retning ufoene
     * beveger seg i.
     *
     *
     * 3. Oppdater retningen ufoene beveger seg i.
     *
     * Ufoene kan bevege seg mot høyre eller venstre eller nedover. Når ufoene
     * beveger seg ett nivå ned, skal farten økes. 
     * 
     *
     * Om metoden returnerer 1 har en eller flere ufo nådd jorden, dvs spillet
     * er slutt. Ellers returneres 0;
     */

    Spaceinvader *spaceinvader = (Spaceinvader*)ufoer->spaceinvader;    
    Modell * modell = spaceinvader->modell;
    Skjerm * skjerm = spaceinvader->skjerm;
    
    /* Oppdater eventuell eksisterende ild-givning fra ufoene. */
    
    int teller;
    for (teller = 0; teller < 55; teller++) {        
        Ufo * ufo = ufoer->ufo[teller];        
        Ufo_tikk (ufo);
    }    
        
    /* Ufo'ene har varierende fart avhengig av hvor langt vi er kommet. */
    
    if (modell->ufo_tikk_timer > 0) {
        modell->ufo_tikk_timer--;
        return 0;
    }    
    
    modell->ufo_tikk_timer = modell->ufo_fart;
        
    /* Oppdater plassering */
        
    for (teller = 0; teller < 55; teller++) {        
        Ufo * ufo = ufoer->ufo[teller];        
        if (modell->ufo_retning == 1) {        
            ufo->r->x += 5;                        
        } else if (modell->ufo_retning == 2) {        
            ufo->r->y += ufo->r->h;                                    
        } else if (modell->ufo_retning == 3) {        
            ufo->r->x -= 5;            
        } else if (modell->ufo_retning == 4) {        
            ufo->r->y += ufo->r->h;            
        } 

        /* Benyttes ifm kollisjonsdeteksjon. */
        if (ufo->r->y > modell->ufo_nivaa) {
            modell->ufo_nivaa = ufo->r->y;
        }
        
    }
    
    /* Oppdater retning og eventuelt fart */
    
    if (modell->ufo_retning == 1) {    
        for (teller = 0; teller < 55; teller++) {
            Ufo * ufo = ufoer->ufo[teller];
            if ((ufo->r->x + ufo->r->b) > (skjerm->bredde - 10) ) {
                modell->ufo_retning = 2;
                modell->ufo_fart--;
                break;
            }
        }
    } else if (modell->ufo_retning == 2) {    
        modell->ufo_retning = 3;        
    } else if (modell->ufo_retning == 3) {
        for (teller = 0; teller < 55; teller++) {
            Ufo * ufo = ufoer->ufo[teller];
            if ((ufo->r->x < 10) ) {
                modell->ufo_retning = 4;
                modell->ufo_fart--;
                break;
            }
        }                        
    } else if (modell->ufo_retning == 4) {    
        modell->ufo_retning = 1;        
    }    

    /* Har noen ufoer nådd jorden? */
    
    int jord_kontakt = 0;
    for (teller = 0; teller < 55; teller++) {        
        Ufo * ufo = ufoer->ufo[teller];                
        if (ufo->r->y > modell->jord_nivaa) {
            jord_kontakt = 1;
            break;
        }        
    }

    return jord_kontakt;
    
}


void Ufoer_fyr_av_et_prosjektil (Ufoer * ufoer) {

    Spaceinvader * spaceinvader = (Spaceinvader*)ufoer->spaceinvader;
    Modell * modell = spaceinvader->modell;
    
    /* Aller først, sjekk at vi har èn eller flere aktive ufoer. */
    
    int har_ufo = 0;
    int teller = 0;
    for (teller = 0; teller < ANTALL_UFOER; teller++) {    
        Ufo * ufo = ufoer->ufo[teller];
        if (ufo->status == 0) {
            har_ufo = 1;
            break;
        }    
    }
        
    if (har_ufo == 0) {
        return;
    }
    
    /* Fyr av et skudd fra en tilfeldig ufo i den nederste raden. */
        
    int rader = 0; /* Rader 1,2,3,4,5 */
    int indeks = 0; /* Indeks 1,2,3,4,5,6,7,8,9,10,11 */
    int ild_indeks = 0;
    
    for (rader = 4; rader >= 0; rader--) {
    
        /* Finn ut hva som er nederste rad. */
        
        int f = 0;
        int s[11] = {0};        
        for (indeks = 11; indeks >= 1; indeks--) {                    
            Ufo * ufo = ufoer->ufo[(rader * 11) + indeks - 1];        
            s[indeks] = ufo->status;        
            if (f == 0 && ufo->status == 0) {
                f = 1;
            }
        }

        if (f == 1) {        
        
            /* Velg tilfeldig ufo i nederste rad. */            
            
            int ikke_ferdig = 1;
            while (ikke_ferdig == 1) {        
                int i = rand()%11;                        
                if (s[i] == 0) {
                    ild_indeks = (rader * 11) + i - 1;
                    ikke_ferdig = 0;
                }                
            }            
            break;        
        }
        
    }

    /* En tilfeldig initiert timer sørger for tilfeldighet mht tid. */
    
    if (modell->ufoer_ild_timer == 0) {
                                
        modell->ufoer_ild_timer = rand()%300;

        Ufo * ufo = ufoer->ufo[ild_indeks];
        
        int teller;
        for (teller = 0; teller < MAX_ANTALL_PROSJEKTIL_UFO; teller++) {
            if (ufo->ild[teller] == NULL) {
                break;
            }    
        }
        if (teller == MAX_ANTALL_PROSJEKTIL_UFO) {
            return;
        }
                
        /* Opprett et nytt prosjektilobjekt, og plasser det i ild- givningen. */

        int type = 1;
        int x = ufo->r->x + (ufo->r->b / 2);
        int y = ufo->r->y + ufo->r->h;
    
        ufo->ild[teller] = Prosjektil_opprett (spaceinvader,type,x,y);
                
    } else {
        
        modell->ufoer_ild_timer--;    
    
    }

}

void Ufoer_sjekk_treff (Ufoer * ufoer) {

    Spaceinvader * spaceinvader = (Spaceinvader*)ufoer->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    
    int teller;
    for (teller = 54; teller >= 0; teller --) {
    
        Ufo * ufo = ufoer->ufo[teller];
        if (ufo->status == 1) {
            continue;
        }        
        
        int teller2;
        for (teller2 = 0; teller2 < MAX_ANTALL_PROSJEKTIL_UFO; teller2++) {
        
            Prosjektil * prosjektil = ufo->ild[teller2];
            if (prosjektil == NULL) {
                continue;
            }
        
            if ((prosjektil->r->y + prosjektil->r->h) >= kanon->r->y) {   
            
                Rektangel * r1 = prosjektil->r;
                Rektangel * r2 = kanon->r;
                int b;
                b = Rektangel_overlapp (r1,r2);
                
                if (b == 1) {
                
                    modell->status = STATUS_STOPP;
                    return;
                    
                }
                
            }   
            
        }   
                
    }

}

int Ufoer_sjekk_ny_sverm (Ufoer * ufoer) {

    int ny_runde = 1;       
    int teller = 0;
    
    for (teller = 0; teller < 55; teller++) {
        Ufo * ufo = ufoer->ufo[teller];                                          
        if (ufo->status == 0) { /* 0 - ok, 1 - skadet eller skutt ned */
            ny_runde = 0;
            break;
        }
    }
        
    return ny_runde;
    
}

void Ufoer_ny_sverm (Ufoer * ufoer) {
    
    int teller = 0;    
    for (teller = 0; teller < 55; teller ++) {
        Ufo * ufo = ufoer->ufo[teller];                                                  
        Ufo_tilbakestill (ufo, teller);        
    }
                
}

