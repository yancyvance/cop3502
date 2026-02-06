#include <stdio.h>
#include <stdlib.h>

// Write a program that counts the number of permutation of 
// 4 distinct symbols where the first number is lesser
// than the last number.

// Function Prototypes
int solve(int *arr, int n, int p, int *actual, int *is_used);
void print_array(int *arr, int n);
int check_solution(int *arr, int n);


int main(void) {
    // Dynamically provide the slot information
    int slots = 4;
    
    // Create the solution array that we will fill in
    // The elements used to fill in will be coming
    // from the actual array of symbols
    int *array = malloc(sizeof(int) * slots);
    
    // Assume that there are 4 numbers in the list
    int symbols[] = {3, 6, 7, 9};
    
    // Dynamically allocate an array of integer (flags)
    // that are all initialized to 0 (off/unused)
    int *is_used = calloc(slots, sizeof(int));
    
    // Start solving the problem by using the array
    // as storage of the solution we are generating
    int final_result = solve(array, slots, 0, symbols, is_used);
    
    printf("Correct Solutions Found: %d\n", final_result);
    
    // Destroy the solution array
    free(array);
    
    // Destroy the flag array
    free(is_used);
    
    return 0;
}


// Function Definitions
int solve(int *arr, int n, int p, int *actual, int *is_used) {
    // Base Case is when we have completely
    // filled the solution array
    if( p == n ) {
        // Print the candidate solution found
        // only if it is a correct one
        int res = check_solution(arr, n);
        
        if( res )
            print_array(arr, n);
            
        return res;
    }
    
    int partial = 0;
    
    // There are n symbols available to use
    // Strategy: 3 parallel arrays
    for(int i = 0; i < n; i++) {
        // Try filling this slot with an unused 
        // symbol only
        if( !is_used[i] ) {
            // Copy the actual symbol to the
            // slot of the solution array
            arr[p] = actual[i];
            
            // Mark the symbol as used
            is_used[i] = 1;
        
            // Accumulate the correct solutions found
            // for each branch
            partial = partial + solve(arr, n, p+1, actual, is_used);
            
            // Unmark the symbol and try the next branch
            is_used[i] = 0;
        }
    }
    
    // Return the grand total of all branches
    return partial;
}

void print_array(int *arr, int size) {
    // Helper function that prints the contents
    // of an array of integers with given size
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int check_solution(int *arr, int size) {
    // Helper function that returns 1 if the candidate
    // is a correct solution to the problem; otherwise
    // it returns 0
    
    // Final decision, is the first number lesser than
    // the last number?
    return arr[0] < arr[size-1];
}
