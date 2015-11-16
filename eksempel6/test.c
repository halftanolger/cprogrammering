/*
    C -programmering, en innføring. 

    Eksempel 6

    Hensikten med eksempelet er å vise hvordan man kan benytte
    input-argumenter til et C -program.

*/

int main(int argc, char *argv[]) {

    if (argc != 3) {
        return 0;
    }
    char *a = argv[0];
    char *b = argv[1];
    char *c = argv[2];
    int t1 = atoi(b);
    int t2 = atoi(c);
	
    return t1 + t2;
	
}

