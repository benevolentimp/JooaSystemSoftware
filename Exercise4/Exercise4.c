/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Title:      Exercise4.c - Basics of Functions
Auhtor:     Jooa Jaakkola
Desc:       Programming basics - Learning to divide code into "function-blocks"
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int askingNumbers();
int countNegatives();
int countSum();

int main() {
	
	int countedNegatives = 0;
	int countedSum = 0;
	
	
	/* Exercise_4 3a – Conditions for accurate grammar in output. */
	countedNegatives = countNegatives();
	
	if (countedNegatives == 1) {
	
		printf("You gave %d negative number.\n", countedNegatives);
		printf("\n################################\n\n");
		
	} else if (countedNegatives == 0) {
	
		printf("You gave no negative numbers.\n");
		printf("\n################################\n\n");
		
	} else {
	
		printf("You gave %d negative numbers.\n", countedNegatives);
		printf("\n################################\n\n");
	}
	
	
	/* Exercise_4 3b */
	countedSum = countSum();
	
	printf("The sum of your integers is: %d\n", countedSum);
	printf("\n################################\n\n");
    
    
    return 0;
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

int countNegatives() {

	int local = 1;
	int inputs = 0;
	int negatives = 0;
	
	while (local) {
		
		printf("Give an integer (press 0 to exit): "); scanf("%d", &inputs);
		
		if (inputs == 0) {
			
			printf("Exiting 'countNegatives()'...\n");
			local = 0;
			
		} else if (inputs < 0) {
		
			negatives++;
			
		}
	}
	
	return negatives;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int countSum() {
	
	int local = 1;
	int inputs = 0;
	int sum = 0;
	
	while (local) {
		
		printf("Give an integer (press 0 to exit): "); scanf("%d", &inputs);
		
		if (inputs == 0) {
		
			printf("Exiting 'countSum()'...\n");
			sum += inputs;
			local = 0;
			
		} else if (inputs < 0) {
		
			sum = sum + inputs;
			
		} else {
		
			sum += inputs;
		}
		// NOTE! If you put {sum += inputs;} here, SUMming happens twice!
	}
	
	return sum;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
