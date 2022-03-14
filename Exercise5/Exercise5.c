/*
Title:      	Exercise5.c - Main() function's parameters, and Arrays.
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about main()-function and Arrays...
*/

#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#define MAX 10000000

int isNumber(char number[]);
void armstrong(int clA);

void printArray(int array[], int size); // Doesn't return anything, just prints or modifies an array.
int generateArray(int array[], int size);
void arrangeArray(int array[], int size);
void swap(int *xp, int *yp);


int main(int argc, char *argv[]) {
	
	// int i = 0;
	
	int clIntegerCheck = 0;
	int clInteger = 0;
	
	int actualArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int actualArray2[8] = {-1, 1, 0, -9, 4.20, 2, 0, 7};
	int actualArray3[8] = {'@', '#', 6, 9, 4, 2, 0, 'f'}; // Test array for non-numeric elements.
	
	int emptyArray[10];
	
	// -¤- 3ab -¤-
	
	if (argc == 1) {
	
		printf("Too few arguments!\n");
		return 0;
	
	}
	
	clIntegerCheck = isNumber(argv[1]);
	
	if (clIntegerCheck == 1 && argc == 2) {
		
		printf("Executed program : %s\nWith 1 additional argument...\n", argv[0]);
		printf("%s is a number\n", argv[1]);
		clInteger = atoi(argv[1]);
		
		if (clInteger > MAX) {
			
			printf("Command-line argument too big,\nShould be between 0 - 10 000 000.\n");
			
		} else {
			
			armstrong(clInteger);
			// printf("armstrongChecker(clInteger)\n");
		}
		
	} else if (clIntegerCheck == 0 && argc == 2) {
		
		printf("Executed program : %s\nWith 1 additional argument...\n", argv[0]);
		printf("%s : Invalid input...\n", argv[1]);
		
	} else {
		
		printf("Too many arguments!\n");
		return 0;
	}
	
	// -¤- 4a -¤-
	printf("\nFunction running...\t[printArray(actualArray)]\n"); 
	printArray(actualArray, 10);
	printf("\nFunction running...\t[printArray(actualArray2)]\n"); 
	printArray(actualArray2, 8);
	printf("\nFunction running...\t[printArray(actualArray3)]\n"); 
	printArray(actualArray3, 8);
	
	// -¤- 4b -¤-
	printf("\nFunction(s) running...\t[generateArray(emptyArray), printArray(emptyArray)]\n"); 
	generateArray(emptyArray, 10);
	printArray(emptyArray, 10);
	
	// -¤- 4c -¤-
	printf("\nFunction(s) running...\t[arrangeArray(emptyArray), printArray(emptyArray)]\n"); 
	arrangeArray(emptyArray, 10);
	printArray(emptyArray, 10);
	
	printf("\n\n");
	
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
		
		// Each round of outer loop, 
		// swap the found minimum element with the first element.
		swap(&array[min_idx], &array[i]);
	}
}

void swap(int *xp, int *yp) {

	int temp = *xp;
	
	*xp = *yp;
	*yp = temp;
}

int isNumber(char number[]) {
	
	int boolean = 0;
	
	int i = 0;
	
	// Check for negatives => "the minus sign":
	if (number[0] == '-') {
		
		// printf("Give POSITIVE (+) integer, please!\n");
		
		return boolean;
	}
	
	for (i = 0; number[i] != 0; i++) {
	
		// if (number[i] > '9' || number[i] < '0')
		if (isdigit(number[i])) {
			
			boolean = 1;
			
		} else if (!isdigit(number[i])) {
			
			boolean = 0;
			// printf("Invalid argument,\nNaN-error!\n\n");
			break;
		}
	}
	
	return boolean;
}

void armstrong(int clA) {
		
	int og = 0;
	int remainder = 0;
	int sum = 0;
	int digits = 0;
	
	og = clA;
	
	// Number of digits in input:
	while (clA != 0) {
		
		digits++;
		clA /= 10;
	}
	
	clA = og; // Restores original value.
	
	// Find sum:
	while (clA != 0) {
		
		remainder = clA % 10;
		sum += pow(remainder, digits);
		clA /= 10;
	}
	
	if (sum == og) {
		
		printf("Your number '%d' is an Armstrong-number!\n", og);
		
	} else {
		
		printf("Your command-line argument is not Armstrong/Narcissistic!\n");
	}
}

/*
End of File
*/
