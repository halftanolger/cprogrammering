/*
    C -programmering, en innføring. 

    Eksempel 7

    Hensikten med eksempelet er å vise hvordan man kan benytte
    printf -funksjonen til å skrive ut tekst og variabler til skjerm.

*/


#include <stdio.h>

int main(int argc, char *argv[]) {

    char a[] = "hei";
    int b = 2;
    int c = 3;
    int d = b + c;

    printf ("a = %s b = %d c = %d d = %d \n", a, b, c, d);
    return 0;

}

