/*
    C -programmering, en innføring. 

    Eksempel 34

*/

#include <stdlib.h>
#include <stdio.h>
#include "rektangel.h"

Rektangel * Rektangel_opprett(int x, int y, int b, int h) {

    Rektangel * rektangel = (Rektangel*)malloc(sizeof(Rektangel));
        
    rektangel->x = x;
    rektangel->y = y;
    rektangel->b = b;
    rektangel->h = h;
            
    return rektangel;
    
}

int Rektangel_slett (Rektangel ** rektangel) {

    free(*rektangel);
    return 0;
    
}

int Rektangel_overlapp (Rektangel * r1, Rektangel * r2) {

    /* To rektangler overlapper ikke hverandre, om en 
       av de to punktene nedenfor stemmer:
       
       1. Det ene rektangelet er ovenfor det andre.
       2. Det ene rektangelet er til venstre for det andre.
       
       (Nb, legg merke begrepene 'det ene' og 'det andre', som i praksis betyr
        at du kan bytte det ene med det andre, og dermed kun trenger å nevne
        toppen (og ikke bunnen), venstre siden (og ikke høyre) :-) Legg også 
        merke til at puntet 0,0 er oppe i venstre hjørne på 'skjermen', og at
        f.eks punktet 10,10 blir litt til høyre og litt ned ...)
        
                       
                         v2
                         +--------------------+
        v1               |                    |
        +------------------------+            |
        |                |       |            |
        |                +-------|------------+
        |                        |            h2
        |                        |
        +------------------------+
                                 h1
       
       0,0       
        +------------- 100
        |   x(1,1)
        |
        |          x(80,80)     
       100
                
        Ref. http://www.geeksforgeeks.org/find-two-rectangles-overlap 
                                                
      */  
                     
    int h1x = r1->x + r1->b;
    int h1y = r1->y + r1->h;
    
    int v1x = r1->x;
    int v1y = r1->y;
            
    int h2x = r2->x + r2->b;;
    int h2y = r2->y + r2->h;
    
    int v2x = r2->x;
    int v2y = r2->y;
        
     /* Det ene til siden for det andre? */
     
    if (v1x > h2x || v2x > h1x) {
        return 0;
    }
 
    /* Det ene ovenfor det andre? */
    
    if (v1y > h2y || v2y > h1y) {
        return 0;
    }
       
    return 1;

}

