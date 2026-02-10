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
SLLNode *sll_delete(SLList *list, int query);
SLLNode *sll_get_element_at(SLList *list, int index);
SLLNode *sll_remove_at(SLList *list, int index);
void sll_insert_at(SLList *list, int index, int val);


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
    list->head = NULL;
    
    // Deallocate the linked list
    sll_destroy_list(list);
    
    /*
    list = sll_create_list();
    for(int i = 1; i <= 10; i+=2) {
        sll_add_head(list, i*10);
        sll_add_tail(list, (i+1)*10);
    } 
    sll_print_list(list);
    sll_destroy_list(list);
    */
    
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
    SLLNode *ptr = list->head;
    SLLNode *tmp;
    
    while( ptr != NULL ) {
        tmp = ptr->next;
        
        sll_destroy_node(ptr);
        
        ptr = tmp;
    }
    
    free(list);
}

void sll_print_list(SLList *list) {
    SLLNode *ptr = list->head;
    
    while( ptr != NULL ) {
        printf("%d -> ", ptr->data);
        
        ptr = ptr->next;
    }
    
    printf("NULL\n");
}

int sll_is_empty(SLList *list) {
    return list->head == NULL;
}

int sll_get_size(SLList *list) {
    int count = 0;
    SLLNode *ptr = list->head;
    
    while( ptr != NULL ) {
        //printf("%d -> ", ptr->data);
        count++;
        
        ptr = ptr->next;
    }
    return count;
}

int sll_search(SLList *list, int query) {
    SLLNode *ptr = list->head;
    
    while( ptr != NULL ) {
        //printf("%d -> ", ptr->data);
        if( ptr->data == query )
            return 1;
            
        ptr = ptr->next;
    }
    
    return 0;
}

void sll_add_head(SLList *list, int val) {
    SLLNode *tmp = sll_create_node(val);
    
    tmp->next = list->head;
    list->head = tmp;
}

void sll_add_tail(SLList *list, int val) {
    if( list->head == NULL ) {
        list->head = sll_create_node(val);
        return;
    }
    
    SLLNode *ptr = list->head;
    
    while( ptr->next != NULL ) {
        ptr = ptr->next;
    }
    
    ptr->next = sll_create_node(val);
}

SLLNode *sll_remove_head(SLList *list) {
    // Note: We need to add a safeguard
    // if the list is empty
    if( sll_is_empty(list) )
        return NULL;
    
    SLLNode *tmp = list->head;
    
    list->head = tmp->next;
    
    return tmp;
}

/*
SLLNode *sll_remove_tail(SLList *list) {
    // Note: We need to add a safeguard
    // if the list is empty
    if( sll_is_empty(list) )
        return NULL;
    
    if( list->head->next == NULL ) {
        SLLNode *tmp = list->head;
        list->head = NULL;
        return tmp;
    }
    
    SLLNode *ptr = list->head;
    while( ptr->next->next != NULL ) {
        ptr = ptr->next;
    }
    
    SLLNode *tmp = ptr->next;
    ptr->next = NULL;
    return tmp;
}
*/

SLLNode *sll_remove_tail(SLList *list) {
    // Note: We need to add a safeguard
    // if the list is empty
    if( sll_is_empty(list) )
        return NULL;
    
    // Uses the concept of trailing pointer    
    SLLNode *ptr = list->head;
    SLLNode *trail = NULL;
    
    while( ptr->next != NULL ) {
        trail = ptr;
        ptr = ptr->next;
    }
    
    // Check if head
    if( trail == NULL ) {
        SLLNode *tmp = list->head;
        list->head = NULL;
        return tmp;
    }
    
    trail->next = NULL;
    return ptr;
}

SLLNode *sll_delete(SLList *list, int query) {
    // Note: We need to add a safeguard
    // if the list is empty
    if( sll_is_empty(list) )
        return NULL;
        
    // Perform a search but stop at the node
    // prior to the query's node
    // Recall: When deleting a node,
    // we need to update the node that comes
    // before it
    SLLNode *ptr = list->head;
    SLLNode *trail = NULL;
    
    while( ptr != NULL ) {
        //printf("%d -> ", ptr->data);
        if( ptr->data == query )
            break;
        
        trail = ptr;
        ptr = ptr->next;
    }
    
    // Node is found
    if( ptr ) {
        // Check if head
        if( trail == NULL ) {
            return sll_remove_head( list );
        }
        else {
            trail->next = ptr->next;
            return ptr;
        }
    }
    
    return NULL;
}

SLLNode *sll_get_element_at(SLList *list, int index) {
    // Similar to getting the size
    int count = 0;
    SLLNode *ptr = list->head;
    
    while( ptr != NULL ) {
        if( count == index )
            return ptr;
            
        count++;
        ptr = ptr->next;
    }
    
    return NULL;
}

SLLNode *sll_remove_at(SLList *list, int index) {
    // Similar to get element at AND delete
    int count = 0;
    SLLNode *ptr = list->head;
    SLLNode *trail = NULL;
    
    while( ptr != NULL ) {
        if( count == index )
            break;
            
        count++;
        trail = ptr;
        ptr = ptr->next;
    }
    
    // Node is found
    if( ptr ) {
        // Check if head
        if( trail == NULL ) {
            return sll_remove_head( list );
        }
        else {
            trail->next = ptr->next;
            return ptr;
        }
    }
    
    return NULL;
}

void sll_insert_at(SLList *list, int index, int val) {
    // Similar to remove at
    int count = 0;
    SLLNode *ptr = list->head;
    SLLNode *trail = NULL;
    
    while( ptr != NULL ) {
        if( count == index )
            break;
            
        count++;
        trail = ptr;
        ptr = ptr->next;
    }
    
    
    // Check if head
    if( trail == NULL ) {
        sll_add_head(list, val);
    }
    else {
        // create a node
        SLLNode *tmp = sll_create_node(val);
        tmp->next = ptr;
        trail->next = tmp;
    }
}
