#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE "logs.txt"

/*
    COP 3502C PA3
    This program is written by: Your Full Name
*/

typedef struct Cat_s {
    int arrival;            // Cat's arrival time at the clinic 
                            // Minutes since clinic opened (unique)
    char *name;             // Cat's unique name (dynamic string)
    int duration;           // Required treatment time in minutes
} Cat;

typedef struct SLLNode_s {
    Cat *cat;               // Pointer to a dynamically allocated Cat
    struct SLLNode_s *next;
} SLLNode;


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
