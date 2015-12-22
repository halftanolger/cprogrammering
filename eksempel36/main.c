/*
    C -programmering, en innføring. 

    Eksempel 36

*/

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "spaceinvader.h"
#include "logger.h"
#include "konfigurasjon.h"
#include "test/test.h"

Konfigurasjon * konfigurasjon;
Logger * logg;

int main(int argc, char *argv[]) {

    konfigurasjon = Konfigurasjon_opprett("konfigurasjon.txt");
    
    if (konfigurasjon == NULL) 
        return 1;
    
    logg = Logger_opprett(konfigurasjon);
    
    if (logg == NULL)
        return 1;

    if (strcmp(konfigurasjon->test_aktiv,"1") == 0) 
        return test_main();
        
    const char * sign = "main(int,char*[])";
    
    Logger_log (logg, INFO, sign, "start");
    
    Spaceinvader *spaceinvader = Spaceinvader_opprett();
    
    if (spaceinvader == NULL) 
        return 1;

    Spaceinvader_spill(spaceinvader);
    
    Spaceinvader_slett(&spaceinvader);

    Logger_log (logg, INFO, sign, "slutt");
    
    return 0;

}

