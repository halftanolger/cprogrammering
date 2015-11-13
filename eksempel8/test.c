	
#include <stdio.h>

int main(int argc, char *argv[]) {    
    	
	char *navn = argv[0];

    	if (argc != 3) {
        	printf("\nBruk: %s t1 t2 \n", navn);
            	printf("\n      hvor t1 og t2 er to heltall ");
            	printf("som er > 0\n\n");        
            	printf("Programmet adderer to tall og ");
            	printf("skriver summen ut paa skjermen.\n");
            	return 1;
        }

    	char *a = argv[1];
    	char *b = argv[2];
    	int t1 = atoi(a);

        if (t1 == 0) {
            	printf("\nFeil: t1 maa vaere et heltall > 0\n");
            	return 1;
        }     
   
    	int t2 = atoi(b);

        if (t2 == 0) {
            	printf("\nFeil: t2 maa vaere et heltall > 0\n");
            	return 1;
        }

    	int t3 = t1 + t2;
        printf ("Summen av %d og %d er %d\n", t1, t2, t3);

    	return 0;

}


