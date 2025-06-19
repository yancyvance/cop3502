#include <stdio.h>
#include "sll.h"

// Sample Test Program for Singly Linked List.

int main(void) { 
    // create a list
    SLList *list = sll_create_list();
    
    // Section 1: Use the iterative versions
    
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
        
    // print the list
    sll_print_list(list);
    
    while( !sll_is_empty(list) ) {
        sll_destroy_node( sll_remove_tail(list) );
        
        sll_print_list(list);
    }
    
    // destroy the list
    sll_destroy_list(list);
    
    
    
    // SECTION 2: Use the recursive versions
    
    // create new list
    list = sll_create_list();
    
    // the recursive function to add a new
    // element at the tail
    sll_add_recursive(&(list->head), 10);
    sll_add_recursive(&(list->head), 20);
    sll_add_recursive(&(list->head), 30);
    
    // print the list
    sll_print_recursive(list->head);
    
    // try the recursive delete; we have to deallocate
    sll_destroy_node( sll_delete_recursive(&(list->head), 20) );
    
    // print the list again
    sll_print_recursive(list->head);
    
    // destroy the list
    sll_destroy_list(list);
    
    
    // Section 3: Linked Lists without the SLList struct
    
    // empty list, set head to NULL
    SLLNode *head = NULL; //sll_create_node(10);
    
    // print the list
    sll_print_recursive(head);
    
    // add a new node
    sll_add_recursive(&head, 100);
    sll_add_recursive(&head, 200);
    sll_add_recursive(&head, 300);
    
    // print the list
    sll_print_recursive(head);
    
    // destroy all the nodes
    sll_destroy_node( sll_delete_recursive(&head, 200) );
    sll_print_recursive(head);
    
    sll_destroy_node( sll_delete_recursive(&head, 100) );
    sll_print_recursive(head);
    
    sll_destroy_node( sll_delete_recursive(&head, 300) );
    sll_print_recursive(head);
    
    return 0;
}
