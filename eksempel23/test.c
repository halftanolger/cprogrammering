/*
    C -programmering, en innføring. 

    Eksempel 23

*/

#include <stdio.h>

struct punkt {
    int x;
    int y;
};

typedef struct punkt Punkt;

int main() {

    Punkt p;

    p.x = 2;
    p.y = 3;
    
    printf("Mitt punkt p(%d,%d)\n",p.x, p.y);
    
    return 0;

}

