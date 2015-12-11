/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "konfigurasjon.h"

enum logg_typer_enum {INFO, FEIL};

typedef enum logg_typer_enum logg_type;

typedef struct logger_st {
    
    int aktiv;
    
    char signatur[256];
   
} Logger;

Logger * Logger_opprett (Konfigurasjon *);

int Logger_slett (Logger **);

void Logger_log (Logger *, logg_type, const char*, const char *);

#endif // _LOGGER_H_