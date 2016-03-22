
#define MAX_ANTALL 10

struct tid {
    int time;
    int minutt;
    int sekund;
};

struct deltaker {    
    int nummer;
    char navn[60];
    struct tid starttid;
    struct tid sluttid;    
};


int meny();
int init();
void avslutt();
int registrer_deltaker();
int slett_deltaker();
int registrer_starttid();
int registrer_sluttid();
int vis_deltakerliste();
int vis_resultatliste();