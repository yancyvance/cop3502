#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_s {
    int *array;
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
    return queue->rear == -1;
}

int queue_peek(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    return queue->array[0];
}

void queue_enqueue(Queue *queue, int val) {
    if( queue_is_full(queue) ) {
        printf("Queue is Full!\n");
        exit(1);
    }
    
    queue->array[++queue->rear] = val;
}

int queue_dequeue(Queue *queue) {
    if( queue_is_empty(queue) ) {
        printf("Queue is Empty!\n");
        exit(1);
    }
    
    int val = queue->array[0];
    
    for(int i = 0; i < queue->rear; i++) {
        queue->array[i] = queue->array[i+1];
    }
    
    queue->rear--;
    
    return val;
}

int queue_is_full(Queue *queue) {
    return queue->rear+1 == queue->capacity;
}
