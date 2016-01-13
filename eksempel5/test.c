/*
    C -programmering, en innføring. 

    Eksempel 5

    Hensikten med eksempelet er å vise hvordan man kan benytte
    input-argumenter til et C -program.

*/

int main(int argument_antall, char *argument_vektor[]) {

    int x = atoi(argument_vektor[1]);

    return x + 1;

}

