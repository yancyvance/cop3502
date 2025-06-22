#ifndef QUEUE_H     // Check if QUEUE_H is not defined
#define QUEUE_H     // Define QUEUE_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
//#include "sll2.h" // SLL with head and tail pointers

// Sample C Implementation of a Queue (Linked List).



// The Queue struct represents a Queue that uses
// a Singly Linked List as an implementation
typedef struct Queue_s {
    SLList *list;
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



// function definitions
Queue * queue_create() {
    // dynamicallly allocate a pointer to a queue
    Queue *queue = malloc( sizeof(Queue) );
    
    // check if malloc was successful
    if(queue == NULL) return NULL;
    
    // call helper function to dynamically
    // allocate the linked list
    queue->list = sll_create_list();
    
    return queue;
}

void queue_destroy(Queue *queue) {
    // destroy dynamic fields first then
    // destroy the struct itself (queue)
    
    // destroy the linked list
    sll_destroy_list( queue->list );
    
    // destroy the dynamic struct / queue
    free(queue);
}

void queue_enqueue(Queue *queue, int value) {
    // we call the helper function that
    // performs add to tail to a linked list,
    // passing the value we want to add
    sll_add_tail( queue->list, value );
}

int queue_dequeue(Queue *queue) {
    // we call the helper function that
    // performs remove head to a linked list
    // afterward, we extract the node's data
    // then, it is our responsibility to
    // deallocate this node per our design
    SLLNode *node = sll_remove_head( queue->list );
    
    if(node) {
        // extract data
        int value = node->data;
    
        // deallocate the node
        sll_destroy_node(node);
        
        return value;
    }
    
    // special marker to indicate null
    return -1;
}

int queue_peek(Queue *queue) {
    // if the queue is empty, we return
    // a special marker to indicate null
    //if( sll_is_empty(queue->list) )   // equivalent logic
    if( queue_is_empty(queue) )
        return -1;
    
    // return the data of the head
    // of the linked list
    return queue->list->head->data;
}

int queue_is_empty(Queue *queue) {
    // we call the helper function that
    // checks if a linked list is empty
    // return the same value
    return sll_is_empty( queue->list );
}

void queue_print(Queue *queue) {
    // we call the helper function that
    // prints the contents of a linked
    // list; for debugging purposes
    sll_print_list( queue->list );
}


#endif              // End QUEUE_H -- Do not add any code below
