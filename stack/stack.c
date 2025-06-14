#include <stdio.h>
#include "stack_sll.h"
//#include "stack_vla.h"

// Sample C Implementation of a Stack.

int main(void) {
    // create a stack
    Stack *stack = stack_create();
    
    // perform some operations here    
    for(int i = 1; i <= 15; i++)
        stack_push(stack, i);
    
    // print the contents
    stack_print(stack);
    
    // empty the stack
    while( !stack_is_empty(stack) ) {
        printf("%d\n", stack_pop(stack));
    }
    
    // print the contents
    stack_print(stack);
    
    // destroy the stack
    stack_destroy(stack);
    
    return 0;
}
