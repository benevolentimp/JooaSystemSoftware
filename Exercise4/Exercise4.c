/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Title:      Exercise4.c - Basics of Functions
Auhtor:     Jooa Jaakkola
Desc:       Programming basics - Learning to divide code into "function-blocks"
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int askingNumbers();
int countNegatives();
int countSum();
int countSumPlus();
int randomNumberGenerator(int first, int second);

int main() {

	int randomNumber = 0;
	
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
	
	/////////////////////////////////////////////////////////////////
	/* Exercise_4 4a – Loop to generate 2 parameters from console. */
	
	randomNumber = randomNumberGenerator(0, 120); // note: CHANGE MANUALLY!
	
	printf("Generated 'randomNumber' is: %d\n", randomNumber);
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
		
		printf("Give an integer for counting negatives (press 0 to exit): "); scanf("%d", &inputs);
		
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
		
		printf("Give an integer for summing them (press 0 to exit): "); scanf("%d", &inputs);
		
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
		
		printf("Give an integer for summing positives divisible by three (press 0 to exit): "); scanf("%d", &inputs);
		
		if (inputs == 0) {
		
			printf("Exiting 'countSumPlus()'...\n");
			local = 0;
			
		} else if ((inputs > 0) && (inputs % 3 == 0)) {
		
			sum += inputs;
		}
	}
	
	return sum;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int randomNumberGenerator(int first, int second) {
	
	int randomNumber = 0;
	
	srand(time(0));
		
	if (first > second) {
			
		randomNumber = (rand() % (first - second + 1)) + second;
			
	} else if (second > first) {
			
		randomNumber = (rand() % (second - first + 1)) + first;
			
	} else if (first == second) { // If inputs are equal, no "MIN_RANGE".
			
		randomNumber = rand() % (first + 1);
	}
		
	return randomNumber;
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
