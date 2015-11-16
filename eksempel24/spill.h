/*
    C -programmering, en innføring. 

    Eksempel 24

*/

typedef struct spill_st {
    int poeng;
    int status;
} Spill;

Spill * Spill_opprett();
int Spill_start( Spill * );
int Spill_pause( Spill * );
int Spill_stopp( Spill * );
int Spill_slett( Spill ** );

