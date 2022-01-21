/*
Title:		Exercise2 - Basics for C
Author:		Jooa Jaakkola
Desc:		
*/

#include <stdio.h>
const char* comparison(int fI, int sI);

int main(void) {	

	int firstInteger;
	int secondInteger;
	
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

	printf("%s\n", comparison(firstInteger, secondInteger)); //function call and giving it the parameter values
	
	
	return 0;
}

const char* comparison(int fI, int sI) {
	
	if (fI > sI) {
	
		return ("Your first input is bigger than the second one.\n\n");
		
	} else if (sI > fI){
	
		return ("Your second input is bigger than the first one.\n\n");
		
	} else if (fI == sI) {
	
		return "Both of your inputs are identical, yay!!!\n\n";
	}
}
