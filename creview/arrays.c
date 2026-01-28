#include <stdio.h>
#include <stdlib.h>

// Write a program that dynamically allocates a 2D array of whole numbers.

// Function Prototypes
int **create_array(int r, int c);
void destroy_array(int **arr, int size);
void print_array(int **arr, int r, int c);


int main(void) {
    // 2D array with dimesions: rows x cols
    int rows;
    int cols;
    
    // TODO 5: Ask the user to indicate the dimensions
    scanf("%d", &rows);
    scanf("%d", &cols);
    
    // TODO 1: Creates a 2D dynamic array of ints and initialize it
    int **data = create_array(rows, cols);
    
    // Process
    print_array(data, rows, cols);

    // TODO 2: Deallocate the dynamic 2D array
    destroy_array(data, rows);

    return 0;
}


// Function Definitions

// TODO 4: Define the constructor and destructor functions
int **create_array(int r, int c) {
    // Strategy: Top-down (parent array then child arrays)
    int **data = malloc( sizeof(int *) * r );

    for(int i = 0; i < r; i++) {
        data[i] = malloc( sizeof(int) * c );
        
        for(int j = 0; j < c; j++) {
            data[i][j] = 100;   // 100 here is an arbitrary value
        }
    }
    
    return data;
}

void destroy_array(int **arr, int size) {
    // Strategy: Bottom-up (Child arrays then parent array)
    for(int i = 0; i < size; i++) {
        free( arr[i] );
    }
    
    free( arr );
}

// TODO 3: Define a function that prints the numbers
void print_array(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
