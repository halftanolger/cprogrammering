/*
    C -programmering, en innføring. 

    Eksempel 22

    Hensikten med eksempelet er å vise hvordan man kan bruke en struc
    for å lage en kompleks variabel.

*/

#include <stdio.h>

int main() {

    struct punkt {
        int x;
        int y;
    };

    struct punkt p;

    p.x = 2;
    p.y = 3;
    
    printf("Mitt punkt p(%d,%d)\n",p.x, p.y);
    
    return 0;

}

