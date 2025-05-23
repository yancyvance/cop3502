#include <stdio.h>
#define SIZE 10

// Sample C Implementation of linear search and binary search.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-05-23.


// function prototypes
int linear_search(int *, int, int);
int binary_search(int *, int, int);


int main(void) {
    int arr[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int query;
    
    // prompt the user to entery query
    printf("Query: ");
    scanf("%d", &query);
    
    // linear search
    printf("Linear Search:\n");
    if( linear_search( arr, SIZE, query ) )
        printf("Found!");
    else
        printf("Not Found!");
        
    printf("\n\n");
    
    // binary search
    printf("Binary Search:\n");
    if( binary_search( arr, SIZE, query ) )
        printf("Found!");
    else
        printf("Not Found!");
    
    return 0;
}


int linear_search(int *arr, int size, int query) {
    // check how many comparisons
    int counter = 0;
    int found = 0;  // default to not found
    
    for(int i = 0; i < size; i++) {
        counter++;
        
        if( arr[i] == query ) {
            // found
            found = 1;
            break;
        }
    }
    
    printf("Comparisons: %d\n", counter);
    
    return found;
}


int binary_search(int *arr, int size, int query) {
    int start = 0;
    int end = size-1;
    int mid;
    
    // check how many comparisons
    int counter = 0;
    int found = 0;  // default to not found
    
    while( start <= end ) {
        // compute mid index
        mid = start + (end-start) / 2;
        
        counter++;
        
        // check if this mid element is query
        if( arr[mid] == query ) {
            found = 1;
            break;
        }
            
        // otherwise, check if query is to
        if( query < arr[mid] )
            // the left of the current element
            end = mid - 1 ;
        else
            // the right of the current element
            start = mid + 1;
    }
    
    printf("Comparisons: %d\n", counter);
    
    return found;
}
