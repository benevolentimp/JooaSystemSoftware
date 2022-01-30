/*
Title:      Exercise3.c - Selection and iteration
Auhtor:     Jooa Jaakkola
Desc:       
*/

#include <stdio.h>

int apLoop();


int main() {

    printf("The sum of arithmetic progression of one from 1 to 10 is %d.\n\n", apLoop());
    
    return 0;
}


int apLoop() {

    int result = 0;
	
	for (int i = 1; i < 11; i++) {
        
        result = result + i;
	}
	
	return result;
}

/*
eof
*/
