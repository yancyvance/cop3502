#ifndef HEAP_H       // Check if HEAP_H is not defined
#define HEAP_H       // Define HEAP_H so it won't be included again
                     // Put all your codes below this line


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
void heap_destroy(MinHeap *heap);

// various operations, important
void heap_build(MinHeap *heap, int *arr, int size);
void heap_heapify(MinHeap *heap, int idx);
void heap_heapify_up(MinHeap *heap, int idx);
void heap_print(MinHeap *heap);
void heap_sort(MinHeap *heap);

// helper functions
int heap_left_index(int idx);
int heap_right_index(int idx);
int heap_parent_index(int idx);
void heap_swap(int *a, int *b);
int * duplicate_array(int *arr, int size);



// function definitions







#endif              // End HEAP_H -- Do not add any code below
