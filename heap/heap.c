#include <stdio.h>
#include "heap.h"

// Sample Test Program for Binary Min Heap.

int main(void) {
    int nums[] = {4, 1, 9, 2, 16, 5, 10, 14, 3, 7};
    int N = 10;
    
    // create a heap
    MinHeap *heap = heap_build(nums, N);
    
    // perform some operations here
    heap_print(heap);
    
    // destroy the heap
    heap_destroy(heap);
    
    
    // heap sort demonstration
    int arr[] = {50, 10, 20, 60, 30};
    int M = 5;
    
    // print before
    for(int i = 0; i < M; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    
    // do a heapsort
    heap_sort(arr, M);
    
    // print after
    for(int i = 0; i < M; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    

    return 0;
}
