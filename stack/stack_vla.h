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
void stack_destroy(Stack *);

// various operations, important
void stack_push(Stack *, int);
int stack_pop(Stack *);
int stack_peek(Stack *);
int stack_is_empty(Stack *);



// function definitions



#endif              // End STACK_H -- Do not add any code below
