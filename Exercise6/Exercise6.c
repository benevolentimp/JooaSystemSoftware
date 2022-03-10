/*
Title:      	Exercise6.c - Pointers and arrays
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about pointers and arrays.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10
#define ROWS 32
#define COLS 2

void print(int *ptr, int size); // Takes any array
void print2d(float arr, int rows, int cols);

int generate(int *ptr, int size); // Takes empty array

int sort(int *ptr, int size); // Takes any array
int find(int *ptr, int size); // Takes any array

void ntcLookup1k(s);

int main() {
	
	// Array declos:
	int prefilledArray[SIZE] = {0,1,2,3,4,5,6,7,8,9};
	int array[SIZE];
	float ntcLookupTable[ROWS][COLS];
	/*
	// 32 rows, 2 columns – 32 inner arrays, each has two elements.
	float ntcLookup[32][2] = {
	{250, 1.4},
	{275, 4.0},
	{300, 6.4},
	{325, 8.8},
	{350, 11.1},
	{375, 13.4},
	{400, 15.6},
	{425, 17.8},
	{450, 20.0},
	{475, 22.2},
	{500, 24.4},
	{525, 26.7},
	{550, 29.0},
	{574, 31.3},
	{600, 33.7},
	{625, 36.1},
	{650, 38.7},
	{675, 41.3},
	{700, 44.1},
	{725, 47.1},
	{750, 50.2},
	{775, 53.7},
	{784, 55.0},
	{825, 61.5},
	{850, 66.2},
	{875, 71.5},
	{900, 77.9},
	{925, 85.7},
	{937, 90.3},
	{950, 96.0},
	{975, 111.2},
	{1000, 139.5},
	};
	*/
	
	// Pointer declos:
	int *pfArrayP = NULL;
	int *arrayP = NULL;
	float *ntcP = NULL;
	
	pfArrayP = &prefilledArray[0];
	arrayP = &array[0];
	ntcP = &ntcLookupTable[0][0];
	
	// Function calls:
	print(pfArrayP, SIZE);
	
	generate(arrayP, SIZE);
	print(arrayP, SIZE);
	
	sort(arrayP, SIZE);
	if (find(arrayP, SIZE) != NULL) {
		printf("User gave %d and it is in array,\n(accessed from pointer)\n\n", *arrayP);
	} else {
		printf("The number user gave is not in array.\n\n");
	}
	
	/*
	//ntcLookup1k(float ntcLookup);
	for (int j = 0; j < ROWS; ++j) {
		for (int i = 0; i < COLS; ++i) {
			printf("Row_%d, Column_%d | ADC -:- %.2f\n", i+1, j+1, ntcLookup[i][j]);
		}
	}
	*/
	
	ntcLookup1k();
	
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

int find(int *ptr, int size) {

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

void ntcLookup1k() {
	
	FILE *ptr = fopen("1k_NTC_Thermistor_Look_Up_Table.txt", "r");
	if (ptr == NULL) {
		printf("This file doesn't exist or is in another directory.");
		return NULL;
	}
	
	char buffer[128];
	while (fscanf(ptr, "%*s, %*s, %s", buffer) == 1) {
		printf("%s\n", buffer);
	}
}

/*
End of File
*/
