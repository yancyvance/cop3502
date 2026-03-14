#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE "scores.txt"
#define NUM_TRAITS 7
#define TOTAL_IDX 6
#define MAX_LEN 13
#define BASE_CASE_SIZE 30

/*
    COP 3502C PA4
    This program is written by: Your Full Name
*/

typedef struct Cat_s {
    char *name;         	   // Cat's name (unique)
    int scores[NUM_TRAITS];
} Cat;


// Global Variable
const char TRAITS[NUM_TRAITS][MAX_LEN] = {
    "Cuteness", "Fluffiness", "Agility", "Friendliness", 
    "Intelligence", "Laziness", "Total"
};


// Function Prototypes
void myMain(FILE *ifile);
int compareTo(Cat *ptrC1, Cat *ptrC2, int key);
void mergeSort(Cat **list, int n, int key);
void mergeSortRec(Cat **list, int low, int high, int key);
void quickSort(Cat **list, int n, int key);
void quickSortRec(Cat **list, int low, int high, int key);

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

int compareTo(Cat *ptrC1, Cat *ptrC2, int key) {
    // TODO: Complete this function
    // TODO 2 BEGIN





    // TODO 2 END
}

void mergeSort(Cat **list, int n, int key) {
    // TODO: Complete this function
    // TODO 3 BEGIN





    // TODO 3 END
}

void mergeSortRec(Cat **list, int low, int high, int key) {
    // TODO: Complete this function
    // TODO 4 BEGIN





    // TODO 4 END
}

void quickSort(Cat **list, int n, int key) {
    // TODO: Complete this function
    // TODO 5 BEGIN





    // TODO 5 END
}

void quickSortRec(Cat **list, int low, int high, int key) {
    // TODO: Complete this function
    // TODO 6 BEGIN





    // TODO 6 END
}
