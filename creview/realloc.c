#include <stdio.h>
#include <stdlib.h>

// Function Prototype
void print_array(int *arr, int size);


int main(void) {
    int size = 4;
    
    // Originally allocate a dynamic array with 4 elements
    int *arr = malloc(sizeof(int) * size);
    
    // TODO: Populate the array
    
    
    
    // Resize the array to accomodate one more element
    int *tmp = realloc(arr, sizeof(int)*(size+1));
    
    // Update the value of size
    size++;
    
    // Check if realloc() is successful
    if( tmp != NULL ) {
        arr = tmp;
    }
    
    // TODO: Fill in the value of the new element
    
    
    
    // Deallocate the dynamic array
    free(arr);

    return 0;
}


// Function Definition
void print_array(int *arr, int size) {
    // Print the numbers
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
