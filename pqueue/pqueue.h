#ifndef PQUEUE_H       // Check if PQUEUE_H is not defined
#define PQUEUE_H       // Define PQUEUE_H so it won't be included again
                       // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

// Sample C Implementation of a Priority Queue (Min).



// The PriorityQueue struct represents a Priority Queue (Min) 
// that uses a min heap as an implementation.
typedef struct PriorityQueue_s {
    MinHeap *heap;
} PriorityQueue;


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


#endif                // End PQUEUE_H -- Do not add any code below
