/*
Title:		Exercise2 - Basics for C
Author:		Jooa Jaakkola
Desc:		
*/

#include <stdio.h>


int main() {	

	int firstInteger;
	int secondInteger;
	
	printf("Give an integer: ");
	scanf("%d", &firstInteger); //goes right after the printf!!!
	
	printf("Give another integer: ");
	scanf("%d", &secondInteger);
	
	printf("First inputted integer is %d\nand the second one %d\n\n", firstInteger, secondInteger);
	
	
	if (firstInteger > secondInteger) {
		printf("Your first input %d is bigger than the second one %d\n\n", firstInteger, secondInteger);
	} 
	if (secondInteger > firstInteger){
		printf("Your second input %d is bigger than the first one %d\n\n", secondInteger, firstInteger);
	} else if (firstInteger == secondInteger){
		printf("Both of your inputs are identical, yay!!!\n");
		printf("%d == %d\n\n", firstInteger, secondInteger);
	}
	
	return 0;
}
