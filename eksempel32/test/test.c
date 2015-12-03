/*
    C -programmering, en innføring. 

    Eksempel 32

*/

#include <stdio.h>
#include "test_rektangel.h"
#include "test.h"

int test_main() {

    int i = 0;
    int antall_feil = 0;
    int antall_tester = 0;

    int (*test_funksjons_peker_tabell[])() = {

        test_rektangel_overlapp

    };

    antall_tester = 1;

    for (i = 0; i < antall_tester; i++) {
        if (test_funksjons_peker_tabell[i]() > 0) {
            antall_feil++;
        }
    }

    fprintf(stderr, "Totalt antall enhetstester : %d\n", antall_tester);
    fprintf(stderr, "Antall enhetstester, ok    : %d\n", antall_tester - antall_feil);
    fprintf(stderr, "antall enhetstester, feilet: %d\n", antall_feil);

    return antall_feil;

}

