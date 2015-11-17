/*
    C -programmering, en innføring. 

    Eksempel 12

    Hensikten med eksempelet er å vise hvordan man kan bygge opp et dataprogram
    ved å dele det opp i flere funksjoner.

*/

#include <stdio.h>

void min_input(char *tekst, int *data) {
    printf("%s",tekst);
    scanf("%d",data);
}

int min_beregning(int a, int b) {
    return a+b;
}

void min_output(int a, int b, int c) {
    printf("%d + %d = %d\n",a,b,c);
}

int main() {
    
    int a,b,c;
    
    min_input("Oppgi et tall, a: ",&a);
    min_input("Oppgi et tall, b: ",&b);

    c = min_beregning(a,b);

    min_output(a,b,c);
    return 0;    
}

