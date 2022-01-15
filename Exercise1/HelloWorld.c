/*
Title:      HelloWorld-program in C
Auhtor:     Jooa Jaakkola
Desc:       Just "printf" the string "Hello, World!!!" (with a linebreak) 
            within a necessary main()-function
*/

#include <stdio.h> // importing libraries (stdio.h for printf); '#' starts "prepocessor" commands

int main() {

    printf("Hello, World!!! "); // sentences end with semicolon; functions end with curlies
    printf("is a common phrase, \nwhen starting to learn programming. \n");
    
    return 0; // non void functions return always something!!! 0 == nothing special
    
}

/*
gcc (calls compiler)
-Wall (compiler option to show all warnings)
-Wextra (compiler option for more warnings)
-std=c11 (compiler option for)
HelloWorld.c (target file)
-o (flag)
HelloWorld (compiled "executable")
*/
