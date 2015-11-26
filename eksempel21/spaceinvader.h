/*
    C -programmering, en innføring. 

    Eksempel 21

*/

typedef struct spaceinvader_st {

    int status;
	
} Spaceinvader;

Spaceinvader * Spaceinvader_opprett();

int Spaceinvader_spill( Spaceinvader * );

int Spaceinvader_slett( Spaceinvader ** );

