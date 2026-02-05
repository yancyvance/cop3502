#include <stdio.h>
#include <stdlib.h>

// Write a program that accepts a series of numbers and
// stores them in an array in ascending order (increasing).
// The program stops asking for a number if the -1 
// sentinel is entered by the user or the logical size
// has reached the capacity of the backend array.

// Function Prototypes
void print_array(int *arr, int size);


int main(void) {
    // Allocate a dynamic array with capacity of 8
    int capacity = 8;
    int *arr = malloc( sizeof(int) * capacity );
    int logical_size = 0;
    int total_moves = 0;
    
    int num;
    while( logical_size < capacity ) {
        // Read a single number
        scanf("%d", &num);
        
        // Sentinel value is -1
        if( num == -1 )
            break;
        
        // Find the correct location
        int correct = logical_size;
        for(int i = 0; i < logical_size; i++) {
            // The correct location is found
            if( arr[i] > num ) {
                correct = i;
                break;
            }
        }
        
        // Shift elements to the right to provide
        // a space for the new number
        int moves = 0;
        for(int i = logical_size; i > correct; i--) {
            arr[i] = arr[i-1];
            moves++;
        }
        
        printf("\t%d Moves\n", moves);
        total_moves = total_moves + moves;
        
        // Put the number in the newly opened location
        arr[correct] = num;
        
        // Increment the logical size
        logical_size++;
        
        // For testing purposes
        print_array(arr, logical_size);
    }
    
    printf("Grand Total Moves %d\n", total_moves);
    
    // Deallocate the dynamic array
    free(arr);

    return 0;
}


// Function Definitions
void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
