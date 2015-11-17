/*
    C -programmering, en innføring. 

    Eksempel 17

    Hensikten med eksempelet er å vise hvor en global variabel er synlig.

*/

#include <stdio.h>

int a = 1;

void funk1() {
    printf("%d",a);
}

void funk2() {
    int a = 2;
    printf("%d",a);
}

int main() {

    funk1();
    funk2();
    printf("%d",a);

    {
        int a=3;
        printf("%d",a);
    }

    return 0;

}

