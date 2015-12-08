/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "modell.h"
#include "spaceinvader.h"
#include "kontrollsentral.h"

Kontrollsentral * Kontrollsentral_opprett(void * spaceinvader) {

    Kontrollsentral *k = (Kontrollsentral*)malloc(sizeof(Kontrollsentral));        
    
    k->spaceinvader = spaceinvader;        
    
    return k;
    
}

int Kontrollsentral_slett (Kontrollsentral ** Kontrollsentral) {

    free(*Kontrollsentral);
    
    return 0;
    
}

int Kontrollsentral_er_vi_ferdig (Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell *modell = spaceinvader->modell;
    
    if (modell->status == STATUS_STOPP) {
        return 1;
    } else {
        return 0;
    }
    
}

void Kontrollsentral_avslutt (Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell *modell = spaceinvader->modell;
    
    modell->status = STATUS_STOPP;

}

void Kontrollsentral_kanon_til_venstre(Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    
    Kanon_flytt_til_venstre (kanon);
    
}

void Kontrollsentral_kanon_til_hoeyre(Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    
    Kanon_flytt_til_hoeyre (kanon);

}

void Kontrollsentral_kanon_fyr_av_et_prosjektil(Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    
    Kanon_fyr_av_et_prosjektil (kanon);

}

void Kontrollsentral_tikk (Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;
    Kanon * kanon = modell->kanon;
    Ufoer * ufoer = modell->ufoer;
        
    /* Eksisterende ild- givning fra kanonen skal tikkes ett steg frem. */
    
    Kanon_tikk (kanon);
                            
    /* Eksisterende ufo'er skal tikkes ett steg frem. Om r er lik 1 har en 
       eller flere ufoer nådd jorden. */

    int r = Ufoer_tikk (ufoer);
              
    if (r == 1) {
        fprintf(stdout, "Kontrollsentral_tikk: r==1, ufo har nådd jorden");
        modell->status = STATUS_STOPP;
        return;
    }
    
    /* Generer tilfeldig ild- givning fra eksisterende ufo'er.  */

    Ufoer_fyr_av_et_prosjektil (ufoer);
            
    /* Sjekk om noen prosjektiler fra kanonen har 
       truffet en eller flere ufoer. */
         
	Kanon_sjekk_treff (kanon);
    
    /* Sjekk om kanonen har skutt ned alle ufoene, i så fall må vi lage
       en ny sverm. */
       
    r = Ufoer_sjekk_ny_sverm (ufoer);
    
    if (r == 1) {
        Ufoer_ny_sverm (ufoer);
    }
            
    /* Sjekk om noen prosjektiler fra en eller flere ufoer har 
       truffet kanonen. */
    
    r = Ufoer_sjekk_treff (ufoer);
    
    if (r == 1) {
        fprintf(stdout, "Kontrollsentral_tikk: r==1, ufo har truffet kanon");
        modell->status = STATUS_STOPP;
        return;
    }
    
        
    /* Skriv ut på skjermen hvor mange poeng som er oppnådd. */
    
    char buff[128];
    sprintf(buff,"POENG %.4d TOPP %.4d",modell->poeng,modell->toppresultat);
    Tekst_set_melding (modell->tekst_poeng, buff);
            
}

void Kontrollsentral_les_data (Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;

    FILE * f = fopen (modell->datafil, "r");
    
    if (f == NULL) {
        fprintf(stderr,"Klarer ikke å lese fra fila %s\n",modell->datafil);
        return;
    }
    
    int p;
    
    size_t sz = fread(&p, sizeof(int), 1, f);
    
    if (sz != 1) {
        return;
    }
    
    modell->toppresultat = p;
        
    fclose(f);
 
}

void Kontrollsentral_skriv_data (Kontrollsentral * kontrollsentral) {

    Spaceinvader *spaceinvader = (Spaceinvader*)kontrollsentral->spaceinvader;
    Modell * modell = spaceinvader->modell;

    FILE * f = fopen(modell->datafil,"w");
    
    if (f == NULL) {
        fprintf(stderr,"Klarer ikke å skrive til fila %s\n",modell->datafil);
        return;
    }
    
    if (modell->poeng > modell->toppresultat) {
        modell->toppresultat = modell->poeng;
    }
    
    int p = modell->toppresultat;
    
    fwrite(&p, sizeof(int), 1, f);
    
    fflush(f);
    
    fclose(f);
    
}


