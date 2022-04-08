/**
 * @file main.c
 * @author Jooa Jaakkola (@benevolentimp)
 * @brief Main-file from which every implementation should be called from.
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "Functions.h"

int main()
{
    int leetNum = 0;
    leetNum = inputNumber();
    switch (leetNum)
    {
        case 0:
            printf("Hello, W%drld!\n", leetNum);
            break;

        default:
            for (int i = 0; i < 69; ++i) 
            {
                printf("Hello, pl%db!\n", leetNum);
            }
            break;
    }

    return 0;
}