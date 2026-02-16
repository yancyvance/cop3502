#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode_s {
    int data;
    struct SLLNode_s *next;
} SLLNode;

typedef struct Queue_s {
    SLLNode *front;
    SLLNode *rear;
} Queue;


// Function Prototypes

// Housekeeping for Nodes
SLLNode *sll_create_node(int val);
void sll_destroy_node(SLLNode *node);

// Housekeeping for Queue
Queue *queue_create();
void queue_destroy(Queue *queue);

// Essential Operations
int queue_is_empty(Queue *queue);
int queue_peek(Queue *queue);
void queue_enqueue(Queue *queue, int val);
int queue_dequeue(Queue *queue);
int queue_is_full(Queue *queue);


int main(void) {
    // Create a queue
    Queue *queue = queue_create();
    
    // Perform some operations here    
    for(int i = 1; i <= 15; i++)
        queue_enqueue(queue, i);
    
    // Empty the queue
    while( !queue_is_empty(queue) ) {
        printf("%d\n", queue_dequeue(queue));
    }
    
    // Destroy the queue
    queue_destroy(queue);
    
    /*
    queue = queue_create();
    
    for(int i = 1; i <= 5; i++) {
        queue_enqueue(queue, i);
        
        if( i % 2 == 0 ) printf("%d ", queue_dequeue(queue));
    }
    
    while( !queue_is_empty(queue) ) {
        if( queue_peek(queue) % 2 == 1 )
            printf("%d ", queue_dequeue(queue));
        else
            queue_dequeue(queue);
    }
    
    queue_destroy(queue);
    */
    
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

Queue *queue_create() {
    Queue *queue = malloc(sizeof(Queue));
    
    queue->front = NULL;
    queue->rear = NULL;
    
    return queue;
}

void queue_destroy(Queue *queue) {
    SLLNode *ptr = queue->front;
    SLLNode *tmp;
    
    // Destory all the nodes first
    while( ptr != NULL ) {
        tmp = ptr->next;
        
        sll_destroy_node(ptr);
        
        ptr = tmp;
    }
    
    // Destroy the queue last
    free(queue);
}

int queue_is_empty(Queue *queue) {
    return queue->front == NULL;
}

int queue_peek(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    return queue->front->data;
}

void queue_enqueue(Queue *queue, int val) {
    SLLNode *tmp = sll_create_node(val);
    
    // Scenario 1
    if( queue_is_empty(queue) ) {
        queue->front = tmp;
        queue->rear = tmp;
        return;
    }
    
    // Scenario 2
    queue->rear->next = tmp;
    queue->rear = tmp;
}

int queue_dequeue(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    SLLNode *tmp = queue->front;
    queue->front = tmp->next;
    
    // Scenario 1 Only
    if( queue->front == NULL ) {
        queue->rear = NULL;
    }
    
    int val = tmp->data;
    sll_destroy_node(tmp);
    return val;
}

int queue_is_full(Queue *queue) {
    // Does not make sense for Linked List
    // backend. Therefore, always report not full.
    return 0;
}
