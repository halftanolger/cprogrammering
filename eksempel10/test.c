/*
    C -programmering, en innf�ring. 

    Eksempel 10

    Hensikten med eksempelet er � vise hvordan man kan benytte en for-l�kke.

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

