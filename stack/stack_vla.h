#ifndef STACK_H     // Check if STACK_H is not defined
#define STACK_H     // Define STACK_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "vla.h"

// Sample C Implementation of a Stack (Array).



// The Stack struct represents a Stack that uses
// an array as an implementation
typedef struct Stack_s {
    VLArray *list;
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
    // allocate a variable length array
    stack->list = vla_create_list();
    
    // some minor tweak that prevents
    // our array from growing
    stack->list->can_grow = 0;
    
    return stack;
}

void stack_destroy(Stack *stack) {
    // destroy dynamic fields first then
    // destroy the struct itself (stack)
    
    // destroy the array
    vla_destroy_list( stack->list );
    
    // destroy the dynamic struct / stack
    free(stack);
}

void stack_push(Stack *stack, int value) {
    // we call the helper function that
    // adds at the tail-end of an array,
    // passing the value we want to add
    vla_add_tail( stack->list, value );
}

int stack_pop(Stack *stack) {
    // we call the helper function that
    // removes from the tail-end of an array
    return vla_remove_tail( stack->list );
}

int stack_peek(Stack *stack) {
    // compute the index of the top element
    // based on the current size of the array
    int top_idx = stack->list->size - 1;
    
    // if the stack is empty, we return
    // a special marker to indicate null
    //if( top_idx == -1 )       // equivalent logic
    if( stack_is_empty(stack) )
        return -1;
    
    // return the element at this location
    return stack->list->array[top_idx];
}

int stack_is_empty(Stack *stack) {
    // we call the helper function that
    // checks if an array is empty
    // return the same value
    return vla_is_empty( stack->list );
}

void stack_print(Stack *stack) {
    // we call the helper function that
    // prints the contents of an array;
    // for debugging purposes
    vla_print_list( stack->list );
}


#endif              // End STACK_H -- Do not add any code below
