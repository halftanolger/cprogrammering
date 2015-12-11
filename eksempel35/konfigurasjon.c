/*
    C -programmering, en innføring. 

    Eksempel 35

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "konfigurasjon.h"

static char *trim(char *str);
static char *hent_verdi_peker(char *navn, char *linje);

Konfigurasjon * Konfigurasjon_opprett (const char * filnavn) {

    assert (filnavn != NULL);
    assert (strlen(filnavn) > 1);

    Konfigurasjon * konfigurasjon = (Konfigurasjon*)malloc(sizeof(Konfigurasjon));
                
    if (konfigurasjon == NULL) {
        fprintf(stderr, "Klarer ikke aa allokere minne: %s\n", strerror( errno ));
        return NULL;
    }
    
    konfigurasjon->filnavn = strdup(filnavn);        
    
    if (konfigurasjon->filnavn == NULL) {
        fprintf(stderr, "Klarer ikke aa kopiere streng: %s\n", strerror( errno ));
        return NULL;    
    }
        
    konfigurasjon->logg_aktiv = NULL;

    konfigurasjon->logg_nivaa = NULL;

    konfigurasjon->logg_filnavn = NULL;
    
    konfigurasjon->test_aktiv = NULL;
        
    FILE *f = fopen(konfigurasjon->filnavn,"r");
    
    if (f == NULL) {        
        fprintf(stderr, "Klarer ikke aa aapne fila %s. %s\n", konfigurasjon->filnavn, strerror( errno ));
        return NULL;
    }

    char linje[1024];
    while (fgets(linje, 1024, f) != NULL) {
        
        char *s = trim(linje);
        
        if (strlen(s) == 0)
            continue;
            
		if (strncmp("#", s, 1) == 0)
			continue;        
                        
        if (strncmp(s,"logg_aktiv=",11) == 0) {        
            if (konfigurasjon->logg_aktiv == NULL) {
                char *p = hent_verdi_peker("logg_aktiv=",s);                        
                if ((strcmp(p,"0") == 0) || (strcmp(p,"1") == 0)) {            
                    konfigurasjon->logg_aktiv = strdup(p);            
                } else {
                    fprintf(stderr, "Ukjent verdi for logg_aktiv: '%s'\n", p);
                    return NULL;
                }
            }               
        }

        if (strncmp(s,"logg_nivaa=",11) == 0) {        
            if (konfigurasjon->logg_nivaa == NULL) {
                char *p = hent_verdi_peker("logg_nivaa=",s);                        
                if ((strcmp(p,"INFO") == 0) || (strcmp(p,"ERROR") == 0)) {            
                    konfigurasjon->logg_nivaa = strdup(p);            
                } else {
                    fprintf(stderr, "Ukjent verdi for logg_nivaa: %s\n", p);
                    return NULL;
                }
            }               
        }
        
        if (strncmp(s,"logg_filnavn=",13) == 0) {        
            if (konfigurasjon->logg_filnavn == NULL) {
                char *p = hent_verdi_peker("logg_filnavn=",s);                        
                if (strlen(p) > 0) {            
                    konfigurasjon->logg_filnavn = strdup(p);            
                } else {
                    fprintf(stderr, "Ukjent verdi for logg_filnavn: %s\n", p);
                    return NULL;
                }
            }               
        }
     
        if (strncmp(s,"test_aktiv=",11) == 0) {        
            if (konfigurasjon->test_aktiv == NULL) {
                char *p = hent_verdi_peker("test_aktiv=",s);                        
                if ((strcmp(p,"0") == 0) || (strcmp(p,"1") == 0)) {            
                    konfigurasjon->test_aktiv = strdup(p);            
                } else {
                    fprintf(stderr, "Ukjent verdi for test_aktiv: '%s'\n", p);
                    return NULL;
                }
            }               
        }

     
    }
        
    if (konfigurasjon->logg_aktiv == NULL) {
        fprintf(stderr, "Konfigurasjonsfeil, logg_aktiv er ikke definert.\n");
        return NULL;
    }

    if (konfigurasjon->logg_nivaa == NULL) {
        fprintf(stderr, "Konfigurasjonsfeil, logg_nivaa er ikke definert.\n");
        return NULL;   
    }

    if (konfigurasjon->logg_filnavn == NULL) {
        fprintf(stderr, "Konfigurasjonsfeil, logg_filnavn er ikke definert.\n");
        return NULL;   
    }

    if (konfigurasjon->test_aktiv == NULL) {
        fprintf(stderr, "Konfigurasjonsfeil, test_aktiv er ikke definert.\n");
        return NULL;
    }
    
    return konfigurasjon;
    
}

void Konfigurasjon_slett (Konfigurasjon ** konfigurasjon) {
    
    assert(*konfigurasjon != NULL);
    
    free((*konfigurasjon)->filnavn);
    free((*konfigurasjon)->logg_aktiv);
    free((*konfigurasjon)->logg_nivaa);
    free((*konfigurasjon)->logg_filnavn);
    free((*konfigurasjon)->test_aktiv);
        
    free(*konfigurasjon);
    
    return;
    
}


static char *hent_verdi_peker(char *navn, char *linje) {

	/* Hjelpefunksjon ifm parsing av konfig.-fil. Der vil jeg kunne få
	 feks 'navn= et navn'. Da må jeg kunne parse ut verdi-delen av
	 navn-verdi -strengen. */

	if (strncmp(navn, linje, strlen(navn)) != 0)
		return linje;

	char *p;
	p = linje + strlen(navn);
	while (isspace((int )*p))
		p++; /* Ta bort eventuelle space i starten */
	return p;
}

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
//http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
static char *trim(char *str) {
	char *end;

	// Trim leading space
	while (isspace((int )*str))
		str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((int )*end))
		end--;

	// Write new null terminator
	*(end + 1) = 0;

	return str;
}

