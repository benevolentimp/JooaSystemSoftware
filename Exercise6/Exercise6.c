/*
Title:      	Exercise6.c - Pointers and arrays
Auhtor:     	Jooa Jaakkola
Description:	Small exercises about pointers and arrays.
*/

#include <stdio.h>

#define SIZE 10

void arrayPrint(char *a_pointer, int size);

int main() {
	
	char array[SIZE] = {'q','w','e','r','t','y','u','i','o','p'};
	char *arrayPointer = NULL;
	arrayPointer = &array[0];
	
	arrayPrint(arrayPointer, SIZE);
	
    return 0;
}

void arrayPrint(char *a_pointer, int size) {
	
	int i = 0;
	
	for (i = 0; i < size; i++) {
		
		printf("%c", *a_pointer);
		a_pointer++;
	}
	printf("\n");
}

/*
End of File
*/
