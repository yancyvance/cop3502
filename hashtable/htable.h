#ifndef HTABLE_H       // Check if HTABLE_H is not defined
#define HTABLE_H       // Define HTABLE_H so it won't be included again
                       // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#define NULL_MARKER 0
#define DELETED_MARKER -1

// Sample C Implementation of a Hash Table (Open Addressing).



// The HashTable struct represents a HashTable 
// that keeps track of its size and capacity.
// It also keeps track of an internal array
// of integers, where the size of 
// the array is the same as the capacity 
// of the HashTable. Note that 0 and -1 have
// special meanings, so don't use them as keys!
typedef struct HashTable_s {
    int *array;
    int size;
    int capacity;
    int is_linear_probing;
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
int htable_linear_probing(int loc, int i, int capacity);
int htable_quadratic_probing(int loc, int i, int capacity);
int htable_is_location_available(int location);



// function definitions
HashTable * htable_create(int capacity) {
    // dynamically allocate a hashtable
    HashTable *table = malloc( sizeof(HashTable) );
    
    if(table == NULL) return NULL;
    
    // set the values for the fields first
    table->size = 0;
    table->capacity = capacity;
    
    // dynamically allocate an array of integers
    // with size of capacity
    table->array = malloc( sizeof(int) * capacity );
    
    // for each element of this array, set it
    // initially to NULL_MARKER (special value)
    for(int i = 0; i < capacity; i++)
        table->array[i] = NULL_MARKER;
    
    // default to linear probing
    table->is_linear_probing = 1;
        
    return table;
}

void htable_destroy(HashTable *table) {
    // destroy all the dynamic fields first
    // destroy the dynamic array
    free( table->array );
        
    // destroy the hash table
    free( table );
}

void htable_insert(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // retain in case of a collision
    int initial_hash_value = hash_value;
    
    // prevents us from ending in an infinite loop
    int probe_count = 0;
    
    // keep finding until an available slot is found
    while( !(htable_is_location_available( table->array[hash_value] )) ) {
        // prevents an infinite loop
        if(probe_count == table->capacity)
            return;
        
        // get new location
        // linear probing?
        if( table->is_linear_probing )
            hash_value = htable_linear_probing(initial_hash_value, probe_count, table->capacity);
        else
            hash_value = htable_quadratic_probing(initial_hash_value, probe_count, table->capacity);
            
        // increment probe counter
        probe_count++;
    }
    
    // once this point is reached, a location
    // has been found, so insert it
    table->array[hash_value] = key;
    
    // update size
    table->size++;
}

int htable_search(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // retain in case of a collision
    int initial_hash_value = hash_value;
    
    // prevents us from ending in an infinite loop
    int probe_count = 0;
    
    // keep finding until an available slot is found
    while( !(htable_is_location_available( table->array[hash_value] )) ) {
        // prevents an infinite loop
        if(probe_count == table->capacity)
            return 0;
            
        // is this what we are looking for?
        if( table->array[hash_value] == key ) return 1;
        
        // get new location
        // linear probing?
        if( table->is_linear_probing )
            hash_value = htable_linear_probing(initial_hash_value, probe_count, table->capacity);
        else
            hash_value = htable_quadratic_probing(initial_hash_value, probe_count, table->capacity);
        
        // increment probe counter
        probe_count++;
    }
    
    // not found
    return 0;
}

void htable_remove(HashTable *table, int key) {
    // compute the hash value
    int hash_value = htable_hash(table, key);
    
    // retain in case of a collision
    int initial_hash_value = hash_value;
    
    // prevents us from ending in an infinite loop
    int probe_count = 0;
    
    // keep finding until an available slot is found
    while( !(htable_is_location_available( table->array[hash_value] )) ) {
        // prevents an infinite loop
        if(probe_count == table->capacity)
            return;
            
        // is this what we are looking for?
        if( table->array[hash_value] == key ) {
            // mark it as a graveyard
            table->array[hash_value] = DELETED_MARKER;
            
            // update size
            table->size--;
            
            return;
        }
        
        // get new location
        // linear probing?
        if( table->is_linear_probing )
            hash_value = htable_linear_probing(initial_hash_value, probe_count, table->capacity);
        else
            hash_value = htable_quadratic_probing(initial_hash_value, probe_count, table->capacity);
        
        // increment probe counter
        probe_count++;
    }
}

int htable_hash(HashTable *table, int key) {
    return key % table->capacity;
}

void htable_print(HashTable *table) {
    printf("Open Addressing (%s Probing)\n", table->is_linear_probing ? "Linear" : "Quadratic");
    printf("Index | Contents\n");
    printf("------|---------\n");
    
    // loop through each element of the internal
    // array and start printing each element
    for(int i = 0; i < table->capacity; i++) {
        printf("%5d | ", i);
        
        // change representation
        switch( table->array[i] ) {
            case NULL_MARKER:
                printf(" ");
                break;
            case DELETED_MARKER:
                printf("*");
                break;
            default:
                printf("%d", table->array[i]);
        }
        printf("\n");
    }
}

int htable_linear_probing(int loc, int i, int capacity) {
    return (loc+i) % capacity;
}

int htable_quadratic_probing(int loc, int i, int capacity) {
    return ( loc+(i*i) ) % capacity;
}

int htable_is_location_available(int location) {
    return (location == NULL_MARKER || location == DELETED_MARKER);
}


#endif               // End HTABLE_H -- Do not add any code below
