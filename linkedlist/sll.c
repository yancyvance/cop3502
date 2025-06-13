#include <stdio.h>
#include "sll.h"

// Sample C Implementation of a Singly Linked List.

int main(void) {
    // create a list
    SLList *list = sll_create_list();
    
    
    // perform some operations here
    sll_add_tail(list, 3);
    sll_add_tail(list, 1);
    sll_add_tail(list, 2);
    sll_add_tail(list, 5);
    
    sll_add_head(list, 4);    
    
    sll_print_list(list);
    
    // nodes removed need to be deallocated
    sll_destroy_node( sll_remove_head(list) );
    
    sll_print_list(list);
    
    
    // destroy the list
    sll_destroy_list(list);
    
    
    // create an empty list
    list = sll_create_list();
    
    for(int i = 1; i <= 15; i++)
        sll_add_tail(list, i);
        
    sll_print_list(list);
    
    while( !sll_is_empty(list) ) {
        sll_destroy_node( sll_remove_tail(list) );
        
        sll_print_list(list);
    }
    
    // destroy the list
    sll_destroy_list(list);
    
    return 0;
}
