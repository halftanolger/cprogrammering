/*
    C -programmering, en innføring. 

    Eksempel 11

    Hensikten med eksempelet er å vise hvordan man kan bygge opp et dataprogram
    ved å dele det opp i flere funksjoner.

*/

#include <stdio.h>

int min_funksjon(int a, int b) {
    return a+b;
}

int main() {

    int c = min_funksjon(2,3);
    printf("c=%d",c);
    return 0;

}

