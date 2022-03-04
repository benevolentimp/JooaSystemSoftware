/*
Title:      	Exercise6.c - Pointers and arrays
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about pointers and arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void arrayPrint(int *pfAPointer, int size);
int arrayGenerate(int *eAPointer, int size);

int main() {
	
	// Array declos:
	int prefilledArray[SIZE] = {0,1,2,3,4,5,6,7,8,9};
	int emptyArray[SIZE];
	
	// Pointer declos:
	int *pfA = NULL; // == prefilledArray
	int *eA = NULL; // == emptyArray
	
	pfA = &prefilledArray[0];
	eA = &emptyArray[0];
	
	// Function calls:
	arrayPrint(pfA, SIZE);
	arrayGenerate(eA, SIZE);
	arrayPrint(eA, SIZE);
	
	// Debugging testing:
	//printf("%d\n", prefilledArray[0]);
	
	printf("%d\n", *eA);
	
    return 0;
}

void arrayPrint(int *pfAPointer, int size) {
	
	int i = 0;
	
	for (i = 0; i < size; i++) {
		
		// Special format for beginning of array.
		if (i == 0) {
			
			printf("{%d, ", *pfAPointer);
			pfAPointer++;
		
		// Special format @ the end of array.
		} else if (i == size-1) {
			
			printf("%d}\n", *pfAPointer);
			
		} else {
			
			printf("%d, ", *pfAPointer);
			pfAPointer++;
		}
	}
}

int arrayGenerate(int *eAPointer, int size) {
	
	int i = 0;
	int indices = 0;
	
	srand(time(0)); // Setting the seed for rand()
	
	for (i = 0; i < size; i++) {
		
		*eAPointer = rand() % 1000000;
		indices++;
		
		if (indices == size) {
		
			i = size;
		}
		
		eAPointer++;
	}
	
	return *eAPointer;
}

/*
End of File
*/
