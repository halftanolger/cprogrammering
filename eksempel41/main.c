/*
    C -programmering, en innføring. 

    Eksempel 41

    Hensikten med eksempelet er å vise et mer eller mindre komplett
    dataprogram, som løser en konkret oppgave. I dette tilfellet er den 
    primære oppgaven å beregne anvendt tid, ifm et skirenn. Ut fra beregnet 
    anvendt tid, skal det også lages ei resultatliste.

    Følgende funksjoner er implementert:
    
        - register en deltaker
        - slett en deltaker
        - registrer klokkeslett for starttidspunkt
        - registrer klokkeslett for måltidspunkt
        - skriv ut ei deltakerliste
        - skriv ut ei resultatliste
        
*/

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

struct deltaker deltakere[MAX_ANTALL];
const char *filnavn = "deltakere.dat";

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
    
    avslutt();
    
    return 0;
}

int init() {
    
    int teller = 0;
    FILE * fd = 0;
                      
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

    /* Les inn data fra fil, om denne finnes. */
    
    fd = fopen(filnavn,"rb");                                 
    
    if (fd == 0) {        
        return 1;
    }    
                
    teller = 0;
    size_t s = 0;
    do {        
        s = fread(&deltakere[teller],sizeof(struct deltaker),1,fd);
        teller++;    
    } while (s > 0 && teller < MAX_ANTALL+1);
 
    fclose(fd);
    
    return 0;
}

void avslutt() {
    
    int teller = 0;
    FILE * fd = 0; 

    /* Skriv data til fil. */
    
    fd = fopen(filnavn,"wb");   

    if (fd == 0) {
        fprintf(stderr,"\nFeil. Klarte ikke å åpne fila %s\n", filnavn);
    }    
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {
        if (deltakere[teller].nummer != 0) {         
            fwrite(&deltakere[teller],sizeof(struct deltaker),1,fd);            
        }    
    }
    
    fclose(fd);
        
}

int meny() {
    
    int v = 0;
    
    abc:
    
    printf("\n\n == SkiData == \n\n");
    printf(" 0 - avslutt \n");
    printf(" 1 - registrer deltaker \n");
    printf(" 2 - slett deltaker \n");
    printf(" 3 - registrer start-tid for en deltaker \n");
    printf(" 4 - registrer slutt-tid for en deltaker \n");
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
    
    int nummer,teller = 0;
        
    printf("\n\n Angi deltaker \n\n");
    printf(" nummer   : ");
    scanf("%2d",&nummer);
         
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer == nummer) {                        
            deltakere[teller].nummer = 0;            
            printf("\n\n Deltaker er slettet: %s \n\n", deltakere[teller].navn);                       
            return 0;
        }        
    }
        
    printf("\n\n Feilmelding: angitt deltaker er ikke registrert. \n\n");
    
    return 1;
}

int registrer_starttid()  {
    
    int nummer,time, minutt, sekund, teller = 0;
        
    printf("\n\n Angi starttid \n\n");
    printf(" nummer   : ");
    scanf("%2d",&nummer);
    printf(" time     : ");
    scanf("%2d",&time);
    printf(" minutt   : ");
    scanf("%2d",&minutt);
    printf(" sekund   : ");
    scanf("%2d",&sekund);
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer == nummer) {                                                
            deltakere[teller].starttid.time = time;
            deltakere[teller].starttid.minutt = minutt;
            deltakere[teller].starttid.sekund = sekund;            
            printf("\n\n Starttid er registrert: %s (%.2d:%.2d:%.2d) \n\n", 
                deltakere[teller].navn,
                deltakere[teller].starttid.time,
                deltakere[teller].starttid.minutt,
                deltakere[teller].starttid.sekund);                       
            return 0;
        }        
    }
        
    printf("\n\n Feilmelding: angitt deltaker er ikke registrert. \n\n");        
        
    return 1;
}

int registrer_sluttid()  {
    
    int nummer,time, minutt, sekund, teller = 0;
        
    printf("\n\n Angi sluttid \n\n");
    printf(" nummer   : ");
    scanf("%2d",&nummer);
    printf(" time     : ");
    scanf("%2d",&time);
    printf(" minutt   : ");
    scanf("%2d",&minutt);
    printf(" sekund   : ");
    scanf("%2d",&sekund);
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer == nummer) {                                                
            deltakere[teller].sluttid.time = time;
            deltakere[teller].sluttid.minutt = minutt;
            deltakere[teller].sluttid.sekund = sekund;            
            printf("\n\n Sluttid er registrert: %20s (%.2d:%.2d:%.2d) \n\n", 
                deltakere[teller].navn,
                deltakere[teller].sluttid.time,
                deltakere[teller].sluttid.minutt,
                deltakere[teller].sluttid.sekund);                       
            return 0;
        }        
    }
        
    printf("\n\n Feilmelding: angitt deltaker er ikke registrert. \n\n");        
    
    return 1;
}

int vis_deltakerliste() {
    
    int teller = 0;
    
    printf("\n\n Deltakerliste \n\n");    
    printf(" %2s %-20s %-8s %-8s %-8s\n","Nr","Navn","Start","Slutt"); 
    printf(" -----------------------------------------\n");
       
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer != 0) {                 
                printf(" %2d %-20s %.2d:%.2d:%.2d %.2d:%.2d:%.2d  \n", 
                deltakere[teller].nummer, 
                deltakere[teller].navn,
                deltakere[teller].starttid.time,
                deltakere[teller].starttid.minutt,
                deltakere[teller].starttid.sekund,
                deltakere[teller].sluttid.time,
                deltakere[teller].sluttid.minutt,
                deltakere[teller].sluttid.sekund);            
        }        
    }
    
    return 0;
}

int vis_resultatliste()  {
    
    int teller = 0;    
    int antall = 0;
    int r[MAX_ANTALL][2] = {0};
    struct tid resultat[MAX_ANTALL];
    struct tid t1, t2, diff;
    
    /* Beregn anvendt tid. */
    
    for (teller = 0; teller < MAX_ANTALL; teller++) {        
        if (deltakere[teller].nummer != 0) {                 

            t1.time = deltakere[teller].sluttid.time;
            t1.minutt = deltakere[teller].sluttid.minutt;
            t1.sekund = deltakere[teller].sluttid.sekund;

            /* Om det ikke er registrert slutt-tid, dropper vi denne. */
            
            if (t1.time == 0 && t1.minutt == 0 && t1.sekund == 0)
                continue;
            
            t2.time = deltakere[teller].starttid.time;
            t2.minutt = deltakere[teller].starttid.minutt;
            t2.sekund = deltakere[teller].starttid.sekund;

            /* Om det ikke er registrert start-tid, dropper vi denne. */
            
            if (t2.time == 0 && t2.minutt == 0 && t2.sekund == 0)
                continue;
            
            if (t2.sekund > t1.sekund) {
                t1.minutt --;
                t1.sekund += 60;
            }

            diff.sekund = t1.sekund - t2.sekund;

            if (t2.minutt > t1.minutt) {
                t1.time --;
                t1.minutt += 60;
            }

            diff.minutt = t1.minutt - t2.minutt;
            diff.time = t1.time - t2.time;

            resultat[teller].time = diff.time;
            resultat[teller].minutt = diff.minutt;
            resultat[teller].sekund = diff.sekund;
                
            r[antall][0] = diff.time * 60 * 60 + diff.minutt * 60 + diff.sekund;
            r[antall][1] = deltakere[teller].nummer;        
            antall++;
        }
    }

    /* Sorter lista vha 'Bubble sort'-algoritmen. */
    
    int c,d,e,f;
    
    for (c = 0; c < antall - 1; c++) {     
        for (d = 0; d < antall - c - 1; d++) {         
            if (r[d][0] > r[d+1][0]) {  
                 
                /* Bytt om */

                e = r[d][0];
                f = r[d][1];
                
                r[d][0] = r[d+1][0];
                r[d][1] = r[d+1][1];
                
                r[d+1][0] = e;
                r[d+1][1] = f;
    
            }            
        }        
    }
     
    /* Skriv ut liste til skjerm. */ 
    
    printf("\n\n Resultatliste \n\n");    
    printf("%2s %-20s %-8s %-8s %-8s\n","Nr","Navn","Start","Slutt","Brukt"); 
    printf("--------------------------------------------------\n");
    
    for (c = 0; c < antall; c++) {   
        for (teller = 0; teller < MAX_ANTALL; teller++) {               
            if (deltakere[teller].nummer == r[c][1]) { 
            
                printf("%2d %-20s %.2d:%.2d:%.2d %.2d:%.2d:%.2d %.2d:%.2d:%.2d  \n", 
                deltakere[teller].nummer, 
                deltakere[teller].navn,
                deltakere[teller].starttid.time,
                deltakere[teller].starttid.minutt,
                deltakere[teller].starttid.sekund,
                deltakere[teller].sluttid.time,
                deltakere[teller].sluttid.minutt,
                deltakere[teller].sluttid.sekund,
                resultat[teller].time,
                resultat[teller].minutt,
                resultat[teller].sekund);
                break;
                
            }                    
        }        
    }
   
    return 0;
    
}