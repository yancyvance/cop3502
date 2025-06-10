#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Variable Length Array.



// struct needed
typedef struct VLArray_s {
    int *array;      // Pointer to the dynamically allocated array of integers
    int size;        // Current number of elements in the array
    int capacity;    // Maximum number of elements that can be stored before resizing
} VLArray;



// function prototypes defined here

// create and destory variable length array
VLArray * vla_create_list();
void vla_destroy_list(VLArray *list);

// various operations, important
void vla_print_list(VLArray *list);
int vla_search(VLArray *list, int query);
int vla_is_empty(VLArray *list);
int vla_get_size(VLArray *list);

// various operations, practice
void vla_insert_at(VLArray *list, int index, int value);
int vla_remove_at(VLArray *list, int index);
int vla_get_element_at(VLArray *list, int index);
int vla_delete(VLArray *list, int value);
void vla_add_tail(VLArray *list, int value);

// utility
void vla_grow_list(VLArray *list);



int main(void) {
    // create a list
    
    
    
    
    
    
    // destroy the list
    
    
    return 0;
}



// function definitions
