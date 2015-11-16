/*
    C -programmering, en innføring. 

    Eksempel 14

    Hensikten med eksempelet er å vise hvor en variabel er synlig.

*/

#include <stdio.h>

int funk() {
    int hjemvegen123 = 1;
    return hjemvegen123;
}

int main() {
    int hjemvegen123 = 2;
    printf ("%d %d", hjemvegen123, funk());
    return 0;
}

