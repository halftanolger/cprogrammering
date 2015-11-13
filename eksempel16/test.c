#include <stdio.h>

int main() {
	int a = 2;
	{
    		int a = 3;
    		printf("%d",a);
	}
    	printf ("%d",a);
    	return 0;
}

