#include <stdio.h>
#include "htable_sll.h"

// Sample Test Program for Hash Table.

int main(void) {
    // create a hash table
    HashTable *table = htable_create(7);
    
    // print the table first
    htable_print(table);
    
    // insert the following values
    htable_insert(table, 12);
    htable_insert(table, 19);
    htable_insert(table, 26);
    htable_insert(table, 33);
    htable_insert(table, 3);
    
    // print the table again
    htable_print(table);
    
    // check if the following keys exist
    printf("%d\n", htable_search(table, 26));
    printf("%d\n", htable_search(table, 50));
    
    // delete a key
    htable_remove(table, 3);
    htable_remove(table, 19);
    
    // do a search
    printf("%d\n", htable_search(table, 3));
    printf("%d\n", htable_search(table, 19));
    
    // print the table
    htable_print(table);    
    
    // deallocate hash table
    htable_destroy(table);

    return 0;
}
