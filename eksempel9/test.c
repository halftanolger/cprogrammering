/*
    C -programmering, en innf�ring. 

    Eksempel 9

    Hensikten med eksempelet er � vise hvordan man kan benytte en while-l�kke.

*/
#include <stdio.h>

int main(int argc, char *argv[]) {

    int b = 10;

    while (b > 0) {
        b = b - 1;
        printf ("%d\n",b);
    }

return 0;

}

