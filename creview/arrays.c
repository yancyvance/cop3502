#include <stdio.h>
#include <stdlib.h>

// Write a program that dynamically allocates a 2D array of whole numbers.

// TODO 2: Deallocate the dynamic 2D array

// TODO 3: Define a function that prints the numbers

// TODO 4: Define the constructor andn destructor functions

// TODO 5: Ask the user to indicate the dimensions

int main(void) {
    // 2D array with dimesions: 3 rows x 2 cols
    int rows = 3;
    int cols = 2;
    
    // TODO 1: Creates a 2D dynamic array of ints and initialize it
    int **data = malloc( sizeof(int *) * rows );

    for(int i = 0; i < cols; i++) {
        data[i] = malloc( sizeof(int) * cols );
        
        for(int j = 0; j < cols; j++) {
            data[i][j] = 100;   // 100 here is an arbitrary value
        }
    }



    return 0;
}
