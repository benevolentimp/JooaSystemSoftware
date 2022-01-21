/*
Title:		Exercise2 - Basics for C
Author:		Jooa Jaakkola
Desc:		Exercise 2, which contains coding habit practise
            for eg. conditions, loops and data-types.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

const char* comparison(int fI, int sI);

int sum(int fI, int sI);
int diff(int fI, int sI);
int pro(int fI, int sI);
double divi(int fI, int sI);
double mean(int fI, int sI);

int randomGenerator(void);
const char* EvenOrOdd(int RNG);
const char* IsItDivisible(int RNG);
int DoesArrayHave(int integers, int RNG);

int loopArray(int array);

int integers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(void) {	

	int firstInteger, secondInteger;
	
	int summa, erotus, tulo, pot;
	double jako, kA;
	
	int randomNumber;
	
	
	printf("Give an integer: ");
	scanf("%d", &firstInteger); //goes right after the printf!!!
	
	printf("Give another integer: ");
	scanf("%d", &secondInteger);
	
	if (firstInteger + secondInteger == 15) {
	
		printf("Your integers make %d%d... Nice ;)\n\n", firstInteger, secondInteger);
	
	} else if (firstInteger == secondInteger) {
	
		printf("Your integers are double %ds\n\n", firstInteger, secondInteger);
		
	} else {
	
		printf("Your integers are %d and %d\n\n", firstInteger, secondInteger);
	}


	printf("%s", comparison(firstInteger, secondInteger)); //function call and giving it the parameter values
	
	
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
	
	randomNumber = randomGenerator();
	printf("Generated number is %d, ", randomNumber);
	printf("and it's considered %s.\n", EvenOrOdd(randomNumber));
	printf("The number is also %s.\n\n", IsItDivisible(randomNumber));
    
    printf("%d\n", loopArray(integers));
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int sum(int fI, int sI) {
	
	int resultSum;
	
	resultSum = fI + sI;
	
	return resultSum;
}

int diff(int fI, int sI) {
	int resultDiff;
	
	if (fI > sI) {
		resultDiff = fI - sI;
		return resultDiff;
	} else if (sI > fI) {
		resultDiff = sI - fI;
		return resultDiff;
	} else if (fI == sI) {
		return 0;
	}
}

int pro(int fI, int sI) {
	int resultPro;
	
	resultPro = fI * sI;
	return resultPro;
}

double divi(int fI, int sI) {
	double resultDivi;
	if (sI == 0) {
		fprintf(stderr, "ZeroDivisionError, exiting execution...\n"); // handling zero division with a library
		exit(-1);
	} else {
		resultDivi = (double) fI / (double) sI; // type-casting "passes" into correct type
		return resultDivi;
	}
}

double mean(int fI, int sI) {
	double resultMean;
	resultMean = ((double) fI + (double) sI) / 2;
	return resultMean;
}

////////////////////////////
int randomGenerator(void) {
	
	int number;
	srand(time(0)); //sets the seed for randomness
	
	number = rand() % 101; //((max+1 - min) - min)
	
	
	return number;
}

/////////////////////////////////
const char* EvenOrOdd(int RNG) {
	
	if (RNG == 0) {
		return "0 is considered neither odd nor even.";
	} else {
		if (RNG % 2 == 0) {
			return "even";
		} else if (RNG % 2 != 0) {
			return "odd";
		}
	}
}

/////////////////////////////////////
const char* IsItDivisible(int RNG) {
	
	if ((RNG%4 && RNG%7) == 0) {
		return "divisible by both 4 and 7, lucky find!!!"; // wanted to add (nested?) clause for 4 but not 7...
	} else {
		return "not divisible by either 4 or 7";
	}
}

/////////////////////////////////////////
const char* comparison(int fI, int sI) {
	
	if (fI > sI) {
	
		return ("Your first input is bigger than the second one.\n\n");
		
	} else if (sI > fI) {
	
		return ("Your second input is bigger than the first one.\n\n");
		
	} else if (fI == sI) {
	
		return "Both of your inputs are identical, yay!!!\n\n";
	}
}

///////////////////////////
int loopArray(int array) {
    
    int i, j;    
    
    for (i = 0; i < 10; i++) {
        
        if (i == 9) {
            printf("%d\n", integers[i]);
        } else {
            printf("%d", integers[i]);
        }
    }
    
    for (j = i; j > 0; j--) {
        
        if (i == 9) {
            printf("%d\n", integers[j-1]);
        } else {
            printf("%d", integers[j-1]);
        }
    }
    
    return 0;
}


int DoesArrayHave(int integers, int RNG) {
    
    int i;    

    
}


/* 
eof 
*/
