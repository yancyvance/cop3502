#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 255

// Sample C Implementation of a hash table (chaining).
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2026-04-15.


typedef struct PersonItem_s {
    char *key;
    char *name;
    int age;
} PersonItem;

typedef struct LLNode_s {
    PersonItem *data;
    struct LLNode_s *next;
} LLNode;

typedef struct LList_s {
    LLNode *head;
    LLNode *tail;
} LList;

typedef struct HashTable_s {
    // we have a pointer to pointers
    LList **table;
    int capacity;
} HashTable;



// function prototypes
HashTable * create_hash_table(int);
void destroy_hash_table(HashTable *);
PersonItem * create_person(char *, char *, int);
void destroy_person(PersonItem *);
LLNode * create_node(PersonItem *);
void destroy_node(LLNode *);
LList * create_linked_list();
void destroy_linked_list(LList *);
void destroy_linked_list_recursive(LLNode *);
void add_to_tail(LList *, PersonItem *);
int string_to_int(char *);
int hash_function(HashTable *, int);
void insert(HashTable *, PersonItem *);
PersonItem * search_table(HashTable *, char *);
PersonItem * delete_item(HashTable *, char *);
LLNode * linked_list_search(LList *, char *);
LLNode * linked_list_delete(LList *, char *);
void display_person(PersonItem *);
void display_table(HashTable *);
void recursive_print_node(LLNode *);



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
    // pointers to LLists given capacity
    HashTable *hash_table = malloc(sizeof(HashTable));

    // dynamically allocate this array of pointers to LList
    hash_table->table = malloc(sizeof(LList*) * capacity);

    // set all the pointers to NULL
    // to prevent from dealing with garbage values
    for(int i = 0; i < capacity; i++)
        hash_table->table[i] = NULL;

    hash_table->capacity = capacity;

    return hash_table;
}


void destroy_hash_table(HashTable *hash_table) {
    // traverse through each of the elements
    // of the dynamic array, and individually
    // destroy the linked list
    for(int i = 0; i < hash_table->capacity; i++) {
        // check if there is a linked list existing
        // at this location
        if(hash_table->table[i] != NULL) {
            destroy_linked_list(hash_table->table[i]);
        }
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
    if(person == NULL)
        return;

    // deallocate the strings
    free(person->key);
    free(person->name);

    // deallocate the person
    free(person);
}


LLNode * create_node(PersonItem *data) {
    // dynamically create a node
    LLNode *node = malloc(sizeof(LLNode));

    // set the appropriate attributes
    node->data = data;

    // set the next to NULL
    node->next = NULL;

    return node;
}


void destroy_node(LLNode *node) {
    // destroy the person
    destroy_person(node->data);

    // deallocate the node itself
    free(node);
}


LList * create_linked_list() {
    // dynamically allocate one
    LList *list = malloc(sizeof(LList));

    // initialize the members
    list->head = NULL;
    list->tail = NULL;

    return list;
}


void destroy_linked_list(LList *list) {
    // if the linked list is not empty
    // traverse until the tail is reached
    // this is a wrapper function to the
    // recursive solution
    destroy_linked_list_recursive(list->head);
    free(list);
}


void destroy_linked_list_recursive(LLNode *node) {
    // this is a recursive function that
    // deallocates the nodes of a linked
    // list from the tail going back to
    // the head of the list
    // base case is if there is no more
    // node to visit
    if(node == NULL)
        return;

    // visit the next node
    destroy_linked_list_recursive(node->next);

    // deallocate the node
    // think: it is like the postorder traversal
    // of a tree if you come to think of it
    // the call above is the L or R
    // the code below this is the V
    destroy_node(node);
}


void add_to_tail(LList *list, PersonItem *val) {
    // if linked list is empty, then set
    // the head and tail
    if(list->head == NULL) {
        list->head = list->tail = create_node(val);
        return;
    }

    // otherwise, simply add a new to the tail
    // create a temp node
    LLNode *tmp = create_node(val);
    list->tail->next = tmp;
    // update to have a new tail
    list->tail = tmp;
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
    // hash table minus 1, inclusive; this is
    // done through modulo operator
    // this is called the division method
    return key % hash_table->capacity;
}


void insert(HashTable *hash_table, PersonItem *data) {
    // convert the string to an int
    int key = string_to_int(data->key);
    // hash the given int
    int hash_value = hash_function(hash_table, key);

    // check first if there is already a linked
    // list existing in this location, if none
    // create an empty one
    if( hash_table->table[hash_value] == NULL )
        hash_table->table[hash_value] = create_linked_list();

    // add to tail at the hash_value's location
    add_to_tail( hash_table->table[hash_value], data );
}


PersonItem * search_table(HashTable *hash_table, char *str) {
    // this function searches a hash table
    // convert the string to an int
    int key = string_to_int(str);
    // hash the given int
    int hash_value = hash_function(hash_table, key);

    // check if there is a list first
    if(hash_table->table[hash_value] != NULL) {
        // do a search operation on a linked list
        LLNode *node = linked_list_search(hash_table->table[hash_value], str);

        // return the person's data
        if(node)
            return node->data;
    }

    // it is not found
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

    // check if there is a list first
    if(hash_table->table[hash_value] != NULL) {
        // do a delete operation on a linked list
        LLNode *node = linked_list_delete(hash_table->table[hash_value], str);

        // return the person's data
        if(node) {
            PersonItem *data = node->data;
            free(node);
            return data;
        }
    }

    // it is not found
    return NULL;
}


LLNode * linked_list_search(LList *list, char *str) {
    // check if the list is empty or not
    if(list->head == NULL)
        return NULL;

    LLNode *ptr = list->head;
    while(ptr != NULL) {
        // if this node has data
        // that we are looking for
        // we are dealing with a string
        if( strcmp(ptr->data->key, str) == 0 )
            return ptr;

        // go to the next
        ptr = ptr->next;
    }

    return NULL;
}


LLNode * linked_list_delete(LList *list, char *str) {
    // check if the list is empty or not
    if(list->head == NULL)
        return NULL;

    // the trailing pointer is to
    // keep track the node right before
    // what we want to delete
    LLNode *trail = NULL;
    LLNode *ptr = list->head;
    while(ptr != NULL) {
        // if this node has data
        // that we are looking for
        // we are dealing with a string
        if( strcmp(ptr->data->key, str) == 0 ) {
            // check first if the trailing
            // pointer is NULL, because
            // that means ptr is the head
            // so update the list
            if(trail == NULL) {
                // new head of the list then
                list->head = ptr->next;
            }
            else {
                // otherwise, we just
                // remove ptr and update
                // its parent to have a new
                // child node
                trail->next = ptr->next;
            }

            // did we just remove the tail?
            if(list->tail == ptr) {
                // update the tail to be the
                // trailing pointer
                list->tail = trail;
            }

            // reset the next for cleanup
            ptr->next = NULL;

            // return the node found
            return ptr;
        }

        // go to the next; but update
        // the trailing pointer first
        trail = ptr;
        ptr = ptr->next;
    }

    return NULL;
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
        if(hash_table->table[i])
            // print the contents of this list
            recursive_print_node(hash_table->table[i]->head);
    }
}


void recursive_print_node(LLNode *node) {
    if(node == NULL)
        return;

    // display this person
    display_person(node->data);

    // recursively call the function
    recursive_print_node(node->next);
}
