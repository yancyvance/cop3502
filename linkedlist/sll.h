#ifndef SLL_H       // Check if SLL_H is not defined
#define SLL_H       // Define SLL_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Singly Linked List.



// The SLLNode struct represents a Singly Linked 
// List Node that holds a single integer.
typedef struct SLLNode_s {
    int data;
    struct SLLNode_s *next;
} SLLNode;

// The SLList struct represents a Singly Linked 
// List that keeps track of the first node (head).
typedef struct SLList_s {
    SLLNode *head;
} SLList;


// function prototypes defined here

// create and destroy nodes
SLLNode * sll_create_node(int);
void sll_destroy_node(SLLNode *);

// create and destory linked list
SLList * sll_create_list();
void sll_destroy_list(SLList *);

// various operations, important
void sll_print_list(SLList *);
int sll_search(SLList *, int);
int sll_is_empty(SLList *);
int sll_get_size(SLList *);
void sll_add_tail(SLList *, int);
void sll_add_head(SLList *, int);
SLLNode * sll_remove_tail(SLList *);
SLLNode * sll_remove_head(SLList *);

// various operations, practice
void sll_insert_at(SLList *, int, int);
SLLNode * sll_remove_at(SLList *, int);
SLLNode * sll_get_element_at(SLList *, int);



// function definitions
SLLNode * sll_create_node(int data) {
    // dynamically allocate a struct
    SLLNode *node = malloc( sizeof(SLLNode) );
    
    // initialize the fields
    node->data = data;
    node->next = NULL;
    
    return node;
}

void sll_destroy_node(SLLNode *node) {
    free(node);    
}

// create and destory linked list
SLList * sll_create_list() {
    // dynamically allocate a struct
    SLList *list = malloc( sizeof(SLList) );
    
    // initialize the fields
    list->head = NULL;
    
    return list;
}

void sll_destroy_list(SLList *list) {
    // incomplete
    
    
    
}

void sll_print_list(SLList *list) {


    
}

int sll_search(SLList *list, int query) {
    
    
    
}

int sll_is_empty(SLList *list) {
    

    
}

int sll_get_size(SLList *list) {
    

    
}

void sll_add_to_tail(SLList *list, int value) {
    
    
    
}

void sll_add_to_head(SLList *list, int value) {
    
    
    
}

SLLNode * sll_remove_tail(SLList *list) {
    
    
    
}

SLLNode * sll_remove_head(SLList *list) {
    
    
    
}

#endif              // End SLL_H -- Do not add any code below
