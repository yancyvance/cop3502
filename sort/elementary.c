#include <stdio.h>

// Function Prototypes
void selection_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void bubble_sort_efficient(int *arr, int size);
void print_array(int *arr, int size);
void swap(int *a, int *b);

int main(void) {
    int nums[] = {5, 3, 8, 4, 2};
    int size = 5;
    
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
    for(int i = 0; i < size-1; i++) {
        int min_idx = i;
        
        for(int j = i+1; j < size; j++) {
            if( arr[j] < arr[min_idx] ) {
                min_idx = j;
            }
        }

        if( i != min_idx )
            swap( &arr[i], &arr[min_idx] );
    }
}

void insertion_sort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int tmp = arr[i];
        int j;
        
        for(j = i-1; j >= 0 && tmp < arr[j]; j--) {
            arr[j+1] = arr[j];
        }
        
        arr[j+1] = tmp;
    }
}

void bubble_sort(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-1-i; j++) { 
            if( arr[j] > arr[j+1] ) {
                swap( &arr[j], &arr[j+1] );
            }
        }
    }
}

void bubble_sort_efficient(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        int swapped = 0;
        for(int j = 0; j < size-1-i; j++) 
            if( arr[j] > arr[j+1] ) {
                swap( &arr[j], &arr[j+1] );
                swapped = 1;
            }
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
