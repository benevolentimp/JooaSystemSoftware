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
	
	
	printf("First inputted integer is %d\nand the second one %d\n", firstInteger, secondInteger);
	
	return 0;
}
