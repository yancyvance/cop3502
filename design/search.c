#include <stdio.h>

// Function Prototypes
int linear_search(int *arr, int size, int query);
int binary_search(int *arr, int size, int query);


int main(void) {
    int nums[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;
    int q;
    
    scanf("%d", &q);
    printf("%d is %s\n", q, linear_search(nums, size, q) ? "Found" : "Not Found");
    printf("%d is %s\n", q, binary_search(nums, size, q) ? "Found" : "Not Found");

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
