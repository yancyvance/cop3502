#include <stdio.h>
#include "queue_sll.h"
//#include "queue_vla.h"

// Sample Test Program for Queue.
// Switch the back-end implementation by
// commenting one and un-commenting the
// other H file above.
//      SLL - Singly Linked List
//      VLA - Variable Length Array

int main(void) {
    // create a queue
    Queue *queue = queue_create();
    
    // perform some operations here    
    for(int i = 1; i <= 15; i++)
        queue_enqueue(queue, i);
    
    // print the contents
    queue_print(queue);
    
    // empty the queue
    while( !queue_is_empty(queue) ) {
        printf("%d\n", queue_dequeue(queue));
    }
    
    // print the contents
    queue_print(queue);
    
    // destroy the queue
    queue_destroy(queue);
    
    return 0;
}
