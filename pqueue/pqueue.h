#ifndef PQUEUE_H       // Check if PQUEUE_H is not defined
#define PQUEUE_H       // Define PQUEUE_H so it won't be included again
                       // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
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
void pqueue_delete(PriorityQueue *pqueue, int idx);



// function definitions



#endif                // End PQUEUE_H -- Do not add any code below
