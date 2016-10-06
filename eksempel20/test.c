/*
    C -programmering, en innføring. 

    Eksempel 20

    Hensikten med eksempelet er å vise at en statiskt definert funksjon i 
    fila funk.c ikke er synlig for kode som er definert i en annen 
    kompileringsenhet.

*/

#include <stdio.h>
#include <funk.h>

int hemmelig_funksjon(int a, int b) {
    return 45;
}


int main() {
    int a = funk(2,3);
    printf("%d\n",a);
    printf("%d\n",hemmelig_funksjon(2,3));
    return 0;
}

