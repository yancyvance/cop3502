#ifndef STACK_H     // Check if STACK_H is not defined
#define STACK_H     // Define STACK_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Sample C Implementation of a Stack (Linked List).



// The Stack struct represents a Stack that uses
// a Singly Linked List as an implementation
typedef struct Stack_s {
    SLList *list;
} Stack;


// function prototypes defined here

// create and destroy stack
Stack * stack_create();
void stack_destroy(Stack *stack);

// various operations, important
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_peek(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_print(Stack *stack);



// function definitions
Stack * stack_create() {
    // dynamically allocate a pointer to stack
    Stack *stack = malloc( sizeof(Stack) );
    
    // check if malloc was successful
    if(stack == NULL) return NULL;
    
    // call helper function to dynamically
    // allocate the linked list
    stack->list = sll_create_list();
    
    return stack;
}


void stack_destroy(Stack *stack) {
    // destroy dynamic fields first then
    // destroy the struct itself (stack)
    
    // destroy the linked list
    sll_destroy_list( stack->list );
    
    // destroy the dynamic struct / stack
    free(stack);
}

void stack_push(Stack *stack, int value) {
    // we call the helper function that
    // performs add to head to a linked list,
    // passing the value we want to add
    sll_add_head( stack->list, value );
}

int stack_pop(Stack *stack) {
    // we call the helper function that
    // performs remove head to a linked list
    // afterward, we extract the node's data
    // then, it is our responsibility to
    // deallocate this node per our design
    SLLNode *node = sll_remove_head( stack->list );
    
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

int stack_peek(Stack *stack) {
    // if the stack is empty, we return
    // a special marker to indicate null
    //if( sll_is_empty(stack->list) )   // equivalent logic
    if( stack_is_empty(stack) )
        return -1;
    
    // return the data of the head
    // of the linked list
    return stack->list->head->data;
}

int stack_is_empty(Stack *stack) {
    // we call the helper function that
    // checks if a linked list is empty
    // return the same value
    return sll_is_empty( stack->list );
}

void stack_print(Stack *stack) {
    // we call the helper function that
    // prints the contents of a linked
    // list; for debugging purposes
    sll_print_list( stack->list );
}


#endif              // End STACK_H -- Do not add any code below
