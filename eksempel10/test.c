/*
    C -programmering, en innføring. 

    Eksempel 10

    Hensikten med eksempelet er å vise hvordan man kan benytte en for-løkke.

*/

#include <stdio.h>
#include <ctype.h>

int main() {

    char tekst[] = "Dette er en tekst.";
    int i;
    for(i=0;i<17; i=i+1) {
        tekst[i]=toupper(tekst[i]);
    }

    printf("%s",tekst);
    return 0;

}

