/*
    C -programmering, en innføring. 

    Eksempel 24

*/

typedef struct spaceinvader_st {
    int status;
} Spaceinvader;

Spaceinvader * Spaceinvader_opprett();

void Spaceinvader_spill( Spaceinvader * );

void Spaceinvader_slett( Spaceinvader ** );

