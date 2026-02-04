#include <stdio.h>
#include <stdlib.h>

// Write a program that enumerates all binary strings of length 4.

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
    
    // The loop you are seeing is equivalent to 
    // the 2 pair of codes below it
    for(int i = 0; i < 2; i++) {
        // Try filling in this slot with i
        // Note that because of the loop, we have
        // two possible branches, the 0 branch
        // and the 1 branch
        arr[p] = i;
        
        // Recursive Case is asking the function
        // to go to the right and continue
        // filling in the remaining slots, one
        // slot at a time (per function call)
        solve(arr, n, p+1);
    }
    
    // Equivalent Behavior to Above:
    //arr[p] = 0;
    //solve(arr, n, p+1);
    //arr[p] = 1;
    //solve(arr, n, p+1);
}

void print_array(int *arr, int size) {
    // Helper function that prints the contents
    // of an array of integers with given size
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
