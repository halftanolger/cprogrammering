/*
    C -programmering, en innføring. 

    Eksempel 40

    Hensikten med eksempelet er å vise et mer eller mindre komplett
    dataprogram som løser en konkret oppgave. I dette tilfellet er den 
    primære oppgaven som løses det å beregne anvendt tid, på et skirenn, og 
    ut fra dette, generere ei resultatliste.

*/

#include <stdio.h>
#include <string.h>
#include "main.h"

struct deltaker deltakere[MAX_ANTALL];

int main (int argc, char* argv[]) {
    
    int valg = 0;
    
    init();
    
    do {
        
        valg = meny();
        
        if (valg == 1) 
            registrer_deltaker();
                 
        if (valg == 2) 
            slett_deltaker();
        
        if (valg == 3) 
            registrer_starttid();

        if (valg == 4) 
            registrer_sluttid();

        if (valg == 5) 
            vis_deltakerliste();

        if (valg == 6) 
            vis_resultatliste();

        
    } while (valg != 0);    
    
    return 0;
}

void init() {
    
    int teller = 0;
    
    /* Nullstill alle deltaker-variablene */
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {
        
        deltakere[teller].nummer = 0;
        
        strcpy(deltakere[teller].navn,"nop");
        
        deltakere[teller].starttid.time = 0;
        deltakere[teller].starttid.minutt = 0;
        deltakere[teller].starttid.sekund = 0;
        
        deltakere[teller].sluttid.time = 0;
        deltakere[teller].sluttid.minutt = 0;
        deltakere[teller].sluttid.sekund = 0;
        
    }
    
}

int meny() {
    
    int v = 0;
    
    abc:
    
    printf("\n\n == SkiData == \n\n");
    printf(" 0 - avslutt \n");
    printf(" 1 - registrer deltaker \n");
    printf(" 2 - slett deltaker \n");
    printf(" 3 - registrer start-tid på deltaker \n");
    printf(" 4 - registrer slutt-tid på deltaker \n");
    printf(" 5 - vis deltakerliste \n");
    printf(" 6 - vis resultatliste \n\n");    
    printf(" Velg: ");
    
    scanf("%1d",&v);
    
    if (v < 0 || v > 6) goto abc;
    
    return v;
    
}

int registrer_deltaker() {
    
    int nummer,teller = 0;
    char fornavn[30] = "";
    char etternavn[30] = "";
        
    /* Ta i mot innputt. */
    
    printf("\n\n Registrer deltaker \n\n");
    printf(" nummer   : ");
    scanf("%2d",&nummer);
    printf(" fornavn  : ");
    scanf("%30s",fornavn);
    printf(" etternavn: ");
    scanf("%30s",etternavn);
     
    /* Sjekk om nummeret er ledig. */

    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer == nummer) {            
            printf("\n\n Feilmelding: nummeret er allerede registrert. \n\n");
            return 1;
        }        
    }
    
    /* Sjekk om vi har plass til en deltaker til. */

    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer == 0) {    
            deltakere[teller].nummer = nummer;
            strcpy(deltakere[teller].navn, strcat(strcat(fornavn," "),etternavn));            
            printf("\n\n Ny deltaker er registrert: %d %s \n\n", deltakere[teller].nummer, deltakere[teller].navn);           
            return 0;            
        }        
    }
    
    printf("\n\n Feilmelding: det er ikke plass til flere deltakere. \n\n");
    
    return 1;               
    
}

int slett_deltaker() {
    
    //TODO: alt ...
    
    return 0;
}

int registrer_starttid()  {
    
    //TODO: alt ...
    
    return 0;
}

int registrer_sluttid()  {
    
    //TODO: alt ...
    
    return 0;
}

int vis_deltakerliste() {

    int teller = 0;
    
    printf("\n\n Deltakerliste \n\n");
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer != 0) {                 
            printf("%2d %s\n", deltakere[teller].nummer, deltakere[teller].navn);                       
        }        
    }
    
    return 0;
}

int vis_resultatliste()  {
    
    //TODO: alt ...
    
    return 0;
}