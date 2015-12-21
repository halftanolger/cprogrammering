/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "logger.h"

Logger * Logger_opprett(Konfigurasjon * konfigurasjon) {

    assert (konfigurasjon != NULL);

    Logger * logger = (Logger*)malloc(sizeof(Logger));

    if (logger == NULL) {
        fprintf(stderr, "Klarer ikke aa allokere minne: %s\n", strerror( errno ));
        return NULL;
    }
    
    if (strcmp(konfigurasjon->logg_aktiv,"1") == 0) {
        logger->aktiv = 1;
    } else if (strcmp(konfigurasjon->logg_aktiv,"0") == 0) {   
        logger->aktiv = 0;
    } else {
        fprintf(stderr, "Systemfeil %d %s", __LINE__, __FILE__);
        return NULL;
    }    
        
    strcpy(logger->signatur,"nop");
                  
    return logger;
    
}

int Logger_slett (Logger ** logger) {

    free(*logger);
    
    return 0;
    
}

void Logger_log (Logger * logger, logg_type type, const char * signatur, const char * melding) {

    if (logger->aktiv == 0) {
        return;
    }

	time_t rawtime;
	struct tm * timeinfo;
    char tekst[128];
    char *type_tekst;
    char *type_tekst_info = "INFO";
    char *type_tekst_feil = "FEIL";

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	
    if (type == INFO) {
        type_tekst = type_tekst_info;
    } else {
        type_tekst = type_tekst_feil;
    }
    
	sprintf (tekst, "%d:%d:%d %s %s: ", timeinfo->tm_hour, timeinfo->tm_min,
			timeinfo->tm_sec, type_tekst, signatur);
            
    fprintf (stderr,"%s %s\n", tekst, melding);
            
}

