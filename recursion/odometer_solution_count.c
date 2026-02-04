#include <stdio.h>
#include <stdlib.h>

// Write a program that counts the number of numbers 
// of length 4 that has at least three 8s in it.

// Function Prototypes
int solve(int *arr, int n, int p);
void print_array(int *arr, int n);
int check_solution(int *arr, int n);


int main(void) {
    // Dynamically provide the slot information
    int slots = 4;
    
    // Create the solution array that we will fill in
    int *array = malloc(sizeof(int) * slots);
    
    // Start solving the problem by using the array
    // as storage of the solution we are generating
    int final_result = solve(array, slots, 0);
    
    printf("Correct Solutions Found: %d\n", final_result);
    
    // Destroy the solution array
    free(array);
    
    return 0;
}


// Function Definitions
int solve(int *arr, int n, int p) {
    // Base Case is when we have completely
    // filled the solution array
    if( p == n ) {
        // Print the candidate solution found
        // only if it is a correct one
        int res = check_solution(arr, n);
        
        // The printing here becomes optional
        // You can comment it out
        if( res )
            print_array(arr, n);

        return res;
    }
    
    int partial = 0;
    
    // Get the sum of results for all the branches
    // which in this case is 10 branches
    for(int i = 0; i < 10; i++) {
        arr[p] = i;
        
        // Accumulate the correct solutions found
        // for each branch
        partial = partial + solve(arr, n, p+1);
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
    
    // Count how many 8s there are in the array
    int count = 0;
    for(int i = 0; i < size; i++) {
        if( arr[i] == 8 )
            count++;
    }
    
    // Final decision, are there at least three 8s?
    return count >= 3;
}
