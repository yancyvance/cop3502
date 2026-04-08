#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Binary Min Heap.



// The MinHeap struct represents a Binary Min Heap 
// that keeps track of an internal array.
typedef struct MinHeap_s {
    int *array;
    int capacity;
    int size;
} MinHeap;


// function prototypes defined here

// create and destroy binary min heap
MinHeap * heap_create(int capacity);
MinHeap * heap_build(int *arr, int size);
void heap_destroy(MinHeap *heap);

// various operations, important
void heap_heapify(MinHeap *heap, int idx);
void heap_heapify_up(MinHeap *heap, int idx);
void heap_print(MinHeap *heap);

// helper functions
int heap_left_index(MinHeap *heap, int idx);
int heap_right_index(MinHeap *heap, int idx);
int heap_parent_index(MinHeap *heap, int idx);
void heap_swap(int *a, int *b);
void heap_copy_array(int *dst_arr, int *src_arr, int size);

// external function
void heap_sort(int *arr, int size);


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


// function definitions
MinHeap * heap_create(int capacity) {
    MinHeap *heap = malloc( sizeof(MinHeap) );
    
    if(heap == NULL) return NULL;
    
    heap->array = malloc( sizeof(int) * capacity );
    heap->capacity = capacity;
    heap->size = 0;
    
    return heap;
}

MinHeap * heap_build(int *arr, int size) {
    MinHeap *heap = heap_create(size);
    
    // copy
    heap_copy_array(heap->array, arr, size);
    heap->size = size;
    
    // compute index of last internal node
    int last_internal_idx = heap_parent_index(heap, size-1);
    
    // iterate from the last internal node
    // moving backward all the way to the root
    for(int i = last_internal_idx; i >= 0; i--)
        heap_heapify(heap, i);
    
    return heap;
}

void heap_destroy(MinHeap *heap) {
    free(heap->array);
    
    free(heap);
}

void heap_heapify(MinHeap *heap, int idx) {
    // get the left and right child index
    int left_idx = heap_left_index(heap, idx);
    int right_idx = heap_right_index(heap, idx);
    int min_idx = idx;
    
    if( left_idx != -1 && heap->array[left_idx] < heap->array[min_idx] )
        min_idx = left_idx;
        
    if( right_idx != -1 && heap->array[right_idx] < heap->array[min_idx] )
        min_idx = right_idx;
        
    // if there was a change
    if( min_idx != idx ) {
        // do a swap
        heap_swap( &(heap->array[idx]), &(heap->array[min_idx]) );
        
        // and perform a heapfiy at the
        // new location
        heap_heapify( heap, min_idx );
    }
}

void heap_heapify_up(MinHeap *heap, int idx) {
    // get the parent index
    int parent_idx = heap_parent_index(heap, idx);
    
    // if value at parent is smaller than at idx
    if( parent_idx != -1 && heap->array[idx] < heap->array[parent_idx] ) {
        // do a swap
        heap_swap( &(heap->array[idx]), &(heap->array[parent_idx]) );
        
        // and perform a heapify at the
        // new location
        heap_heapify_up( heap, parent_idx );
    }
}

void heap_print(MinHeap *heap) {
    printf("[");
    for(int i = 0; i < heap->size; i++) {
        if(i > 0)
            printf(", ");
        printf("%d", heap->array[i]);
    }
    printf("]\n");
}

int heap_left_index(MinHeap *heap, int idx) {
    int val = idx*2 + 1;
    if(val >= heap->size) return -1;
    return val;
}

int heap_right_index(MinHeap *heap, int idx) {
    int val = idx*2 + 2;
    if(val >= heap->size) return -1;
    return val;
}

int heap_parent_index(MinHeap *heap, int idx) {
    int val = (idx-1)/2;
    if(val < 0) return -1;
    return val;
}
void heap_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heap_copy_array(int *dst_arr, int *src_arr, int size) {
    // assumption here is that both arrays
    // were already allocated, so we simply
    // just copy
    for(int i = 0; i < size; i++)
        dst_arr[i] = src_arr[i];
}

void heap_sort(int *arr, int size) {
    // build the heap
    MinHeap *heap = heap_build(arr, size);
    
    // work backwards
    for(int i = size-1; i > 0; i--) {
        // swap the root and the last node
        // of the heap
        heap_swap( &(heap->array[0]), &(heap->array[i]) );
        
        // decrement the size of the heap
        heap->size = heap->size - 1;
        
        // heapify at the root
        heap_heapify(heap, 0);
    }
    
    // copy back the result to the original array
    for(int i = 0; i < size; i++)
        arr[i] = heap->array[size-1-i];
        
    // destroy the heap
    heap_destroy(heap);
}
