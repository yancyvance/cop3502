#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_s {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;


// Function Prototypes

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
Queue *queue_create() {
    Queue *queue = malloc(sizeof(Queue));
    
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = 100;      // 100 is an arbitrary value
    queue->array = malloc( sizeof(int) * queue->capacity );
    
    return queue;
}

void queue_destroy(Queue *queue) {
    free(queue->array);
    
    // Destroy the queue last
    free(queue);
}

int queue_is_empty(Queue *queue) {
    return queue->front == -1;
}

int queue_peek(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    return queue->array[ queue->front ];
}

void queue_enqueue(Queue *queue, int val) {
    if( queue_is_full(queue) ) {
        printf("Queue is Full!\n");
        exit(1);
    }
    
    // Compute the actual index of the new rear
    int idx = ( queue->rear + 1 ) % queue->capacity;
    
    // Check which scenario
    if( queue_is_empty(queue) ) {
        // Scenario 1 (Empty)
        // Update both the front and rear
        queue->front = idx;
        queue->rear = idx;
    }
    else {
        // Scenario 2 (Non-Empty)
        queue->rear = idx;
    }
    
    // Set the value at that location
    queue->array[idx] = val;
}

int queue_dequeue(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    // Get the value at the front location
    int val = queue->array[ queue->front ];
    
    // Check which scenario
    if( queue->front == queue->rear ) {
        // Scenario 1 (Only one element)
        queue->front = queue->rear = -1;
    }
    else {
        // Scenario 2 (More than one element)
        
        // Compute the actual index of the new front
        int idx = ( queue->front + 1 ) % queue->capacity;
        
        // Update the front of the queue
        queue->front = idx;
    }
    
    return val;
}

int queue_is_full(Queue *queue) {
    // Check if the queue is still empty
    if( queue_is_empty(queue) )
        return 0;
        
    // Otherwise, check which configuration
    if( queue->front < queue->rear ) {
        // Configuration 1: Normal, so
        // do the math
        int delta = queue->rear - queue->front;
        
        // Delta+1 is the logical size
        return delta+1 == queue->capacity;
    }
    else {
        // Configuration 2: Rear is on
        // the left side of front
        return queue->rear+1 == queue->front;
    }
}
