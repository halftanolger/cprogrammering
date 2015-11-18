/*
    C -programmering, en innføring. 

    Eksempel 9

    Hensikten med eksempelet er å vise hvordan man kan benytte en while-løkke.

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

