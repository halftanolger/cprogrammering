/*
    C -programmering, en innf�ring. 

    Eksempel 5

    Hensikten med eksempelet er � vise hvordan man kan benytte
    input-argumenter til et C -program.

*/

int main(int argc, char *argv[]) {

    int x = atoi(argv[1]);

    return x + 1;

}

