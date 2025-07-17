#include <stdio.h>
#include "pqueue.h"

// Sample Test Program for Priority Queue (Min).

int main(void) {    
    // create a priority queue
    PriorityQueue *pqueue = pqueue_create(10);
    
    // perform some operations here
    pqueue_insert(pqueue, 50);
    pqueue_insert(pqueue, 40);
    pqueue_insert(pqueue, 30);
    pqueue_insert(pqueue, 20);
    pqueue_insert(pqueue, 60);
    pqueue_insert(pqueue, 70);
    pqueue_insert(pqueue, 80);
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // extract the min
    printf("%d\n", pqueue_extract_min(pqueue));
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // decrease the key at index 3 to new value 35
    pqueue_decrease_key(pqueue, 3, 35);
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // delete element at index 5
    printf("%d\n", pqueue_delete(pqueue, 5));
    
    // inspect the pqueue
    pqueue_print(pqueue);
    
    // destroy the priority queue
    pqueue_destroy(pqueue);
    
    
    // demonstration of two scenarios
    // for the delete
    PriorityQueue *pqueue1 = pqueue_create(10);
    PriorityQueue *pqueue2 = pqueue_create(10);
    
    int nums[] = {5, 10, 200, 20, 25, 100, 350, 40, 45, 30};
    int N = 10;
    
    // insert the elements
    for(int i = 0; i < N; i++) {
        pqueue_insert(pqueue1, nums[i]);
        pqueue_insert(pqueue2, nums[i]);
    }
    
    // scenario 1
    pqueue_print(pqueue1);
    printf("Delete at index 5: %d\n", pqueue_delete(pqueue1, 5));
    pqueue_print(pqueue1);
    
    // scenario 2
    pqueue_print(pqueue2);
    printf("Delete at index 1: %d\n", pqueue_delete(pqueue2, 1));
    pqueue_print(pqueue2);
    
    
    // destroy the pqueues
    pqueue_destroy(pqueue1);
    pqueue_destroy(pqueue2);
    

    return 0;
}
