#include <stdio.h>

// Function Prototypes
int linear_search(int *arr, int size, int query);
int binary_search(int *arr, int size, int query);


int main(void) {
    int nums[] = {10, 20, 30, 40};
    int nums2[] = {5, 10, 15, 20};
    int size = 4;
    
    // Strategy 1
    printf("Strategy 1: Linear Search\n");
    for(int i = 0; i < size; i++) {
        if( linear_search( nums, size, nums2[i] ) )
            printf("\t%d is Found\n", nums2[i]);
    }
    
    printf("\n");
    
    // Strategy 2
    printf("Strategy 2: Binary Search\n");
    for(int i = 0; i < size; i++) {
        if( binary_search( nums, size, nums2[i] ) )
            printf("\t%d is Found\n", nums2[i]);
    }
    
    printf("\n");
    
    // Strategy 3
    printf("Strategy 3: Linear Walk\n");
    int i = 0, j = 0;
    while( i < size && j < size ) {
        // Check if they are the same
        printf("Compare %d and %d\n", nums[i], nums2[j]);
        
        if( nums[i] == nums2[j] ) {
            printf("\t%d is Found\n", nums[i]);
            i++, j++;
        }
        else if( nums[i] > nums2[j] ) {
            j++;
        }
        else {
            i++;
        }
    }

    return 0;
}


// Function Definitions
int linear_search(int *arr, int size, int query) {

    for(int i = 0; i < size; i++) {
        printf("Compare %d and %d\n", query, arr[i]);
        
        if( query == arr[i] )
            return 1;
    }

    return 0;
}

int binary_search(int *arr, int size, int query) {
    int left = 0;
    int right = size-1;
    
    while( left <= right ) {
        // Compute the middle index
        int mid = (left+right) / 2;     // average!
        
        printf("Compare %d and %d\n", query, arr[mid]);
        
        if( query == arr[mid] )
            return 1;
        else if( query < arr[mid] )
            right = mid-1;
        else
            left = mid+1;
    }
    
    return 0;
}
