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
int gradeCalc(int points);

int primeQuery();
int isPrime(int input);


int main() {
	
	int countedNegatives = 0;
	int countedSum = 0;
	int countedSumPlus = 0;
	
	int randomNumber = 0;
	int grade = 0;
	
	int input = 0;
	
	
	countedNegatives = countNegatives(); // E4 – 3a:
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

	countedSum = countSum(); // E4 – 3b:
	printf("The sum of your integers is: %d\n", countedSum);
	printf("\n################################\n\n");

	countedSumPlus = countSumPlus(); // E4 – 3c:
	printf("The sum of positive integers divisible by three is: %d\n", countedSumPlus);
	printf("\n################################\n\n");
	
	
	randomNumber = randomNumberGenerator(0, 120); // // E4 – 4a:
	printf("Generated 'randomNumber' is: %d\n", randomNumber);
	printf("\n################################\n\n");
	
	grade = gradeCalc(randomNumber); // E4 – 4b:
	if ((grade < 0) || (grade > 5)) {
		
		printf("Oops, something went wrong...\nInput out of range!\n");
		printf("\n################################\n\n");
		
	} else if (grade >= 0 && grade <= 5) {
		
		printf("Corresponding grade (0 – 5) for %d (0 – 120) is: %d\n", randomNumber, grade);
		printf("\n################################\n\n");
	}
	
	
	input = primeQuery(); // E4 – 5(a)b:
	printf("You entered: %d\n\n", input);
	
	switch (isPrime(input)) {
		
	case 0:
		printf("The number you entered is PRIME!\n");
		break;
	case 1:
		printf("The number you entered is NOT PRIME!\n");
		break;
	}
	
    
    return 0;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 3:
//////////

int countNegatives() {

	int local = 1;
	int inputs = 0;
	int negatives = 0;
	
	while (local) {
		
		printf("Give an integer for counting negatives (press 0 to exit): "); 
		scanf("%d", &inputs);
		
		if (inputs == 0) {
			
			printf("Exiting 'countNegatives()'...\n");
			local = 0;
			
		} else if (inputs < 0) {
		
			negatives++;
			
		}
	}
	
	return negatives;
}

int countSum() {
	
	int local = 1;
	int inputs = 0;
	int sum = 0;
	
	while (local) {
		
		printf("Give an integer for summing them (press 0 to exit): "); 
		scanf("%d", &inputs);
		
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

int countSumPlus() {
	
	int local = 1;
	int inputs = 0;
	int sum = 0;
	
	while (local) {
		
		printf("Give an integer for summing positives divisible by three (press 0 to exit): "); 
		scanf("%d", &inputs);
		
		if (inputs == 0) {
		
			printf("Exiting 'countSumPlus()'...\n");
			local = 0;
			
		} else if ((inputs > 0) && (inputs % 3 == 0)) {
		
			sum += inputs;
		}
	}
	
	return sum;
}

// Task 4:
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

int gradeCalc(int points) {

	int grade = 0;
	
	if ((points < 60) && (points >= 0)) {
		grade = 0;
	} else if ((points >= 60) && (points < 72)) {
		grade = 1;
	} else if ((points >= 72) && (points < 84)) {
		grade = 2;
	} else if ((points >= 84) && (points < 96)) {
		grade = 3;
	} else if ((points >= 96) && (points < 108)) {
		grade = 4;
	} else if ((points >= 108) && (points <= 120)) {
		grade = 5;
	}
	
	return grade;
}

// Task 5:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int primeQuery() {

	int int_max = 2147483647;
	int input = 0;
	char temp = 0; // "Garbage-collector"
	int status = 0; // Is input == "number"
	
	printf("Enter a number, please: ");
	status = scanf("%d", &input); // Make a "copy" of user input into "status".
	temp = scanf("%c", &temp); // Essentially bypassing scanf()'s built-in linebreak.
	
	while (status != 1)  {

		printf("Invalid input... please enter a NUMBER: ");
		status = scanf("%d", &input);
		temp = scanf("%c", &temp);
	}
	
	return input;
}

int isPrime(int input) {
	
	int i = 2;
	int flag = 0;
	
	// for-loop goes through every number below half of input and changes flag if divisible at any time.
	for (i = 2; i <= input/2; ++i) {
		
		if (input % i == 0) {
			
			flag = 1;
		}
	}
	
	if (input == 0 || input == 1) {
		
		printf("%d is neither prime nor composite!\n", input);
		
	} else if (input < 0){
		
		printf("%d is not prime because negative numbers aren't prime!\n", input);
		
	} else {
	
		if (flag == 0) {
		
			return flag; // PRIME
		}
		
		else {
		
			return flag; // NOT PRIME
		}
	}
	
	
	return 22; // The function should never reach here...
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
