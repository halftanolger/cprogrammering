/*
    C -programmering, en innføring. 

    Eksempel 15

    Hensikten med eksempelet er å vise hvor en variabel er synlig.

*/

#include <stdio.h>

int main() {

    int hjemvegen123 = 2;

    int i;

    for (i=0; i<5; i=i+1) {

            int hjemvegen123 = 3;
            printf ("%d", hjemvegen123);

    }

    printf ("%d",hjemvegen123);

    return 0;
}

