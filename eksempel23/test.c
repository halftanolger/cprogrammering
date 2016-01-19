/*
    C -programmering, en innføring. 

    Eksempel 23

*/

#include <stdio.h>
#include <stdlib.h>

struct punkt {
    int x;
    int y;
};

typedef struct punkt Punkt;

Punkt * opprett(int,int);
void slett(Punkt**);
void flytt(Punkt *, int, int);

int main() {

    /* Allokert på stacken. */
    
    Punkt pkt;
    pkt.x = 1;
    pkt.y = 2;
    
    printf("Mitt punkt pkt(%d,%d)\n",pkt.x, pkt.y);
    
    flytt(&pkt,0,0);
    
    printf("Mitt nye punkt pkt(%d,%d)\n",pkt.x, pkt.y);
    
    /* Allokert på heapen. */

    Punkt *p = opprett(2,3);
    
    printf("Mitt punkt p(%d,%d)\n",p->x, p->y);
    
    flytt(p,4,5);
    
    printf("Mitt nye punkt p(%d,%d)\n",p->x, p->y);
    
    slett(&p);
    
    return 0;

}

Punkt * opprett(int x, int y) {
    Punkt *p = (Punkt*)malloc(sizeof(Punkt));
    p->x = x;
    p->y = y;    
    return p;
}

void slett(Punkt ** p) {
    free(*p);
}

void flytt(Punkt * p, int x, int y) {
    p->x = x;
    p->y = y;
}


