/*
    C -programmering, en innføring. 

    Eksempel 6

    Hensikten med eksempelet er å vise hvordan man kan benytte
    input-argumenter til et C -program.

*/

int main(int argument_antall, char *argument_vektor[]) {

    if (argument_antall != 3) {
        return 0;
    }
    char *a = argument_vektor[0];
    char *b = argument_vektor[1];
    char *c = argument_vektor[2];
    int t1 = atoi(b);
    int t2 = atoi(c);
	
    return t1 + t2;
	
}

