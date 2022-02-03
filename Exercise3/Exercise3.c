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

unsigned int randomGenerator();
int underHundo();
int overHundoTouso();

unsigned int multiplication(unsigned int number); // max_value = 2,147,483,647 (2,1 billion)
int collatz(int number);
int isFibonacci(int x);
int isPerfectSquare(int x);


int main() {

	unsigned int randomNumber = 0;
	int n = 0; // Mathematical integer-variable.
	
	int main_iterator = 1;
	int rounds = 0;
	

	printf("A couple of arithmetic progressions:\n#####################################\n");
    printf("The sum of arithmetic progression of one from 1 to 100 is %d.\n", apLoop());
    printf("The sum of arithmetic progression of even numbers from 1 to 1000 is %d.\n\n", apLoopEven());
    
    randomNumber = randomGenerator();
    printf("Initial random integer: %u\n##########################\n", randomNumber);
    
    //printf("LONG_MAX : %ld\n", (long) LONG_MAX);
    printf("After multiplying %u with itself and so on... we got: %u (before overflow)\n\n", randomNumber, multiplication(randomNumber));
    
    
    /*
    Collatz sequence:
    */////////////////
    n = underHundo();
    
    printf("Initial random number for Collatz: %d\n######################################\n", n);
    
    printf("Collatz sequence for %d is: %d – ", n, n); // Continues from same line (in loop)!
    
    while (main_iterator) {
    	
    	if (n == 0) {
    		
    		n = underHundo();
    		printf("Collatz sequence doesn't make sense for 0,\ngenerating new number...\t...%d...\n", n);
    		printf("Collatz sequence for %d is: %d – ", n, n);
    		
    	} else {
    	
    		if (n % 2 == 0) {
    			
    			n /= 2;
    			
    			if (n == 1) {
    				
    				rounds++;
    				printf("%d\n", n);
    				main_iterator = 0;
    				
    			} else {
    				
    				rounds++;
    				printf("%d – ", n);
    			}
    		
    		} else {
    			
    			n = n * 3 + 1;
    			rounds++;
    			printf("%d – ", n);
    		}
    		
    	}
    } // End of While
    
    printf("Length of the sequence is: %d\n\n", rounds+1);
    
    
    int nro = overHundoTouso();
    int IsItFibonacci = isFibonacci(nro);
    
    printf("Is this number (%d) in Fibonacci sequence?\n##############################################\n", nro);
    
    if (IsItFibonacci == 1) {
    
    	printf("The randomly generated number %d IS a Fibonacci-number.\n", nro);
    	
    } else if (IsItFibonacci == 0) {
    
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
unsigned int multiplication(unsigned int number) { // OPERATES WEIRDLY WITH EVEN RNG-INPUTS...
	
	//int result = 0;
	unsigned int uint_max = 4294967295;
	int local_iterator = 1;
	
	while (local_iterator) {
	
		number *= number;
		printf("Product atm == %u\n", number);
	
		if ((number > (uint_max - number))) { // Checks for int overflow BEFORE value_max!
			local_iterator = 0;
			
		} if ((number % 2 == 0)) {
			
			local_iterator = 0;
		}
	}
	
	return number;
}

/*
int collatz(int number) {
	
	int result = 0;
	int local_iterator = 1;
	
	while (local_iterator) {
	
		if (result == 0) {
		
			if (number % 2 == 0) {
	
				result = number / 2;
				
		
			} else {
			
				result = number * 3 + 1;
				
			}
			
		} else if (result > 1) {
			
			if (result % 2 == 0) {
	
				result /= 2;
				
				
		
			} else {
			
				result *= 3 + 1;
				
				
			}
			
		} else {
			
			local_iterator = 0;
		}
	}
	
	return 0;
}
*/

int isPerfectSquare(int x) {

	int s = (int) sqrt(x);
	return (s*s == x);
}

int isFibonacci(int x) {

	return isPerfectSquare(5*x*x + 4) || 
		   isPerfectSquare(5*x*x - 4); // Based on a mathematical rule about fibonacci-sequence. Then a Logic-operand...
}


/*
eof
*/
