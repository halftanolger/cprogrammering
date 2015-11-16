/*
    C -programmering, en innføring. 

    Eksempel 13

    Hensikten med eksempelet er å vise hvordan man kan bygge opp et dataprogram
    ved å dele det opp i flere funksjoner.

*/

#include <stdio.h>
#include <string.h>

void min_input(char *tekst, int *data) {
    printf("%s",tekst);
    scanf("%d",data);
}

int meny() {
    int valg;
    int valg_ok = 0;

    while (valg_ok == 0) {
        printf("\nVelg 1 for aa avslutte\n");
        printf("Velg 2 for aa legge sammen to tall, a + b\n");
        printf("Velg 3 for aa multiplisere to tall, a x b\n");
        printf("\n");

        min_input("Velg:",&valg);

        if (valg == 1 || valg == 2 || valg == 3) {
            return valg;
        } else {
            printf("Ugyldig valg, velg 1, 2 eller 3\n");
        }
    }
}

int min_beregning(int a, int b, int type) {
    if (type == 2) {
        return a+b;
    } else if (type == 3) {
        return a*b;
    } else {
        return 0;
    }
}

void min_output(int a, int b, int c, int type) {
    char t;

    if (type == 2) {
        t = '+';
    } else if (type == 3) {
        t = '*';
    }

    printf("\n%d %c %d = %d\n",a,t,b,c);
}

int main() {
    int a,b,c,v;

    while (1) {

        v = meny();

        if (v == 1)
            return 0;

        min_input("\nOppgi et tall, a: ",&a);
        min_input("Oppgi et tall, b: ",&b);
        c = min_beregning(a,b,v);
        min_output(a,b,c,v);
        
    }

}

