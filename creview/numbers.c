#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMS 5

// Write a program that stores an arbitrary number of whole numbers.

// Function Prototypes
void print_array(int *arr, int size);
int *create_array(int size);
void destroy_array(int *arr);


int main(void) {
    // Declare an array
    //int arr[MAX_NUMS];            // array will be created in stack space
    
    // TODO 4: Ask the user to indicate the count of numbers to store
    int N;
    scanf("%d", &N);
    
    // call our helper function to create
    int *nums = create_array(N);    // array will be created in heap space
    
    
    // Read the numbers
    for(int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    
    // call our helper function to print
    print_array(nums, N);
    
    
    // call our helper function to destroy
    destroy_array(nums);            // do not forget to deallocate the array
    
    
    return 0;
}


// TODO 1: Define a function that prints the numbers
void print_array(int *arr, int size) {
    // Print the numbers
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

// TODO 2: Define a function that creates a dynamic array
int *create_array(int size) {
    int *arr = malloc( sizeof(int) * size );
    
    return arr;
}

// TODO 3: Define a function that deallocates a dynamic array
void destroy_array(int *arr) {
    free(arr);  // Use valgrind to confirm no memory leak
}
