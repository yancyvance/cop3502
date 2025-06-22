#ifndef QUEUE_H     // Check if QUEUE_H is not defined
#define QUEUE_H     // Define QUEUE_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "vla.h"

// Sample C Implementation of a Queue (Array).



// The Queue struct represents a Queue that uses
// an array as an implementation
typedef struct Queue_s {
    VLArray *list;
} Queue;


// function prototypes defined here

// create and destroy queue
Queue * queue_create();
void queue_destroy(Queue *queue);

// various operations, important
void queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue);
int queue_peek(Queue *queue);
int queue_is_empty(Queue *queue);
void queue_print(Queue *queue);
int queue_is_full(Queue *queue);



// function definitions
Queue * queue_create() {
    // dynamicallly allocate a pointer to a queue
    Queue *queue = malloc( sizeof(Queue) );
    
    // check if malloc was successful
    if(queue == NULL) return NULL;
    
    // call helper function to dynamically
    // allocate a variable length array
    queue->list = vla_create_list();
    
    // some minor tweak that prevents
    // our array from growing
    //stack->list->can_grow = 0;    // TODO: future update
    
    return queue;
}

void queue_destroy(Queue *queue) {
    // destroy dynamic fields first then
    // destroy the struct itself (queue)
    
    // destroy the array
    vla_destroy_list( queue->list );
    
    // destroy the dynamic struct / queue
    free(queue);
}

void queue_enqueue(Queue *queue, int value) {
    // we call the helper function that
    // adds at the tail-end of an array,
    // passing the value we want to add
    vla_add_tail( queue->list, value );
}

int queue_dequeue(Queue *queue) {
    // we call the helper function that
    // removes the 0-th index of an array
    if( !queue_is_empty(queue) )
        return vla_remove_at(queue->list, 0);
        
    // if the queue is empty, we return
    // a special marker to indicate null
    return -1;
}

int queue_peek(Queue *queue) {
    // if the queue is empty, we return
    // a special marker to indicate null
    //if( vla_is_empty(queue->list) )   // equivalent logic
    if( queue_is_empty(queue) )
        return -1;
    
    // return the data at the 0-th
    // index of the array
    return queue->list->array[0];
}

int queue_is_empty(Queue *queue) {
    // we call the helper function that
    // checks if an array is empty
    // return the same value
    return vla_is_empty( queue->list );
}

void queue_print(Queue *queue) {
    // we call the helper function that
    // prints the contents of an array;
    // for debugging purposes
    vla_print_list( queue->list );
}

int queue_is_full(Queue *queue) {
    // check if size is at capacity
    return queue->list->size == queue->list->capacity;
}


#endif              // End QUEUE_H -- Do not add any code below
