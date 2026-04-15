#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 255
#define IS_LINEAR_PROBING 1
#define DELETED_MARKER (PersonItem*) -1

// Sample C Implementation of a hash table (open addressing).
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2026-04-15.


typedef struct PersonItem_s {
    char *key;
    char *name;
    int age;
} PersonItem;

typedef struct HashTable_s {
    // we have a pointer to pointers
    PersonItem **table;
    int capacity;
    int size;
} HashTable;



// function prototypes
HashTable * create_hash_table(int);
void destroy_hash_table(HashTable *);
PersonItem * create_person(char *, char *, int);
void destroy_person(PersonItem *);
int string_to_int(char *);
int hash_function(HashTable *, int);
void insert(HashTable *, PersonItem *);
PersonItem * search_table(HashTable *, char *);
PersonItem * delete_item(HashTable *, char *);
int linear_probing(int, int, int);
int quadratic_probing(int, int, int);
int is_location_available(PersonItem *);
void display_person(PersonItem *);
void display_table(HashTable *);



int main(void) {
    // dynamically allocate the table
    HashTable *hash_table = create_hash_table(11);

    // insert the following data
    insert(hash_table, create_person("bob123", "Bob Smith", 20));
    insert(hash_table, create_person("obb123", "John Doe", 25));

    // print the table
    display_table(hash_table);

    // this will hold the query string
    // assume that no white space
    char query[MAX_WORD_SIZE];

    printf("Query: ");
    scanf("%s", query);     // "bob123"

    // do a lookup on the table
    PersonItem *tmp = search_table(hash_table, query);

    // check if this exists in the table
    if(tmp) {
        printf("Record Found!\n");
        display_person(tmp);
    }
    else {
        printf("No Record Found!\n");
    }

    // delete a record
    tmp = delete_item(hash_table, "bob123");

    if(tmp) {
        printf("Record Deleted!\n");

        // deallocate the person
        destroy_person(tmp);
    }

    // print the table
    display_table(hash_table);


    // deallocate the table
    destroy_hash_table(hash_table);

    return 0;
}



HashTable * create_hash_table(int capacity) {
    // dynamically allocate this array of
    // pointers to PersonItems given capacity
    HashTable *hash_table = malloc(sizeof(HashTable));

    // dynamically allocate this array of pointers to PersonItem
    hash_table->table = malloc(sizeof(PersonItem*) * capacity);

    // set all the pointers to NULL
    // to prevent from dealing with garbage values
    for(int i = 0; i < capacity; i++)
        hash_table->table[i] = NULL;

    hash_table->capacity = capacity;
    hash_table->size = 0;

    return hash_table;
}


void destroy_hash_table(HashTable *hash_table) {
    // traverse through each of the elements
    // of the dynamic array, and individually
    // destroy the linked list
    for(int i = 0; i < hash_table->capacity; i++) {
        // check if there is a person existing
        // at this location
        if(hash_table->table[i] != NULL)
            destroy_person(hash_table->table[i]);
    }
    
    free(hash_table->table);

    // destroy the hash table itself
    free(hash_table);
}


PersonItem * create_person(char *key, char *name, int age) {
    // dynamically create a person
    PersonItem *person = malloc(sizeof(PersonItem));

    // set the appropriate attributes
    // dynamically allocate for the string
    // note that we add plus 1 due to the NULL
    // terminator for the string
    person->key = malloc(sizeof(char) * (strlen(key)+1));
    person->name = malloc(sizeof(char) * (strlen(name)+1));

    // we then copy the value of the arguments
    strcpy(person->key, key);
    strcpy(person->name, name);
    person->age = age;

    return person;
}


void destroy_person(PersonItem *person) {
    // if not an actual person
    if(person == NULL || person == DELETED_MARKER)
        return;

    // deallocate the strings
    free(person->key);
    free(person->name);

    // deallocate the person
    free(person);
}


int string_to_int(char *str) {
    // this is a helper function that converts
    // a string to an integer; it does this
    // by getting the sum of the ascii of the
    // characters in str
    int sum_of_ascii = 0;

    // we simply get the sum of the lowercase
    // version of all the letters of str
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        sum_of_ascii = sum_of_ascii + str[i];

    return sum_of_ascii;
}


int hash_function(HashTable *hash_table, int key) {
    // the following is a simple hash function
    // that maps a key to a corresponding number
    // in the range of 0 to size of
    // hash table, inclusive; this is
    // done through modulo operator
    // this is called the division method
    return key % hash_table->capacity;
}


void insert(HashTable *hash_table, PersonItem *data) {
    // check first if there is enough space
    if(hash_table->size == hash_table->capacity) {
        printf("Error. Not enough space!\n");
        return;
    }

    // convert the string to an int
    int key = string_to_int(data->key);
    // hash the given int
    int hash_value = hash_function(hash_table, key);
    // retain the initial hash value in case of collision
    int initial_hash_value = hash_value;
    // the following keeps track the number
    // of attempts we looked at; it prevents
    // infinite loops
    int attempt = 0;

    // keep finding an available location
    // stop once we find one!
    while( !(is_location_available(hash_table->table[hash_value])) ) {
        // this just prevents us from
        // entering an infinite loop
        // as a consequence of the choice
        // of the probing strategy
        if(attempt == hash_table->capacity)
            return;

        // go to the next space then apply
        // the hash function again
        if(IS_LINEAR_PROBING)
            hash_value = linear_probing(initial_hash_value, attempt, hash_table->capacity);
        else
            hash_value = quadratic_probing(initial_hash_value, attempt, hash_table->capacity);

        // increment counter
        attempt++;
    }

    // once this point is reached, then
    // it means we are able to find an available
    // spot, so set the pointer at this location
    hash_table->table[hash_value] = data;
    // increment the size
    hash_table->size++;
}


PersonItem * search_table(HashTable *hash_table, char *str) {
    // this function searches a hash table
    // convert the string to an int
    int key = string_to_int(str);
    // hash the given int
    int hash_value = hash_function(hash_table, key);
    // retain the initial hash value in case of collision
    int initial_hash_value = hash_value;
    // the following keeps track the number
    // of attempts we looked at; it prevents
    // infinite loops
    int attempt = 0;

    // start at the initial location
    // a naive search would simply stop if we end
    // up on a NULL slot; however, this would lead
    // to a logical error when we delete an item
    // that is in the middle of the chain formed
    // by the probing sequence! therefore, we
    // further check if this slot used to have an
    // element so that we can continue looking
    // and not prematurely terminate the search!
    while( hash_table->table[hash_value] != NULL ) {
        // this just prevents us from
        // entering an infinite loop
        // as a consequence of the choice
        // of the probing strategy
        if(attempt == hash_table->capacity)
            return NULL;

        // a temporary person pointer
        PersonItem *ptr = hash_table->table[hash_value];

        // only if this is not a tombstone
        // is this what we are looking for?
        if( ptr != DELETED_MARKER && strcmp(ptr->key, str) == 0 ) {
            // if it is, then return the person
            return ptr;
        }

        // otherwise, we continue looking for
        // the next possible location (probe)
        if(IS_LINEAR_PROBING)
            hash_value = linear_probing(initial_hash_value, attempt, hash_table->capacity);
        else
            hash_value = quadratic_probing(initial_hash_value, attempt, hash_table->capacity);

        // increment counter
        attempt++;
    }

    // once this point is reached, then
    // it means that our search failed, therefore
    // stop and the key is not found
    return NULL;
}


PersonItem * delete_item(HashTable *hash_table, char *str) {
    // this function deletes an item from a hash table
    // however, it does not do the actual deallocation
    // it must be done by the calling function
    // convert the string to an int
    int key = string_to_int(str);
    // hash the given int
    int hash_value = hash_function(hash_table, key);
    // retain the initial hash value in case of collision
    int initial_hash_value = hash_value;
    // the following keeps track the number
    // of attempts we looked at; it prevents
    // infinite loops
    int attempt = 0;

    // start at the initial location
    // a naive search would simply stop if we end
    // up on a NULL slot; however, this would lead
    // to a logical error when we delete an item
    // that is in the middle of the chain formed
    // by the probing sequence! therefore, we
    // further check if this slot used to have an
    // element so that we can continue looking
    // and not prematurely terminate the search!
    while( hash_table->table[hash_value] != NULL ) {
        // this just prevents us from
        // entering an infinite loop
        // as a consequence of the choice
        // of the probing strategy
        if(attempt == hash_table->capacity)
            return NULL;

        // a temporary person pointer
        PersonItem *ptr = hash_table->table[hash_value];

        // only if this is not a tombstone
        // is this what we are looking for?
        if( ptr != DELETED_MARKER && strcmp(ptr->key, str) == 0 ) {
            // replace this location with the DELETED_MARKER
            // to indicate that there used to be
            // an element here; this will ensure
            // our search will not break!
            hash_table->table[hash_value] = DELETED_MARKER;

            // decrement the size
            hash_table->size--;

            // the actual deallocation of this
            // person will be done by the calling
            // function and not here!
            // return the person
            return ptr;
        }

        // otherwise, we continue looking for
        // the next possible location (probe)
        if(IS_LINEAR_PROBING)
            hash_value = linear_probing(initial_hash_value, attempt, hash_table->capacity);
        else
            hash_value = quadratic_probing(initial_hash_value, attempt, hash_table->capacity);

        // increment counter
        attempt++;
    }

    // once this point is reached, then
    // it means that our search failed, therefore
    // stop and the key is not found
    return NULL;
}


int linear_probing(int loc, int i, int capacity) {
    // this function performs linear probing
    // strategy when there is a collision
    // it accepts an original location
    // and returns what the next location
    // to check; it wraps-around based on
    // the capacity of the table
    return (loc+i) % capacity;
}


int quadratic_probing(int loc, int i, int capacity) {
    // this function performs quadratic probing
    // strategy when there is a collision
    // it accepts an original location
    // and the i-th (0-based) attempt we
    // are currently looking for an empty
    // location; it wraps-around based on
    // the capacity of the table
    return ( loc+(i*i) ) % capacity;
}


int is_location_available(PersonItem *loc) {
    // helper function that checks whether
    // a given slot of the hash table is
    // available; a slot is available
    // if it currently is NULL or if it is
    // the DELETED_MARKER (currently empty
    // but used to have a value)
    // note: the parameter is an element
    // of a dynamic array which is a pointer
    // to a person in our example
    return (loc == NULL || loc == DELETED_MARKER);
}


void display_person(PersonItem *person) {
    // helper function to just display
    // the person's details
    printf("ID: %s\n", person->key);
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}


void display_table(HashTable *hash_table) {
    printf("Hash Table Contents:\n");
    // iterate through all the elements
    for(int i = 0; i < hash_table->capacity; i++) {
        // check if there is a list
        if( !(is_location_available(hash_table->table[i])) )
            // print the contents of this list
            display_person(hash_table->table[i]);
    }
}
