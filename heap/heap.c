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
    
    return 0;
}
