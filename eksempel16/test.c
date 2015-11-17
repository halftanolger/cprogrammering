/*
    C -programmering, en innføring. 

    Eksempel 16

    Hensikten med eksempelet er å vise hvor en variabel er synlig.

*/

#include <stdio.h>

int main() {
    int a = 2;
    {
        int a = 3;
        printf("%d",a);
    }
    printf ("%d",a);
    return 0;
}

