/* 
 * File:   		Sieve.c
 * Author:		
 * Description: 
 */

#include <stdio.h>
#include <math.h>

#include "Sieve.h"

int fillMemory(int *ptr, int size) {

	int i = 0;
	
	// Fill memoryslot with all digits from 2 to size.
	for (i = 2; i < size; i++) {
		
		*ptr = i;
		
		ptr++;
	}
	
	return *ptr;
}

int sieve(int *ptr, int size) {
	
	int i = 0;
	
	// Iterate every number 2 to size and their multiples. Then write them as 0 into array.
	for (i = 2; i <= size; i++) {
		
		if ((*ptr % 2 == 0) || (*ptr % 3 == 0) || (*ptr % 5 == 0) || (*ptr % 7 == 0)) {
			
			if ((*ptr == 2) || (*ptr == 3) || (*ptr == 5) || (*ptr == 7)) {
				
				*ptr = *ptr;
								
			} else {
			
				*ptr = 0;
			}
		}
		
		// Print the numbers only if prime !
		if (*ptr != 0) {
			printf("%d\n", *ptr);
		}
		
		// Guard for overindexing pointer !
		if (*ptr == size) {
		
			i++;
			
		} else {
			
			ptr++;
		}
	}
	
	return *ptr;
}
