/*
Title:      	Exercise5.c - Main() function's parameters, and Arrays.
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about main()-function and Arrays...
*/

#include <stdio.h>

#include <stdlib.h>
#include <time.h>
//#include <ctype.h>

int isNumber(char number[]);
void printArray(int array[], int size); // Doesn't return anything, just prints or modifies an array.
int generateArray(int array[], int size);
void arrangeArray(int array[], int size);
void swap(int *xp, int *yp);


int main(int argc, char *argv[]) {
	
	int actualArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int actualArray2[8] = {2, 3, 6, 9, 4, 2, 0, 7};
	//int actualArray3[8] = {'@', '#', 6, 9, 4, 2, 0, 'f'}; // Test array for non-numeric elements.
	int emptyArray[10];
	
	if (argc == 1) {
		printf("Executed program : %s\nWith no additional arguments...\n", argv[0]);
	}
	
	printf("\nFunction running...\t[printArray(actualArray)]\n"); 
	printArray(actualArray, 10);
	
	printf("\nFunction running...\t[printArray(actualArray2)]\n"); 
	printArray(actualArray2, 8);
	
	printf("\nFunction(s) running...\t[generateArray(emptyArray), printArray(emptyArray)]\n"); 
	generateArray(emptyArray, 10);
	printArray(emptyArray, 10);
	
	printf("\nFunction(s) running...\t[arrangeArray(emptyArray), printArray(emptyArray)]\n"); 
	arrangeArray(emptyArray, 10);
	printArray(emptyArray, 10);
	
	/*
	if (isNumber(argv[1]) == 1) {
		
		printf("%s is a number\n", argv[1]);
		
	} else if (isNumber(argv[1]) == 0) {
		
		printf("%s is not a number\n", argv[1]);
	}
	*/
	
    return 0;	
}


void printArray(int array[], int size) {
	
	int i = 0;
	
	for (i = 0; i < size; i++) {
		
		printf("@index_%d : %d\n", i, array[i]);
	}
}

int generateArray(int array[], int size) {
	
	int i = 0;
	
	srand(time(0)); // Set a new seed for random (each function call/program run).
	
	for (i = 0; i < size; i++) {
		
		array[i] = rand() % 1000000;
		//printf("%d\n", array[i]); // Debug print-out.
	}
	
	return array[size];
}

void arrangeArray(int array[], int size) {
	
	int i = 0;
	int j = 0;
	
	int min_idx = 0;
	
	for (i = 0; i < size - 1; i++) {
		
		min_idx = i;
		
		for (j = i + 1; j < size; j++) {
			
			if (array[j] < array[min_idx]) {
				
				min_idx = j;
			}
		}
		
		swap(&array[min_idx], &array[i]);
	}
}

void swap(int *xp, int *yp) {
	
	int temp = *xp;
	
	*xp = *yp;
	*yp = temp;
}

/*
int isNumber(char number[]) {

	int i = 0;
	
	// Check for negatives => "the minus sign":
	if (number[0] == '-') {
		
		i = 1;
	}
	
	for (i = i; number[i] != 0; i++) {
		
		// if (number[i] > '9' || number[i] < '0')
		if (isdigit(number[i])) {
			
			return 1;
		}
	}
	
	return 0;
}
*/

/*
End of File
*/
