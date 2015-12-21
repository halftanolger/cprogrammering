/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _MODELL_H_
#define _MODELL_H_

#define STATUS_SPILL 1
#define STATUS_PAUSE 2
#define STATUS_STOPP 3

#include "tekst.h"
#include "kanon.h"
#include "ufoer.h"

typedef struct modell_st {

    void * spaceinvader;

    int status;
    
    int poeng;
    
    int toppresultat;
    
    Tekst * tekst_poeng;
    
    char * datafil;
        
    /*
     * ufo_retning
     *
     * Dette er et flagg som benyttes for å vise hvilken retning ufoene 
     * beveger seg i. Mulige verdier:
     *
     *   1 - høyre 
     *   2 - ned og deretter til venstre
     *   3 - venstre 
     *   4 - ned og deretter til høyre 
     */

    int ufo_retning;

    /*
     * ufo_tikk_timer
     *
     * Ufoene skal bevege seg litt saktere enn prosjektilene. Dette fikser vi
     * ved at vi oppdaterer, eller 'tikker', ufoene færre ganger. Denne 
     * variabelen holder rede på hvor lenge det er igjen til neste gang vi 
     * skal 'tikke frem' ufoene.
     */

    int ufo_tikk_timer;

    /*
     * ufo_fart
     *
     * Ufoene skal også bevege seg hurtigere jo lengre ned de kommer. Denne 
     * variabelen benyttes til å holde rede på den aktuelle farten.
     */

    int ufo_fart;

    /*
     * ufoer_ild_timer
     *
     * Dette er en tilfeldig initiert timer som sørger for tilfeldighet mht 
     * når tid en ufo skal fyre av et prosjektil.
     */
    
    int ufoer_ild_timer;

    /*
     * jord_nivaa
     *
     * Verdien i denne variabelen angir jordnivået, i.e. en y-koordinatverdi.
     * Når en eller flere ufoer kommer ned til dette nivået, er spillet over.
     * Jordnivået defineres til samme høyde som overkanten til kanonen.
     */
    
    int jord_nivaa;

    /*
     * ufo_nivaa
     *
     * Verdien i denne variabelen angir y-koordinatverdien til den laveste
     * ufoen. Årsaken til at denne eksisterer, er fordi det ikke er nødvendig
     * å starte kollisjonsdeteksjon mellom prosjektil fra kanon og ufoer, før
     * prosjektilet fra kanonen når denne høyden.
     */
     
    int ufo_nivaa;
    
    /*
     * kanon
     *
     * Kanonen kan flyttes horisontalt att og frem, ved hjelp av piltastene. 
     *
     * Det er mulig å avfyre et prosjektil ved å trykke på 'space'.
     *
     * Om et prosjektil fra en ufo treffer kanonen, er spillet over.
     */
    
    Kanon * kanon;

    /*
     * ufoer
     *
     * Dette er settet med ufo'er. Disse beveger seg automatisk horisontalt
     * frem og tilbake. 
     *
     * For hver vending kommer de ett hakk nærmere jorden, samt øker 
     * hastigheten litt. 
     *
     * De ufoene som befinner seg i den nederste raden, kan også avfyre 
     * tifeldige prosjektiler mot jorden.
     *
     * Om en ufo når ned til jorden er spillet over. 
     *
     * Om et prosjektil fra kanonen treffer en ufo, forsvinner denne fra 
     * settet av ufoer. 
     *
     * Om alle ufoene blir skutt ned, opprettes det en ny sverm av ufoer.
     */
    
    Ufoer * ufoer;                    

} Modell;

Modell * Modell_opprett(void *);

int Modell_slett( Modell ** );

#endif // _MODELL_H_
