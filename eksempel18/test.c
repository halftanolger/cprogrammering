/*
    C -programmering, en innf�ring. 

    Eksempel 18

    Hensikten med eksempelet er � vise forskjellen mellom � deklarere en 
    funksjon og definere en funksjon.

*/

#include <stdio.h>

int funk(int a, int b);

int main() {
    int a = funk(2,3);
    printf(�%a�,d);
    return 0;
}

int funk(int a, int b) {
    int c = a + b;
    return c;
}

