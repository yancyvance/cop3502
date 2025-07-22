#ifndef HTABLE_H       // Check if HTABLE_H is not defined
#define HTABLE_H       // Define HTABLE_H so it won't be included again
                       // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Sample C Implementation of a Hash Table (Chaining).



// The HashTable struct represents a HashTable 
// that keeps track of its size and capacity.
// It also keeps track of an internal array
// of pointers to a SLList struct, where the size
// the size of the array is the same as the 
// capacity of the HashTable.
typedef struct HashTable_s {
    SLList **array;
    int size;
    int capacity;
} HashTable;


// function prototypes defined here

// create and destroy hash table
HashTable * htable_create(int capacity);
void htable_destroy(HashTable *table);

// various operations, important
void htable_insert(HashTable *table, int key);
int htable_search(HashTable *table, int key);
void htable_remove(HashTable *table, int key);

// helper functions
int htable_hash(HashTable *table, int key);
void htable_print(HashTable *table);



// function definitions
HashTable * htable_create(int capacity) {
    // dynamically allocate a hashtable
    HashTable *table = malloc( sizeof(HashTable) );
    
    if(table == NULL) return NULL;
    
    // set the values for the fields first
    table->size = 0;
    table->capacity = capacity;
    
    // dynamically allocate an array of Linked Lists
    // with size of capacity
    table->array = malloc( sizeof(SLList *) * capacity );
    
    // for each element of this array, dynamically
    // allocate an empty singly linked list
    for(int i = 0; i < capacity; i++)
        table->array[i] = sll_create_list();
        
    return table;
}

void htable_destroy(HashTable *table) {
    // destroy all the dynamic fields first
    // destroy each linked list in the array
    for(int i = 0; i < table->capacity; i++)
        sll_destroy_list( table->array[i] );
        
    // destroy the dynamic array
    free( table->array );
        
    // destroy the hash table
    free( table );
}

void htable_insert(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // assumes that there is already a
    // linked list at that location
    // so, add this new key to that
    // linked list
    sll_add_tail( table->array[hash_value], key );
    
    // update size
    table->size++;
}

int htable_search(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // assumes that there is already a
    // linked list at that location
    // so, search that linked list only    
    return sll_search( table->array[hash_value], key );
}

void htable_remove(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // assumes that there is already a
    // linked list at that location
    // so, search that linked list only
    SLLNode *node = sll_delete( table->array[hash_value], key );
    
    // if there is such a node
    if(node) {
        // it is our responsibility to deallocate
        sll_destroy_node(node);
        
        // update size
        table->size--;
    }
}

int htable_hash(HashTable *table, int key) {
    return key % table->capacity;
}

void htable_print(HashTable *table) {
    printf("Separate Chaining\n");
    printf("Index | Contents\n");
    printf("------|---------\n");
    
    // loop through each element of the internal
    // array and start printing each linked list
    for(int i = 0; i < table->capacity; i++) {
        printf("%5d | ", i);
        sll_print_list( table->array[i] );
    }
}


#endif               // End HTABLE_H -- Do not add any code below
