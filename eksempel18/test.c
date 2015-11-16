/*
    C -programmering, en innføring. 

    Eksempel 18

    Hensikten med eksempelet er å vise forskjellen mellom å deklarere en 
    funksjon og definere en funksjon.

*/

#include <stdio.h>

int funk(int a, int b);

int main() {
    int a = funk(2,3);
    printf(“%a”,d);
    return 0;
}

int funk(int a, int b) {
    int c = a + b;
    return c;
}

