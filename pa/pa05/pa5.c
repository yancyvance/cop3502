#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_FILE "tournament.txt"
#define MAX_LEN 25
#define NUM_TRAITS 5

/*
    COP 3502C PA5
    This program is written by: Your Full Name
*/

typedef struct Cat_s {
    char *name;                 // dynamically allocated cat name
    char *breed;                // dynamically allocated cat breed
    int charm;                  // unique charm score
    int traits[NUM_TRAITS];     // values corresponding to TRAIT_NAMES
} Cat;

typedef struct BSTNode_s {
    Cat *cat;
    struct BSTNode_s *left;
    struct BSTNode_s *right;
    int subtree_size;           // size of this subtree, not height
} BSTNode;


// Global Variable
const char TRAITS[NUM_TRAITS][MAX_LEN] = {
    "friendly", "grumpy", "playful", "lazy", "curious"
};


// Function Prototypes
void myMain(FILE *ifile);
char **filterByTrait(BSTNode *root, int traitIndex, int traitValue, int *resultSize);

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
    // TODO 1 BEGIN





    // TODO 1 END
}

char **filterByTrait(BSTNode *root, int traitIndex, int traitValue, int *resultSize) {
    // TODO: Complete this function
    // TODO 2 BEGIN





    // TODO 2 END
}
