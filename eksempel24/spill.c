/*
    C -programmering, en introduksjon. 

    Eksempel 24

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <spill.h>

Spill * Spill_opprett() { 

	printf("Spill_opprett - start\n");

	Spill *s = (Spill*)malloc(sizeof(Spill));
	
	if (s == NULL) {
		return NULL;
	}

	s->poeng = 0;
	s->status = 0;
	
	printf("Spill_opprett - slutt\n");
	
	return s;
}

int Spill_slett( Spill ** spill )  { 

	assert(*spill != NULL);

	printf("Spill_slett - start\n");

	free(*spill);

	printf("Spill_slett - slutt\n");
	
	return 0; 
}

int Spill_start( Spill * spill ) { 

	printf("Spill_start - start\n");

	spill->status = 1;
	
	printf("Spill_start - slutt\n");
	
	return 0; 
}

int Spill_pause( Spill * spill )  { 

	printf("Spill_pause - start\n");

	spill->status = 2;
	
	printf("Spill_pause - slutt\n");
	
	return 0; 
}

int Spill_stopp( Spill * spill )  { 

	printf("Spill_stopp - start\n");

	spill->status = 3;
	
	printf("Spill_stopp - slutt\n");
	
	return 0; 
}



