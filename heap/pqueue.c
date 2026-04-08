#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Sample C Implementation of a Priority Queue (Min).



// The MinHeap struct represents a Binary Min Heap 
// that keeps track of an internal array.
typedef struct MinHeap_s {
    int *array;
    int capacity;
    int size;
} MinHeap;

// The PriorityQueue struct represents a Priority Queue (Min) 
// that uses a min heap as an implementation.
typedef struct PriorityQueue_s {
    MinHeap *heap;
} PriorityQueue;


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


// function prototypes defined here

// create and destroy binary min heap
PriorityQueue * pqueue_create(int capacity);
void pqueue_destroy(PriorityQueue *pqueue);


// various operations, important
void pqueue_insert(PriorityQueue *pqueue, int value);
int pqueue_extract_min(PriorityQueue *pqueue);
int pqueue_peek(PriorityQueue *pqueue);
int pqueue_is_empty(PriorityQueue *pqueue);
void pqueue_print(PriorityQueue *pqueue);
int pqueue_is_full(PriorityQueue *pqueue);
void pqueue_decrease_key(PriorityQueue *pqueue, int idx, int val);
int pqueue_delete(PriorityQueue *pqueue, int idx);



int main(void) {    
    // create a priority queue
    PriorityQueue *pqueue = pqueue_create(10);
    
    // perform some operations here
    pqueue_insert(pqueue, 50);
    pqueue_insert(pqueue, 40);
    pqueue_insert(pqueue, 30);
    pqueue_insert(pqueue, 20);
    pqueue_insert(pqueue, 60);
    pqueue_insert(pqueue, 70);
    pqueue_insert(pqueue, 80);
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // extract the min
    printf("%d\n", pqueue_extract_min(pqueue));
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // decrease the key at index 3 to new value 35
    pqueue_decrease_key(pqueue, 3, 35);
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // delete element at index 5
    printf("%d\n", pqueue_delete(pqueue, 5));
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // destroy the priority queue
    pqueue_destroy(pqueue);
    
    
    // demonstration of two scenarios
    // for the delete
    PriorityQueue *pqueue1 = pqueue_create(10);
    PriorityQueue *pqueue2 = pqueue_create(10);
    
    int nums[] = {5, 10, 200, 20, 25, 100, 350, 40, 45, 30};
    int N = 10;
    
    // insert the elements
    for(int i = 0; i < N; i++) {
        pqueue_insert(pqueue1, nums[i]);
        pqueue_insert(pqueue2, nums[i]);
    }
    
    // scenario 1
    pqueue_print(pqueue1);
    printf("Delete at index 5: %d\n", pqueue_delete(pqueue1, 5));
    pqueue_print(pqueue1);
    
    // scenario 2
    pqueue_print(pqueue2);
    printf("Delete at index 1: %d\n", pqueue_delete(pqueue2, 1));
    pqueue_print(pqueue2);
    
    
    // destroy the pqueues
    pqueue_destroy(pqueue1);
    pqueue_destroy(pqueue2);
    

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

// function definitions
PriorityQueue * pqueue_create(int capacity) {
    PriorityQueue *pqueue = malloc( sizeof(PriorityQueue) );
    
    if(pqueue == NULL) return NULL;
    
    pqueue->heap = heap_create(capacity);
    
    return pqueue;
}

void pqueue_destroy(PriorityQueue *pqueue) {
    // destroy heap first
    heap_destroy(pqueue->heap);
    
    // destroy the priority queue
    free(pqueue);
}

void pqueue_insert(PriorityQueue *pqueue, int value) {
    // do not proceed if it is full
    if( pqueue_is_full(pqueue) ) return;
    
    int first_slot = pqueue->heap->size;
    
    // simply add to the first available space
    pqueue->heap->array[first_slot] = value;
    
    // increment the size
    pqueue->heap->size = pqueue->heap->size + 1;
    
    // do a heapify up at the new location
    heap_heapify_up(pqueue->heap, first_slot);    
}

int pqueue_extract_min(PriorityQueue *pqueue) {
    // check if heap is not empty
    if( !pqueue_is_empty(pqueue) ) {
        // get the root value
        int val = pqueue->heap->array[0];
        
        // fill the gap using the last element
        // and decrement the size of the heap
        pqueue->heap->array[0] = pqueue->heap->array[--pqueue->heap->size];
        
        // perform a heapify down at the root
        heap_heapify(pqueue->heap, 0);
        
        // return the min value
        return val;
    }
    
    // return special marker to indicate
    // an invalid value; for a min-heap
    // it is likely a very large number
    return INT_MAX;
}

int pqueue_peek(PriorityQueue *pqueue) {
    // check if heap is not empty
    if( !pqueue_is_empty(pqueue) ) {
        return pqueue->heap->array[0];
    }
    
    // return special marker to indicate
    // an invalid value; for a min-heap
    // it is likely a very large number
    return INT_MAX;
}

int pqueue_is_empty(PriorityQueue *pqueue) {
    return pqueue->heap->size == 0;
}

void pqueue_print(PriorityQueue *pqueue) {
    heap_print(pqueue->heap);
}

int pqueue_is_full(PriorityQueue *pqueue) {
    return pqueue->heap->size == pqueue->heap->capacity;
}

void pqueue_decrease_key(PriorityQueue *pqueue, int idx, int val) {
    // do not proceed if it is empty
    if( pqueue_is_empty(pqueue) ) return;
    
    // do not proceed if new value is not lower than
    // the old value
    if( val >= pqueue->heap->array[idx] ) return;
    
    // change the value at the index
    pqueue->heap->array[idx] = val;
    
    // guaranteed that anything below is always
    // greater than the new value, so only have
    // to go up the root for possible fixing
    heap_heapify_up(pqueue->heap, idx);
}

int pqueue_delete(PriorityQueue *pqueue, int idx) {
    // check if heap is not empty
    if( !pqueue_is_empty(pqueue) ) {
        // remember this value first
        int val = pqueue->heap->array[idx];
        
        // fill in the gap using the last
        // element of the heap; also, decrement
        // the size of the heap
        int last_val = pqueue->heap->array[--pqueue->heap->size];
        pqueue->heap->array[idx] = last_val;
        
        // there are 2 possible cases:
        // case 1: last_val < val, so heapify-up
        // case 2: last_val > val, so heapify-down
        if( last_val < val )
            heap_heapify_up(pqueue->heap, idx);
        else
            heap_heapify(pqueue->heap, idx);
            
        // return the val that was removed
        return val;
    }
    
    // return special marker to indicate
    // an invalid value; for a min-heap
    // it is likely a very large number
    return INT_MAX;
}
