#ifndef QUEUE_H     // Check if QUEUE_H is not defined
#define QUEUE_H     // Define QUEUE_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Sample C Implementation of a Queue (Linked List).



// The Queue struct represents a Queue that uses
// a Singly Linked List as an implementation
typedef struct Queue_s {
    SLList *list;
} Queue;


// function prototypes defined here

// create and destroy queue
Queue * queue_create();
void queue_destroy(Queue *);

// various operations, important
void queue_enqueue(Queue *, int);
int * queue_dequeue(Queue *);
int * queue_peek(Queue *);
int queue_is_empty(Queue *);



// function definitions



#endif              // End QUEUE_H -- Do not add any code below
