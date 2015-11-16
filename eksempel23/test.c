/*
    C -programmering, en innføring. 

    Eksempel 23

    Hensikten med eksempelet er å vise hvordan man kan bruke en struc for å
    lage en kompleks variabel. Videre viser eksempelet hvordan man ved
    hjelp av kommandoen typedef, kan opprette en ny type variabel.

*/

#include <stdio.h>

struct punkt {
    int x;
    int y;
};

typedef struct punkt Punkt;

int main() {

    Punkt p;

    p.x = 2;
    p.y = 3;
    
    printf("Mitt punkt p(%d,%d)\n",p.x, p.y);
    
    return 0;

}

