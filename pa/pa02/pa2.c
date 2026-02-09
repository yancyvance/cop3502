#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SCORES 5
#define INPUT_FILE "scores.txt"

/*
    COP 3502C PA2
    This program is written by: Your Full Name
*/

typedef struct Cat_s {
    char *name;             // Cat's name (dynamic string)
    char *breed;            // Cat's breed (dynamic string)
    int scores[MAX_SCORES]; // Fixed-sized array for the cat's 5 traits scores
    int baseScore;          // Sum of the cat's 5 traits scores
} Cat;

typedef struct Rivals_s {
    Cat *cat1;              // Pointer to cat1
    Cat *cat2;              // Pointer to cat2
} Rivals;


// Global Variables
const float POSITION_BONUS[10] = {3.0, 5.0, 4.0, 6.0, 7.0, 2.0, 8.0, 1.0, 9.0, 1.5}; 

// The following 4 variables are the only allowed GLOBAL variables.
// These variables can be used or accessed by any functions. They
// do not have to be declared within a function. Further, try to
// prevent declaring local variables using the same names within
// a function to prevent variable shadowing.

Cat *cats = NULL;
Rivals *rivals = NULL;
double bestPermScore;
int **tracker = NULL;


// Function Prototypes
void myMain(FILE *ifile);

// You may add more functions if necessary





// BEGIN: DO NOT MODIFY THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Open the input file for reading.
    // This is the only part of the entire code where the file
    // is going to be opened. You should not have any
    // fopen() function call in your functions. Simply
    // pass this existing FILE pointer when necessary.
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    // Calls your own main function and passes the file stream
    myMain(ifile);
    
    // Close the file
    fclose(ifile);
    
    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION





// Function Definitions
void myMain(FILE *ifile) {
    // TODO: Complete this function
    
    
    
    
    
}
