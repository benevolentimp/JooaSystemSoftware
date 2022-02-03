/*
Title:      Exercise3.c - Selection and iteration
Auhtor:     Jooa Jaakkola
Desc:       Programming basics -practise with arithmetic progression etc.
*/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // For seeing the max (integer) value

int apLoop();
int apLoopEven();

unsigned int randomGenerator();

unsigned int multiplication(unsigned int number); // max_value = 2,147,483,647 (2,1 billion)


int main() {

	unsigned int randomNumber = 0;
	//int main_iterator = 1;

    printf("The sum of arithmetic progression of one from 1 to 100 is %d.\n", apLoop());
    printf("The sum of arithmetic progression of even numbers from 1 to 1000 is %d.\n\n", apLoopEven());
    
    randomNumber = randomGenerator();
    printf("Initial random integer: %u\n##########################\n", randomNumber);
    
    //printf("LONG_MAX : %ld\n", (long) LONG_MAX);
    printf("After multiplying %u with itself and so on... we got: %u (before overflow)\n", randomNumber, multiplication(randomNumber));
    
    return 0;
}


/*
Arithmetic Progression:
*///////////////////////
int apLoop() {

    int result = 0;
	
	for (int i = 1; i < 101; i++) {
        
        result = result + i;
	}
	
	return result;
}

int apLoopEven() {

	int result = 0;
	
	for (int i = 1; i < 1001; i++) {
        
        if (i % 2 != 0) { // Iterate through each even number, EXCEPT when number is odd (replaces "continue").
        
        	i += 1;
        	
        }
        
        result = result + i;
     
	}
	
	return result;
}


/*
Random Number Generator:
*////////////////////////
unsigned int randomGenerator() {
	
	int local_iterator = 1;
	unsigned int number = 0;
    
	while (local_iterator) {
		
		srand(time(0)); // Setting the seed for random (rand()).
		number = rand() % ((20 + 1 - 2) - 2); // Using formula: ((max + 1 - min) - min)
		
		if (number == 0 || number == 1) { // Checks if number 0 OR 1, as rand() doesn't allow built-in min-range.
			
			srand(time(0));
			number = rand() % ((20 + 1 - 2) - 2);
			
		} else {
			
			local_iterator = 0;
		}
	}
	
	return number;
}


/*
More math applications:
*///////////////////////
unsigned int multiplication(unsigned int number) {
	
	//int result = 0;
	unsigned int uint_max = 4294967295;
	int local_iterator = 1;
	
	while (local_iterator) {
	
		number *= number;
		printf("Product atm == %u\n", number);
	
		if ((number > 0) && (number > (uint_max - number))) {
			local_iterator = 0;
		}
	}
	
	return number;
}


/*
eof
*/
