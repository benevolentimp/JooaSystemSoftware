/*
Title:      	Exercise6.c - Pointers and arrays
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about pointers and arrays.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void print(int *ptr, int size); // Takes any array

int generate(int *ptr, int size); // Takes empty array

int sort(int *ptr, int size); // Takes any array
int *find(int *ptr, int size); // Takes any array

int main() {
	
	// Array declos:
	int prefilledArray[SIZE] = {0,1,2,3,4,5,6,7,8,9};
	int array[SIZE];
	
	// Pointer declos:
	int *pfArrayP = NULL;
	int *arrayP = NULL;
	
	pfArrayP = &prefilledArray[0];
	arrayP = &array[0];
	
	// Function calls:
	print(pfArrayP, SIZE);
	
	generate(arrayP, SIZE);
	print(arrayP, SIZE);
	
	sort(arrayP, SIZE);
	print(arrayP, SIZE);
	if (find(arrayP, SIZE) != NULL) {
		printf("User gave %d and it is in array,\n(accessed from pointer)\n", *arrayP);
	} else {
		printf("The number user gave is not in array.\n");
	}
	
    return 0;
}

void print(int *ptr, int size) {
	
	int i = 0;
	
	for (i = 0; i < size; i++) {
		
		// Special format for beginning of array.
		if (i == 0) {
			
			printf("{%d, ", *ptr);
			ptr++;
		
		// Special format @ the end of array.
		} else if (i == size-1) {
			
			printf("%d}\n", *ptr);
			
		} else {
			
			printf("%d, ", *ptr);
			ptr++;
		}
	}
}

int generate(int *ptr, int size) {
	
	int i = 0;
	int indices = 0;
	
	srand(time(0)); // Setting the seed for rand()
	
	for (i = 0; i < size; i++) {
		
		*ptr = rand() % 1000000;
		indices++;
		
		if (indices == size) {
		
			i = size; // Break loopnto avoid overindexing
		}
		
		ptr++;
	}
	
	return *ptr;
}

int sort(int *ptr, int size) {

	int i = 0;
	int j = 0;
	int temp = 0;
	
	for (i = 0; i < size; i++) {
		
		for (j = i + 1; j < size; j++) {
			
			// i and j grow and alter this if-statement each round.
			if (*(ptr + j) > *(ptr + i)) {
				
				temp = *(ptr + i); // Save a backup for "current" value
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = temp;
			}
		}
	}
	
	return *ptr;
}

int *find(int *ptr, int size) {

	int i = 0;
	int input = 0;
	
	printf("Give an integer (0 - 1 000 000)\n : ");
	scanf("%d", &input);
	
	for (i = 0; i < size; i++) {
		
		if (*ptr == input) {
		
			return *ptr;
		}
		
		ptr++;
	}
	
	return NULL;
}

/*
End of File
*/
