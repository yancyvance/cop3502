#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode_s {
    int data;
    struct SLLNode_s *next;
} SLLNode;

typedef struct SLList_s {
    SLLNode *head;
} SLList;


// Function Prototypes

// Housekeeping for Nodes
SLLNode *sll_create_node(int val);
void sll_destroy_node(SLLNode *node);

// Housekeeping for Linked List
SLList *sll_create_list();
void sll_destroy_list(SLList *list);

// Essential Operations
void sll_print_list(SLList *list);
int sll_is_empty(SLList *list);
int sll_get_size(SLList *list);
int sll_search(SLList *list, int query);
void sll_add_head(SLList *list, int val);
void sll_add_tail(SLList *list, int val);
SLLNode *sll_remove_head(SLList *list);
SLLNode *sll_remove_tail(SLList *list);

// Additional for Exercise
SLLNode *sll_get_at(int pos);
void sll_insert_at(int pos, int val);


int main(void) {
    // Dynamically create a linked list
    SLList *list = sll_create_list();
    
    // Populate the linked list
    list->head = sll_create_node(10);
    list->head->next = sll_create_node(20);
    list->head->next->next = sll_create_node(30);
    
    // Print the contents of the linked list
    sll_print_list(list);
    
    // Deallocate all the nodes
    sll_destroy_node(list->head->next->next);
    sll_destroy_node(list->head->next);
    sll_destroy_node(list->head);
    
    // Deallocate the linked list
    sll_destroy_list(list);
    
    return 0;
}


// Function Definitions
SLLNode *sll_create_node(int val) {
    SLLNode *n = malloc(sizeof(SLLNode));
    
    n->data = val;
    n->next = NULL;
    
    return n;
}

void sll_destroy_node(SLLNode *node) {
    free(node);
}

SLList *sll_create_list() {
    SLList *list = malloc(sizeof(SLList));
    
    list->head = NULL;
    
    return list;
}

void sll_destroy_list(SLList *list) {
    // Incomplete
    
    free(list);
}

void sll_print_list(SLList *list) {

}

int sll_is_empty(SLList *list) {

}

int sll_get_size(SLList *list) {
    
}

int sll_search(SLList *list, int query) {
    
}

void sll_add_head(SLList *list, int val) {
    
}

void sll_add_tail(SLList *list, int val) {
    
}

SLLNode *sll_remove_head(SLList *list) {
    
}

SLLNode *sll_remove_tail(SLList *list) {
    
}
