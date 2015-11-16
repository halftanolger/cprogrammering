/*
    C -programmering, en innføring. 

    Eksempel 21

*/

typedef struct spill_st {
    int poeng;
    int status;
} Spill;

Spill * Spill_opprett();
int Spill_start( Spill * );
int Spill_pause( Spill * );
int Spill_stop( Spill * );
int Spill_slett( Spill ** );

