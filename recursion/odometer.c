#include <stdio.h>
#include <stdlib.h>

// Write a program that enumerates all numbers of length 4.

// Function Prototypes
void solve(int *arr, int n, int p);
void print_array(int *arr, int n);


int main(void) {
    // Dynamically provide the slot information
    int slots = 4;
    
    // Create the solution array that we will fill in
    int *array = malloc(sizeof(int) * slots);
    
    // Start solving the problem by using the array
    // as storage of the solution we are generating
    solve(array, slots, 0);
    
    // Destroy the solution array
    free(array);
    
    return 0;
}


// Function Definitions
void solve(int *arr, int n, int p) {
    // Base Case is when we have completely
    // filled the solution array
    if( p == n ) {
        // Print the candidate solution found
        print_array(arr, n);
        return;
    }
    
    for(int i = 0; i < 10; i++) {
        // Try filling in this slot with i
        // Note that because of the loop, we have
        // ten possible branches, the 0 branch,
        // the 1 branch, ... , the 9 branch
        arr[p] = i;
        
        // Recursive Case is asking the function
        // to go to the right and continue
        // filling in the remaining slots, one
        // slot at a time (per function call)
        solve(arr, n, p+1);
    }
}

void print_array(int *arr, int size) {
    // Helper function that prints the contents
    // of an array of integers with given size
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
