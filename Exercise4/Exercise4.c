/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Title:      Exercise4.c - Basics of Functions
Auhtor:     Jooa Jaakkola
Desc:       Programming basics - Learning to divide code into "function-blocks"
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int askingNumbers();
int countNegatives();
int countSum();
int countSumPlus();

int main() {
	
	/////////////////////////////////////////////////////////////////
	/* Exercise_4 3a – Conditions for accurate grammar in output. */
	int countedNegatives = countNegatives();
	
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
	////////////////////
	/* Exercise_4 3b */
	int countedSum = countSum();
	
	printf("The sum of your integers is: %d\n", countedSum);
	printf("\n################################\n\n");
	
	////////////////////
	/* Exercise_4 3c */
	int countedSumPlus = countSumPlus();
	
	printf("The sum of positive integers divisible by three is: %d\n", countedSumPlus);
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

int countSumPlus() {
	
	int local = 1;
	int inputs = 0;
	int sum = 0;
	
	while (local) {
		
		printf("Give an integer (press 0 to exit): "); scanf("%d", &inputs);
		
		if (inputs == 0) {
		
			printf("Exiting 'countSumPlus()'...\n");
			local = 0;
			
		} else if ((inputs > 0) && (inputs % 3 == 0)) {
		
			sum += inputs;	
		}
	}
	
	return sum;
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
