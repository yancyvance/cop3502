#include <stdio.h>

// Function Prototypes
void selection_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void bubble_sort_enhanced(int *arr, int size);
void print_array(int *arr, int size);
void swap(int *a, int *b);

int main(void) {
    int nums[] = {5, 3, 8, 4, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    // Before Sorting
    print_array(nums, size);
    
    // Sort the Array
    //selection_sort(nums, size);
    //insertion_sort(nums, size);
    //bubble_sort(nums, size);
    
    // After Sorting
    print_array(nums, size);
    
    return 0;
}

void selection_sort(int *arr, int size) {
    // Each iteration of the outer loop
    // determines the slot of the array
    // we are currently filling in.
    // The correct value that goes here
    // is the minimum value in the unsorted
    // region.
    for(int i = 0; i < size-1; i++) {
        // Assume that the current element
        // at this position is the minimum
        // value. Therefore, we remember
        // its "location" a.k.a. index.
        int min_idx = i;
        
        // Confirm this assumption by
        // inspecting the remaining elements.
        for(int j = i+1; j < size; j++) {
            // If there is an even smaller
            // value found, then we update
            // our assumption of where the
            // minimum value is located at.
            if( arr[j] < arr[min_idx] ) {
                min_idx = j;
            }
        }

        // After having seen all the remaining
        // elements, we simply put the minimum
        // value at the slot we are trying to
        // fill in. This is only done if the
        // minimum is found somewhere else.
        if( i != min_idx )
            swap( &arr[i], &arr[min_idx] );
    }
}

void insertion_sort(int *arr, int size) {
    // We assume that the 0-th element
    // is already sorted. Therefore the
    // task then is to insert the remaining
    // elements (those from the unsorted
    // region) into the sorted region.
    for(int i = 1; i < size; i++) {
        // Because we are dealing with an
        // array and we are "inserting"
        // elements in between, this will
        // involve the shifting behavior.
        // Therefore, we remember the element
        // we are trying to insert first as
        // there is a possibility that it
        // will be overwritten.
        int tmp = arr[i];
        int j;
        
        // The goal is to open a slot in the
        // sorted region which corresponds to
        // the correct location of the value
        // that we are trying to insert.
        // The idea then is to keep on asking
        // the elements in the sorted region
        // to move to the right by 1 position 
        // as long as there is still an element 
        // that we can shift AND what we want 
        // to insert is still lesser than the 
        // current element we are looking at.
        // The objective is to have variable j
        // stop at the index which is located
        // just before the actual location
        // where we want to insert the element.
        for(j = i-1; j >= 0 && tmp < arr[j]; j--) {
            arr[j+1] = arr[j];
        }
        
        // We want to insert the element to the
        // location just after variable j.
        arr[j+1] = tmp;
    }
}

void bubble_sort(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        // A single linear pass will have a
        // consequence of being able to push
        // the heaviest element to the rightmost
        // side of the array. Therefore, one
        // pass constitutes a single round.
        // Following such logic, we will simply
        // perform multiple rounds of this
        // linear pass to be able to "sort"
        // the array. That is the role of
        // the outer loop.
        for(int j = 0; j < size-1-i; j++) { 
            // If this element and its immediate
            // right neighbor are not in their
            // proper places (i.e., the element
            // to the right must be greater), then
            // swap the two values.
            if( arr[j] > arr[j+1] ) {
                swap( &arr[j], &arr[j+1] );
            }
        }
    }
}

void bubble_sort_enhanced(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        // Add a flag variable to determine if
        // there was a swap that happened for
        // this round of linear pass. Initially,
        // we assume that there is none.
        int swapped = 0;
        
        for(int j = 0; j < size-1-i; j++) {
            if( arr[j] > arr[j+1] ) {
                swap( &arr[j], &arr[j+1] );
                
                // If there is a swap, then
                // set the flag to 1 (true).
                swapped = 1;
            }
        }
        
        // After the round, if no swap
        // took place, there is no need to
        // do another round. Therefore, we
        // simply terminate.
        if( !swapped ) break;
    }
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
