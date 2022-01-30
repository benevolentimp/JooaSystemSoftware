/*
Title:      Exercise3.c - Selection and iteration
Auhtor:     Jooa Jaakkola
Desc:       Programming basics -practise with arithmetic progression etc.
*/////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int apLoop();
int apLoopEven();


int main() {

    printf("The sum of arithmetic progression of one from 1 to 100 is %d.\n\n", apLoop());
    
    printf("The sum of arithmetic progression of even numbers from 1 to 1000 is %d.\n\n", apLoopEven());
    
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
eof
*/
