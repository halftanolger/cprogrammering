/*
    C -programmering, en innføring. 

    Eksempel 19

    Hensikten med eksempelet er å vise forskjellen mellom å deklarere en 
    funksjon og definere en funksjon. Deklarasjonen av funksjonen legges i 
    h -fila og definisjonen legges i c -fila.

*/

#include <stdio.h>
#include <funk.h>

int main() {
    int a = funk(2,3);
    printf("%d",a);
    return 0;
}

