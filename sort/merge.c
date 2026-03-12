#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void merge_sort(int *arr, int left, int right);
void merge(int *arr, int start, int mid, int end);
void print_array(int *arr, int size);

int main(void) {
    int nums[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    // Before Sorting
    print_array(nums, size);
    
    // Sort the Array
    merge_sort(nums, 0, size-1);
    
    // After Sorting
    print_array(nums, size);
    
    return 0;
}

void merge_sort(int *arr, int start, int end) {
    // If there is no element OR if there is
    // only one element in this array segment,
    // then we stop dividing as the problem
    // is small enough.
    if( start >= end )
        return;
    
    // Step 1: DIVIDE
    // Find the index of the mid-element
    // to divide the array into two
    // "sub-arrays", the left and the right.
    // If the number of elements is odd,
    // the left sub-array will be shorter
    // than the right sub-array.
    int mid = (start+end+1) / 2;
    
    // Step 2: CONQUER
    // Perform the merge sort on the left
    // sub-array first, then afterward,
    // perform the merge sort on the right
    // sub-array. Note that there is only
    // one array here. We are simply
    // dealing with segments of this array
    // to create the illusion of sub-arrays.
    merge_sort(arr, start, mid-1);  // left
    merge_sort(arr, mid, end);      // right
    
    // Step 3: COMBINE
    // Combine the two sorted "sub-arrays"
    // into a single array while maintaing
    // the sorted property.
    merge(arr, start, mid, end);
}

void merge(int *arr, int start, int mid, int end) {
    // The technique requires the use of an
    // auxilliary (temporary) array in which
    // the size is enough to hold the combined
    // elements of the two "sub-arrays".
    int size = end-start+1;
    int *aux = malloc(sizeof(int) * size);
    
    int i = start, j = mid;
    int p = 0;
    
    // As long as there are elements in both
    // list1 and list2, then proceed with
    // the linear walk. Note that these
    // are inclusive indices that's why
    // the condition is such in the while loop.
    while( i < mid && j <= end ) {
        // If element pointed by i is
        // smaller, then use it, otherwise
        // use the element pointed by j.
        if( arr[i] <= arr[j] )
            aux[p] = arr[i++];
        else
            aux[p] = arr[j++];
            
        p++;
    }
    
    // Two mutually exclusive events. This
    // simply ensures that when one list runs
    // out of elements, the remaining elements
    // in the other list will be copied over.
    while( i < mid  )   aux[p++] = arr[i++];
    while( j <= end )   aux[p++] = arr[j++];
    
    // This copies the elements from the auxilliary
    // array to the actual array.
    for(int k = start, pos = 0; k <= end; k++, pos++)
        arr[k] = aux[pos];
    
    // Deallocate the temporary array used.
    free(aux);
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
