/**
 * @file Functions.c
 * @author Jooa Jaakkola (@benevolentimp)
 * @brief Implementation for various things.
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "Functions.h"


int inputNumber() 
{
	int inputted = 0;
	char temp = 0;
	int status = 0;

	printf("\n : ");
	status = scanf("%d", &inputted);
	temp = scanf("%c", &temp);

	while (status != 1) {
	
		printf("Please give a number...\n : ");
		status = scanf("%d", &inputted);
		temp = scanf("%c", &temp);
	}
	
	return inputted;
}