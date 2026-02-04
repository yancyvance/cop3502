#include <stdio.h>
#include <stdlib.h>

// Write a program that counts the number of subsets of
// a list of numbers where its sum is an odd number.

// Function Prototypes
int solve(int *arr, int n, int p, int *actual);
void print_array(int *arr, int n, int *actual);
int check_solution(int *arr, int n, int *actual);


int main(void) {
    // Dynamically provide the slot information
    int slots = 4;
    
    // Create the solution array that we will fill in
    // Think of this as the switches
    int *array = malloc(sizeof(int) * slots);
    
    // Assume that there are 4 numbers in the list
    int list[] = {3, 6, 7, 9};
    
    // Start solving the problem by using the array
    // as storage of the solution we are generating
    int final_result = solve(array, slots, 0, list);
    
    printf("Correct Solutions Found: %d\n", final_result);
    
    // Destroy the solution array
    free(array);
    
    return 0;
}


// Function Definitions
int solve(int *arr, int n, int p, int *actual) {
    // Base Case is when we have completely
    // filled the solution array (switches)
    if( p == n ) {
        // Print the candidate solution found
        // only if it is a correct one
        int res = check_solution(arr, n, actual);
        
        // The printing here becomes optional
        // You can comment it out
        if( res )
            print_array(arr, n, actual);
            
        return res;
    }
    
    int partial = 0;
    
    // Get the sum of results for all the branches
    // which in this case is 2 branches
    for(int i = 0; i < 2; i++) {
        arr[p] = i;
        
        // Accumulate the correct solutions found
        // for each branch
        partial = partial + solve(arr, n, p+1, actual);
    }
    
    // Return the grand total of all branches
    return partial;
}

void print_array(int *arr, int size, int *actual) {
    // Helper function that prints the contents
    // of the actual array of integers with given size
    // and uses a parallel array to serve as switch
    // to determine whether it should print it or not
    printf("{ ");
    for(int i = 0; i < size; i++) {
        if( arr[i] )
            printf("%d ", actual[i]);
    }
    printf("}\n");
}

int check_solution(int *arr, int size, int *actual) {
    // Helper function that returns 1 if the candidate
    // is a correct solution to the problem; otherwise
    // it returns 0
    
    // Similar to the print_array(), we use the arr
    // as a switch to determine whether to add
    // the value to the sum accumulator or not
    int sum = 0;
    for(int i = 0; i < size; i++) {
        if( arr[i] )
            sum = sum + actual[i];
    }
    
    // Final decision, is the sum an odd number?
    return sum % 2 != 0;
}
