#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode_s {
    int data;
    struct SLLNode_s *next;
} SLLNode;

typedef struct Stack_s {
    SLLNode *top;
} Stack;


// Function Prototypes

// Housekeeping for Nodes
SLLNode *sll_create_node(int val);
void sll_destroy_node(SLLNode *node);

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
    
    
    return 0;
}


// Function Definitions
SLLNode *sll_create_node(int val) {
    SLLNode *n = malloc(sizeof(SLLNode));
    
    n->data = val;
    n->next = NULL;
    
    return n;
}

void sll_destroy_node(SLLNode *node) {
    free(node);
}

Stack *stack_create() {
    Stack *stack = malloc(sizeof(Stack));
    
    stack->top = NULL;
    
    return stack;
}

void stack_destroy(Stack *stack) {
    SLLNode *ptr = stack->top;
    SLLNode *tmp;
    
    // Destory all the nodes first
    while( ptr != NULL ) {
        tmp = ptr->next;
        
        sll_destroy_node(ptr);
        
        ptr = tmp;
    }
    
    // Destroy the stack last
    free(stack);
}

int stack_is_empty(Stack *stack) {
    return stack->top == NULL;
}

int stack_peek(Stack *stack) {
    if( stack_is_empty(stack) ) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    
    return stack->top->data;
}

void stack_push(Stack *stack, int val) {
    SLLNode *tmp = sll_create_node(val);
    tmp->next = stack->top;
    stack->top = tmp;
}

int stack_pop(Stack *stack) {
    if( stack_is_empty(stack) ) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    
    SLLNode *tmp = stack->top;
    stack->top = tmp->next;
    
    int val = tmp->data;
    sll_destroy_node(tmp);
    return val;
}

int stack_is_full(Stack *stack) {
    // Does not make sense for Linked List
    // backend. Therefore, always report not full.
    return 0;
}
