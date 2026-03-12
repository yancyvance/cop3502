#include <stdio.h>

void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
void print_array(int *arr, int size);
void swap(int *a, int *b);

int main(void) {
    int nums[] = {8, 3, 1, 7, 0, 10, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    // Before Sorting
    print_array(nums, size);
    
    // Sort the Array
    quick_sort(nums, 0, size-1);
    
    // After Sorting
    print_array(nums, size);
    
    return 0;
}

void quick_sort(int *arr, int start, int end) {
    // If there is no element OR if there is
    // only one element in this array segment,
    // then we stop dividing as the problem
    // is small enough.
    if( start >= end )
        return;
    
    // Step 1: DIVIDE
    // Divide the array into two "sub-arrays",
    // the left and the right. Those elements
    // in the left are those with values less
    // than or equal to the pivot. Those
    // elements in the right are those with
    // values greater than the pivot. This
    // partitioning will be performed by a
    // helper function. It then returns the
    // index where the pivot is located.
    int p_idx = partition(arr, start, end);
    
    // Step 2: CONQUER
    // Perform the quick sort on the left
    // sub-array first, then afterward,
    // perform the quick sort on the right
    // sub-array. Note that there is only
    // one array here. We are simply
    // dealing with segments of this array
    // to create the illusion of sub-arrays.
    quick_sort(arr, start, p_idx-1);    // left
    quick_sort(arr, p_idx+1, end);      // right
    
    // Step 3: COMBINE
    // Notice that there is no explicit
    // combine step for quick sort.
}

int partition(int *arr, int start, int end) {
    // This is the heart of quick sort.
    // This implementation assumes simply
    // chooses the rightmost element as the
    // pivot for this partitioning step.
    // We then initialize the location of
    // the boundary to be the same as the
    // start index of this array segment.
    // Note that this does not always begin
    // at 0 (due to the use of a single array).
    int pivot = arr[end];
    int d_idx = start;
    
    // Process all the remaining elements and
    // put each of them in the correct region:
    // left or right based on its value relative
    // to the pivot.
    for(int i = start; i < end; i++) {
        // If the current element is smaller
        // than the pivot, then we need to
        // swap this element and the first
        // element of the right "sub-array".
        // Afterward, we move the boundary
        // to the right.
        if( arr[i] <= pivot ) {
            swap( &arr[i], &arr[d_idx] );
            d_idx++;
        }
    }
    
    // This final swap puts the pivot in its
    // correct location. It turns out that this
    // is the same location where the boundary
    // is currently located.
    swap( &arr[end], &arr[d_idx] );
    
    // Return the index or location of the pivot.
    return d_idx;
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
