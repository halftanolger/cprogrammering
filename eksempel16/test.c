/*
    C -programmering, en innf�ring. 

    Eksempel 16

    Hensikten med eksempelet er � vise hvor en variabel er synlig.

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

