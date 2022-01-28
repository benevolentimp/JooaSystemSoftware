/*////////////////////////////////////////////////////
Title:		Exercise2 - Basics for C
Author:		Jooa Jaakkola
Desc:		Exercise 2, which contains coding habit practise
            for eg. conditions, loops and data-types.
*////////////////////////////////////////////////////

#include <stdio.h> // "standard input-output"
#include <stdlib.h> // "standard library"
#include <math.h>
#include <time.h>

const char* comparison(int fI, int sI); // Initialises a function that returns a string.

/*
Initialize functions for arithmetic operations:
*/
int sum(int fI, int sI);
int diff(int fI, int sI);
int pro(int fI, int sI);
double divi(int fI, int sI);
double mean(int fI, int sI);

/*
Initialize functions regarding randomGenerator:
*/
int randomGenerator(void);
const char* EvenOrOdd(int RNG);
const char* IsItDivisible(int RNG);
// int loopArray(int array, int RNG);


int main() {	

	int firstInteger, secondInteger;
	
	int summa, erotus, tulo, pot;
	double jako, kA;
	
	int randomNumber;

    int integers[10] = {1,21,66,0,69,22,11,13,65};

    int inArray;
	
	
	printf("Give an integer: ");
	scanf("%d", &firstInteger); // NOTE: input prompt right after previous printf()!
	
	printf("Give another integer: ");
	scanf("%d", &secondInteger);
	
	if (firstInteger + secondInteger == 15) {
		printf("Your integers make %d%d... Nice ;)\n\n", firstInteger, secondInteger);
	} else if (firstInteger == secondInteger) {
		printf("Your integers are double %ds\n\n", firstInteger); // You only need 1 argument for this formatting.
	} else {
		printf("Your integers are %d and %d\n\n", firstInteger, secondInteger);
	}

	printf("%s", comparison(firstInteger, secondInteger)); // Function call and giving it parameters.
	
    
	/*
    Function calls and outputs for arithmetic operations:
    */
	summa = sum(firstInteger, secondInteger);
	printf("The sum of your integers is %d\n", summa);
	
	erotus = diff(firstInteger, secondInteger);
	printf("The difference between your integers is %d\n", erotus);
	
	tulo = pro(firstInteger, secondInteger);
	printf("The product of your integers is %d\n", tulo);
	
	jako = divi(firstInteger, secondInteger);
	printf("The division of your integers is %.2f\n", jako);
	
	kA = mean(firstInteger, secondInteger);
	printf("The average between your two integers is %.2f\n", kA);
	
	pot = pow(firstInteger, secondInteger);
	printf("Your first number to the power of the second one is %d\n\n", pot);
	
    
    /*
    Function calls and outputs for everything regarding randomNumber:
    */
	randomNumber = randomGenerator();
	printf("Generated number is %d, ", randomNumber);
	printf("and it's considered %s.\n", EvenOrOdd(randomNumber));
	printf("The number is also %s.\n\n", IsItDivisible(randomNumber));
    

    /*
    Fiddling with our array:
    */
    
    // From integers[0] to integers[9]:
    for (int i = 0; i < 10; i++) {
        if (i == 9) { // if-conditional to make loop print numbers neatly.
            printf("%d\n", integers[i]);        
        } else {
            printf("%d, ", integers[i]);
        }
    }
    
    // From integers[9] to integers[0]:
    for (int j = 9; j > -1; j--) {
        if (j == 0) {
            printf("%d\n", integers[j]);        
        } else {
            printf("%d, ", integers[j]);
        }
    }
    
	// Looping array while inspecting it:
    for (int k = 0; k < 10; k++) {
        if (integers[k] == randomNumber) {
            inArray = 1;
        } else {
            inArray = 0;
        }
    }
    
    switch (inArray) {
    
    case 1:
        printf("Randomly generated number %d is in array[10].\n", randomNumber);
        break;
    
    case 0:
        printf("Randomly generated number %d IS NOT in array[10].\n", randomNumber);
        break;
    }


	return 0; // The main function doesn't return anything, yet...
}


/*
Comparison of prompted integers returning a string:
*/
const char* comparison(int fI, int sI) {
	
	if (fI > sI) {
	
		return ("Your first input is bigger than the second one.\n\n");
		
	} else if (sI > fI) {
	
		return ("Your second input is bigger than the first one.\n\n");
		
	} else if (fI == sI) {
	
		return "Both of your inputs are identical, yay!!!\n\n";
	}
	
	return 0;
}


/*
A bunch of arithmetic operations:
*/
int sum(int fI, int sI) { // SUM
	
	int resultSum;
	
	resultSum = fI + sI;
	
	return resultSum;
}

int diff(int fI, int sI) { // DIFFERENCE
    
	int resultDiff;
	
	if (fI > sI) { // Using a condition in order to not get negatives (Bigger - Smaller).
		resultDiff = fI - sI;
		return resultDiff;
	} else if (sI > fI) {
		resultDiff = sI - fI;
		return resultDiff;
	} else if (fI == sI) {
		return 0;
	}
	
	return 0;
}

int pro(int fI, int sI) { // PRODUCT

	int resultPro;
	
	resultPro = fI * sI;
    
	return resultPro;
}

double divi(int fI, int sI) { // DIVIDE
    
	double resultDivi;
    
	if (sI == 0) {
		fprintf(stderr, "ZeroDivisionError, exiting execution...\n"); // Handling zero division with a library.
		exit(-1);
	} else {
		resultDivi = (double) fI / (double) sI; // Type-casting "passes" into correct type.
		return resultDivi;
	}
}

double mean(int fI, int sI) { // MEAN
    
	double resultMean;
    
	resultMean = ((double) fI + (double) sI) / 2;
    
	return resultMean;
}


/*
randomGenerator and using it:
*/
int randomGenerator(void) {
	
	int number;
    
	srand(time(0)); // Setting the seed for random (rand()).
	
	number = rand() % 101; // Using formula: ((max + 1 - min) - min)
	
	return number;
}

const char* EvenOrOdd(int RNG) {
	
	if (RNG == 0) {
		return "0 is considered neither odd nor even.";
	} else {
		if (RNG % 2 == 0) {
			return "even"; // Function ends early if condition met. Is it ok?
		} else if (RNG % 2 != 0) {
			return "odd";
		}
	}
	
	return 0;
}

const char* IsItDivisible(int RNG) {
	
	if ((RNG%4 && RNG%7) == 0) { // AND-operator is strict and thus you only need this and else.
		return "divisible by both 4 and 7, lucky find!!!";
	} else {
		return "not divisible by either 4 or 7";
	}
}


/* 
eof 
*/
