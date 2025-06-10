#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Singly Linked List.



// structs needed
typedef struct SLLNode_s {
    int data;
    struct SLLNode_s *next;
} SLLNode;

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
void sll_add_to_tail(SLList *, int);
void sll_add_to_head(SLList *, int);
SLLNode * sll_remove_tail(SLList *);
SLLNode * sll_remove_head(SLList *);

// various operations, practice
void sll_insert_at(SLList *, int, int);
SLLNode * sll_remove_at(SLList *, int);
SLLNode * sll_get_element_at(SLList *, int);
SLLNode * sll_delete(SLList *, int);

// various operations, recursive (practice)
void sll_print_list_recursive(SLLNode *);
void sll_insert_at_recursive(SLLNode **, int, int);
SLLNode * sll_remove_at_recursive(SLLNode **, int);



int main(void) {
    // create a list
    
    // add a node
    
    
    
    
    
    // destroy the list
    
    
    return 0;
}



// function definitions
SLLNode * sll_create_node(int data) {
    
    
    
}

void sll_destroy_node(SLLNode *node) {
    
    
    
}

// create and destory linked list
SLList * sll_create_list() {
    
    
    
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
