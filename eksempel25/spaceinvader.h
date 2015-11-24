/*
    C -programmering, en innføring. 

    Eksempel 25

*/

#define STATUS_SPILL 1
#define STATUS_PAUSE 2
#define STATUS_STOPP 3

typedef struct spaceinvader_st {
    int poeng;
	int resultatliste[3];	
    int status;
} Spaceinvader;

Spaceinvader * Spaceinvader_opprett();
int Spaceinvader_spill( Spaceinvader * );
int Spaceinvader_slett( Spaceinvader ** );

