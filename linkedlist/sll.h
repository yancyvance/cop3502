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

// create and destroy linked list
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
SLLNode * sll_delete(SLList *list, int query);

// various operations, practice
void sll_insert_at(SLList *list, int index, int value);
SLLNode * sll_remove_at(SLList *list, int index);
SLLNode * sll_get_element_at(SLList *list, int index);

// various operations, recursive
void sll_print_recursive(SLLNode *node);
void sll_add_recursive(SLLNode **node_ref, int value);
SLLNode * sll_delete_recursive(SLLNode **node_ref, int query);



// function definitions
SLLNode * sll_create_node(int data) {
    // dynamically allocate a struct
    SLLNode *node = malloc( sizeof(SLLNode) );
    
    if(node == NULL) return NULL;
    
    // initialize the fields
    node->data = data;
    node->next = NULL;
    
    return node;
}

void sll_destroy_node(SLLNode *node) {
    free(node);    
}

// create and destroy linked list
SLList * sll_create_list() {
    // dynamically allocate a struct
    SLList *list = malloc( sizeof(SLList) );
    
    if(list == NULL) return NULL;
    
    // initialize the fields
    list->head = NULL;
    
    return list;
}

void sll_destroy_list(SLList *list) {
    // incomplete
    SLLNode *ptr = list->head;
    SLLNode *tmp;
    
    while(ptr != NULL) {
        // remember next
        tmp = ptr->next;
        
        // destroy current node
        sll_destroy_node(ptr);
        
        // continue
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

int sll_search(SLList *list, int query) {
    SLLNode *ptr = list->head;
    
    // traverse the list and see
    // if the current node's data
    // is what we are looking for
    while( ptr != NULL ) {
        if(ptr->data == query)
            return 1;
        
        ptr = ptr->next;
    }
    
    return 0;
}

int sll_is_empty(SLList *list) {
    return list->head == NULL;    
}

int sll_get_size(SLList *list) {
    SLLNode *ptr = list->head;
    int count = 0;
    
    while( ptr != NULL ) {
        count++;
        
        ptr = ptr->next;
    }
    
    return count;
}

void sll_add_tail(SLList *list, int value) {
    // if the list is empty
    if( sll_is_empty(list) ) {
        // create a node and make it the head
        list->head = sll_create_node(value);
    }
    else {
        SLLNode *ptr = list->head;
        
        // traverse through the list
        // and find your way to the
        // last node and inform it that
        // it will now have a node
        // next to it (after)
        while( ptr != NULL ) {
            // if this is already the last
            // node (because the next
            // is NULL, then, create
            // the new node and update the
            // next pointer then terminate
            if(ptr->next == NULL) {
                ptr->next = sll_create_node(value);
                return;
            }
            
            // keep on moving to
            // the next node
            ptr = ptr->next;
        }
    }
}

void sll_add_head(SLList *list, int value) {
    // if the list is empty
    if( sll_is_empty(list) ) {
        // create a node and make it the head
        list->head = sll_create_node(value);
    }
    else {
        // create a node and set its next
        // pointer to be the current head
        SLLNode *tmp = sll_create_node(value);
        tmp->next = list->head;
        
        // afterward, update the list such
        // that it will now have a new
        // head, that is the new node
        list->head = tmp;
    }
}

SLLNode * sll_remove_tail(SLList *list) {
    // if the list is not empty
    if( !sll_is_empty(list) ) {
        if( list->head->next == NULL ) {
            // Scenario 1: There is only one node in the list
            
            // copy a reference to the node
            SLLNode *tmp = list->head;
            
            // inform the list to not have
            // a head anymore
            list->head = NULL;
            
            // return the reference
            return tmp;
        }
        else {
            // Scenario 2: There is more than one
            // node in the list
            
            SLLNode *ptr = list->head;
            
            // traverse through the list
            // we stop when we reached the
            // second to the last node
            while( ptr->next != NULL ) {
                // do a look ahead in which if
                // we are currently at the
                // second to the last node,
                // then, we stop and begin
                // the removal process
                if(ptr->next->next == NULL) {
                    // copy a reference to the node
                    // we want to remove (the last
                    // node; which is the next
                    // of where we currently are)
                    SLLNode *tmp = ptr->next;
                    
                    // the current node will not
                    // have any next node anymore
                    ptr->next = NULL;
                    
                    // return the reference
                    return tmp;
                }
                
                ptr = ptr->next;
            }
        }
    }
    
    // fallback return
    return NULL;
}

SLLNode * sll_remove_head(SLList *list) {
    // if the list is not empty
    if( !sll_is_empty(list) ) {
        // temporarily copy a reference
        // to the node we are removing
        SLLNode *tmp = list->head;
        
        // update the list such that
        // it will have a new head
        // this covers both scenarios
        // where (1) there is only one element
        // and (2) there is more than one 
        // element in the list
        list->head = list->head->next;
        
        // return a reference to the
        // node that was just removed
        return tmp;
    }
    
    // fallback return
    return NULL;
}

SLLNode * sll_delete(SLList *list, int query) {
    // if list is empty
    if(list->head == NULL) return NULL;
    
    SLLNode *tmp;
    
    // case 1: head matches
    if(list->head->data == query) {
        tmp = list->head;
        list->head = list->head->next;
        tmp->next = NULL;
        return tmp;
    }
    
    // case 2: non-head
    SLLNode *ptr = list->head;
    
    // traverse the list and see
    // if the current node's data
    // is what we are looking for
    while( ptr != NULL ) {
        if(ptr->next->data == query) {
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            tmp->next = NULL;
            return tmp;
        }
        
        ptr = ptr->next;
    }
    
    return NULL;    
}

void sll_print_recursive(SLLNode *node) {
    // if either empty or reached the end
    if(node == NULL) {
        printf("NULL\n");
        return;
    }
    
    // print
    printf("%d -> ", node->data);
    
    // go to the next node
    sll_print_recursive(node->next);
}

void sll_add_recursive(SLLNode **node_ref, int value) {
    // if either empty or reached the end
    if(*node_ref == NULL) {
        // create a new node
        SLLNode *tmp = sll_create_node(value);
        // update the value of this current variable
        *node_ref = tmp;
        return;
    }        
    
    // Recurse on the rest of the list
    sll_add_recursive(&((*node_ref)->next), value);
}

SLLNode * sll_delete_recursive(SLLNode **node_ref, int query) {
    // if either empty or reached the end
    if(*node_ref == NULL) {
        return NULL;
    }

    // if this node has the value we are looking for
    if( (*node_ref)->data == query ) {
        // remember reference to this node first
        SLLNode *tmp = *node_ref;
        // unlink this node
        *node_ref = (*node_ref)->next;
        // for safety
        tmp->next = NULL;
        return tmp;
    }

    // Recurse on the rest of the list
    return sll_delete_recursive(&(*node_ref)->next, query);
}


#endif              // End SLL_H -- Do not add any code below
