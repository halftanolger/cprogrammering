/*
    C -programmering, en innf�ring. 

    Eksempel 14

    Hensikten med eksempelet er � vise hvor en variabel er synlig.

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

