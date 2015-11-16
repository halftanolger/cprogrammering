/*
    C -programmering, en innføring. 

    Eksempel 20

*/

#include <funk.h>

static int hemmelig_funksjon(int a, int b) {
    return 50;
}

int funk(int a, int b) {
    int c = hemmelig_funksjon(a,b);
    return c;
}

