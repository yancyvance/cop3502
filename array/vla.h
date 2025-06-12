#ifndef VLA_H       // Check if VLA_H is not defined
#define VLA_H       // Define VLA_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Variable Length Array.



// The VLArray struct represents a dynamic array 
// of integers that can grow as needed.
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
int vla_delete(VLArray *list, int query);
void vla_add_tail(VLArray *list, int value);

// utility
void vla_grow_list(VLArray *list);

// various operations, recursive (practice)
void vla_print_list_recursive(VLArray *list);
void vla_print_recursive(VLArray *list, int index);



// function definitions go here
VLArray * vla_create_list() {
    VLArray *list = malloc( sizeof(VLArray) );
    
    list->capacity = 10;
    list->size = 0;
    list->array = malloc( sizeof(int) * list->capacity );
    
    return list;
}

void vla_destroy_list(VLArray *list) {
    // check if there is an actual list first
    if(list != NULL) {
        // deallocate the array first
        free(list->array);
        
        // deallocate the list
        free(list);
    }
}

// various operations, important
void vla_print_list(VLArray *list) {
    if( vla_is_empty(list) ) {
        printf("List Empty!");
    }
    else {
        for(int i = 0; i < list->size; i++)
            printf("%d ", list->array[i]);
    }
    
    printf("\n");
}

int vla_search(VLArray *list, int query) {
    for(int i = 0; i < list->size; i++) {
        if( list->array[i] == query )
            return 1;
    }
    return 0;
}

int vla_is_empty(VLArray *list) {
    return list->size == 0;
}

int vla_get_size(VLArray *list) {
    return list->size;
}

void vla_insert_at(VLArray *list, int index, int value) {
    if( index >= 0 && index <= list->size ) {
        // check if need to grow
        if( list->size == list->capacity )
            vla_grow_list(list);
            
        // start shifting to the right to make space
        for(int i = list->size; i > index; i--) {
            list->array[i] = list->array[i-1];
        }
        
        // put the element
        list->array[index] = value;
        
        // increment counter
        list->size++;
    }
}

int vla_remove_at(VLArray *list, int index) {
    if( index >= 0 && index < list->size ) {
        // get old value
        int tmp = list->array[index];
        
        // start shifting
        for(int i = index; i < list->size - 1; i++) {
            list->array[i] = list->array[i+1];
        }
        
        // decrement the size
        list->size--;
        
        return tmp;
    }
    
    // invalid flag
    return -1;
}

int vla_get_element_at(VLArray *list, int index) {
    if( index >= 0 && index < list->size )
        return list->array[index];
    
    // random flag of invalid index
    return -1;
}

int vla_delete(VLArray *list, int query) {
    // find first
    for(int i = 0; i < list->size; i++)
        if( list->array[i] == query )
            return vla_remove_at(list, i);
            
    // random flag of not found
    return -1;
}

void vla_add_tail(VLArray *list, int value) {
    // check if need to grow
    if( list->size == list->capacity )
        vla_grow_list(list);
        
    // add to the first available spot
    list->array[list->size] = value;
    
    // update size
    list->size++;
}

void vla_grow_list(VLArray *list) {
    // debugging purposes
    printf("Growing from %d to %d!\n", list->capacity, list->capacity*2);
    
    // compute new capacity (double of existing)
    list->capacity = list->capacity * 2;
    
    // allocate a new array
    int *new_array = malloc( sizeof(int) * list->capacity );
    
    // copy the values from the old
    for(int i = 0; i < list->size; i++) {
        new_array[i] = list->array[i];
    }
    
    // deallocate the old array
    free(list->array);
    
    // update the reference to point to new array
    list->array = new_array;
}

void vla_print_list_recursive(VLArray *list) {
    // wrapper function to do the initial call
    vla_print_recursive(list, 0);
}

void vla_print_recursive(VLArray *list, int index) {
    // base case
    if( index == list->size ) {
        printf("\n");
        return;
    }
        
    // recursive
    printf("%d ", list->array[index]);
    
    vla_print_recursive(list, index+1);
}


#endif              // End VLA_H -- Do not add any code below
