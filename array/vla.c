#include <stdio.h>
#include "vla.h"

// Sample Test Program for Variable Length Array.

int main(void) {
    // create a list
    VLArray *list = vla_create_list();
    
    // perform some operations here
    vla_print_list(list);
    
    // add elements
    for(int i = 1; i <= 25; i++)
        vla_add_tail(list, i);
    
    vla_print_list(list);
    
    vla_insert_at(list, 0, 99);
    
    vla_print_list(list);
    
    vla_remove_tail(list);
    
    vla_print_list(list);
    
    vla_remove_at(list, 0);
    
    // confirm if outputs are the same
    vla_print_list(list);
    vla_print_list_recursive(list);
    
    // destroy the list
    vla_destroy_list(list);
    
    return 0;
}
