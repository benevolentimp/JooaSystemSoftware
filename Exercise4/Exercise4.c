/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Title:      Exercise4.c - Basics of Functions
Auhtor:     Jooa Jaakkola
Desc:       Programming basics - Learning to divide code into "function-blocks"
*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int countNegatives();


int main() {
	
	int countedNegatives = countNegatives();
	
	if (countedNegatives == 1) {
	
		printf("You gave %d negative number.\n", countedNegatives);
		
	} else if (countedNegatives == 0) {
	
		printf("You gave no negative numbers.\n");
		
	} else {
	
		printf("You gave %d negative numbers.\n", countedNegatives);
	}
    
    
    return 0;
}

/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

int countNegatives() {

	int inputs = 0;
	int negatives = 0;
	int local_iterator = 1;
	
	while (local_iterator) {
		
		printf("Give an integer (Press 0 to exit): "); scanf("%d", &inputs);
		
		if (inputs == 0) {
			
			printf("Okay... exiting program...\n\n");
			local_iterator = 0;
			
		} else if (inputs < 0) {
			
			//printf(">>> %d\n", inputs);
			negatives++;
			
		} else {
			
			//printf(">>> %d\n", inputs);
		}
	}
	
	return negatives;
}


/*
eof
*/
