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
void vla_destroy_list(VLArray *vla);

// various operations, important
void vla_print_list(VLArray *vla);
int vla_search(VLArray *vla, int query);
int vla_is_empty(VLArray *vla);
int vla_get_size(VLArray *vla);

// various operations, practice
void vla_insert_at(VLArray *vla, int index, int value);
int vla_remove_at(VLArray *vla, int index);
int vla_get_element_at(VLArray *vla, int index);
int vla_delete(VLArray *vla, int value);



int main(void) {
    // create a list
    
    
    
    
    
    
    // destroy the list
    
    
    return 0;
}



// function definitions
