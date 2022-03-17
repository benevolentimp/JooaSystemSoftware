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

int input();

int main() {
	
	int size = 0;
	int *primePointer = NULL;
	
	size = input();
	
	primePointer = (int*) malloc(size * sizeof(int));
	
	if (primePointer != NULL) {
	
		printf("\n<Dynamic memory allocation was succesfull/>\n");
		
		// Fill the dynamically allocated array with numbers 2 to size.
		fillMemory(primePointer, size);
		
		// Use the dynamically allocated array.
		printf("\nEvery prime number until %d –\nCounted with algorithm: 'Sieve of Eratosthenes'\n", size);
		sieve(primePointer, size);
		
	} else {
	
		printf("\n<Dynamic memory allocation failed/>\n");
		return 0;
	}
	
	matrix(); // void matrix() from Matrix.h
    
    free(primePointer);
    
    return 0;
}


int input() {
	
	int sz = 0;
	char temp = 0;
	int status = 0;

	printf("Give Sieve limit\n : ");
	status = scanf("%d", &sz);
	temp = scanf("%c", &temp);
		
	while (status != 1) {
	
		printf("Please give a number...\n : ");
		status = scanf("%d", &sz);
		temp = scanf("%c", &temp);
	}
	
	return sz;
}

