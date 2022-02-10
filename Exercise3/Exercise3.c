/*
Title:      Exercise3.c - Selection and iteration
Auhtor:     Jooa Jaakkola
Desc:       Programming basics -practise with arithmetic progression etc.
*/////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // For seeing the max (integer) value
#include <math.h>

int apLoop();
int apLoopEven();

int randomGenerator();
int underHundo();
int overHundoTouso();

int multiplication(int number); // max_value = 2,147,483,647 (2,1 billion)

int collatz(int number);
int isFibonacci(int x);
int isPerfectSquare(int x);


int main() {

	int randomNumber = 0;
	int n = 0; // Mathematical integer-variable.
	
	int main_iterator = 1;
	int rounds = 0;
	

	printf("A couple of arithmetic progressions:\n#####################################\n");
    printf("The sum of arithmetic progression of one from 1 to 100 (or 10) is %d.\n", apLoop());
    printf("The sum of arithmetic progression of even numbers from 1 to 1000 (or 10) is %d.\n\n", apLoopEven());
    
    randomNumber = randomGenerator();
    printf("Initial random integer: %d\n##########################\n", randomNumber);
    
    //printf("LONG_MAX : %ld\n", (long) LONG_MAX);
    printf("After multiplying %d (initial) with itself and so on...", randomNumber);
    printf("we got: %d (before overflow)\n\n", multiplication(randomNumber));
    
    
    /*
    Collatz sequence:
    */////////////////
    n = underHundo();
    
    printf("Initial random number for Collatz: %d\n######################################\n", n);
    
    if (n == 0 || n < 0) {

        printf("Collatz sequence doesn't make sense for %d! Generating new number...\n\n", n);
        n = underHundo();
    }
    
    printf("Collatz sequence for %d is: %d – ", n, n); // Continues from same line (in loop)!
    while (main_iterator) {    	

    	if (n == 0 || n < 0) { // Checking again in case of "bad luck"...
    		
    		printf("Collatz sequence doesn't make sense for %d! Generating new number...\n", n);
            n = underHundo();
    		printf("Collatz sequence for %d is: %d – ", n, n);
    		
    	} else if (n == 1) {
            
            printf("\n");
            main_iterator = 0;

        } else {
    	   
    	    /* Checking the Collatz-math: */
    		if (n % 2 == 0) {
    			
    			n /= 2;
    			
    			if (n == 1) { // This conditional makes a linebreak at the end of the sequence.
    				
    				rounds++;
    				printf(" %d\n", n);
    				main_iterator = 0;
    				
    			} else {
    				
    				rounds++;
    				printf(" %d –", n); // "_%d_–"
    			}
    		
    		} else {
    			
    			n = n * 3 + 1;
    			rounds++;
    			printf(" %d –", n);
    		}
    		
    	}
    } // End of While
    
    printf("Length of the sequence is: %d\n\n", rounds+1);
    
    
    int nro = overHundoTouso();
    int IsItFibonacci = isFibonacci(nro);
    
    printf("Is this number (%d) in Fibonacci sequence?\n##############################################\n", nro);
    
    if (IsItFibonacci == 1) {
    
    	printf("The randomly generated number %d IS a Fibonacci-number.\n", nro);
    	
    } else if (IsItFibonacci == 0 || IsItFibonacci < 0) {
    
    	printf("The randomly generated number %d IS NOT a Fibonacci-number.\n", nro);
    	nro = overHundoTouso();
    }
    
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
Random Number Generators:
*/////////////////////////
int randomGenerator() {
	
	int local_iterator = 1;
	int number = 0;
    
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

int underHundo() {
	
	int number = 0;
	
	srand(time(0));
	number = rand() % ((100 + 1 - 0) - 0); // Using formula: ((max + 1 - min) - min)
	
	return number;
}

int overHundoTouso() {

	int number = 0;
	
	srand(time(0));
	number = rand() % ((99999 + 1 - 0) - 0); // Using formula: ((max + 1 - min) - min)
	
	return number;
}



/*
More math applications:
*///////////////////////
int multiplication(int number) {
	
	int rounds = 0;
	int result = 0; // Using a different variable for actual result (and function return)!
	int int_max = 2147483647;
	int int_min = -2147483647;
	int local_iterator = 1;
	
	if (number == 0 || number == 1 || number == -1 || number < 0) {
	
		printf("Oops, this is not going to work with a %d! Generating a new number...\n", number);
		number = randomGenerator();
		printf("New number is => %d\n", number);
		
	} else if (number < 0) {
		
		while (local_iterator) {
	
			number = number * number;
			
			if (number < (int_min) || number == 0) {
				local_iterator = 0;
			
			} else {
			
				result = number;
				rounds++;
				printf("Round %d: %d\n", rounds, result); 
			}
		}
	}
		
		while (local_iterator) {
	
			number = number * number;
	
			/* Using a couple of OR:s to rule out unpredictable behaviour from overflow. */
			if (number > (int_max) || number < 0 || number == 0) {
				local_iterator = 0;
			
			} else {
			
				result = number;
				rounds++;
				printf("Round %d: %d\n", rounds, result); 
			}
		}
	
	return result;
}

int isPerfectSquare(int x) {

	int s = (int) sqrt(x);
	return (s*s == x);
}

/*
Based on a mathematical rule about fibonacci-sequence. Then a Logic-operand:
*/
int isFibonacci(int x) {
	
	int result = 0;
	
	if (x < 0) {
		
		result = isPerfectSquare(5*x*(-x) + 4) || isPerfectSquare(5*x*(-x) - 4);
	} else {
	
		result = isPerfectSquare(5*x*x + 4) || isPerfectSquare(5*x*x - 4);
	}
	
	return result;
}


/*
eof
*/
