#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_s {
    int *array;
    int top;            // top+1 == size
    int capacity;
} Stack;


// Function Prototypes

// Housekeeping for Stack
Stack *stack_create();
void stack_destroy(Stack *stack);

// Essential Operations
int stack_is_empty(Stack *stack);
int stack_peek(Stack *stack);
void stack_push(Stack *stack, int val);
int stack_pop(Stack *stack);
int stack_is_full(Stack *stack);


int main(void) {
    // Create a stack
    Stack *stack = stack_create();
    
    // Perform some operations here    
    for(int i = 1; i <= 15; i++)
        stack_push(stack, i);
    
    // Empty the stack
    while( !stack_is_empty(stack) ) {
        printf("%d\n", stack_pop(stack));
    }
    
    // Destroy the stack
    stack_destroy(stack);
    
    /*
    stack = stack_create();
    
    for(int i = 1; i <= 5; i++) {
        stack_push(stack, i);
        
        if( i % 2 == 0 ) printf("%d ", stack_pop(stack));
    }
    
    while( !stack_is_empty(stack) ) {
        if( stack_peek(stack) % 2 == 1 )
            printf("%d ", stack_pop(stack));
        else
            stack_pop(stack);
    }
    
    stack_destroy(stack);
    */
    
    return 0;
}


// Function Definitions
Stack *stack_create() {
    Stack *stack = malloc(sizeof(Stack));
    
    stack->top = -1;
    stack->capacity = 100;      // 100 is an arbitrary value
    stack->array = malloc( sizeof(int) * stack->capacity );
    
    return stack;
}

void stack_destroy(Stack *stack) {
    free(stack->array);
    
    // Destroy the stack last
    free(stack);
}

int stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

int stack_peek(Stack *stack) {
    if( stack_is_empty(stack) ) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    
    return stack->array[ stack->top ];
}

void stack_push(Stack *stack, int val) {
    if( stack_is_full(stack) ) {
        printf("Stack is Full!\n");
        exit(1);
    }
    
    stack->array[ ++stack->top ] = val;
}

int stack_pop(Stack *stack) {
    if( stack_is_empty(stack) ) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    
    int val = stack->array[ stack->top-- ];
    
    return val;
}

int stack_is_full(Stack *stack) {
    return stack->top+1 == stack->capacity;
}
