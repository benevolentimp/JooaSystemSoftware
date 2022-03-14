/* 
 * File:   		Exercise7.c
 * Author:		Jooa Jaakkola
 * Description: Some mathematical concepts with dynamic memory allocation and
 				distibuting functions into separate files.
 */

#include <stdio.h>
#include <stdlib.h>

#include "Sieve.h"
#include "Matrix.h"

int main() {
	
	int size = 0;
	int *primePointer = NULL;
	
	printf("Give Sieve limit\n : ");
	scanf("%d", &size);
	
	primePointer = (int*) malloc(size * sizeof(int));
	
	if (primePointer != NULL) {
	
		printf("\n[Dynamic memory allocation was succesfull]\n");
		
		// Fill the dynamically allocated array with numbers 2 to size.
		fillMemory(primePointer, size);
		
		// Use the dynamically allocated array.
		printf("\nEvery prime number until %d –\nCounted with algorithm: 'Sieve of Eratosthenes'\n", size);
		sieve(primePointer, size);
		
	} else {
	
		printf("\n[Dynamic memory allocation failed]\n");
		return 0;
	}
	
	testMatrix();
    
    free(primePointer);
    
    return 0;
}

