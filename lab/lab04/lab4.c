#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 26
#define INPUT_FILE "numbers.txt"

typedef struct SLLNode_s {
    int data;                       // A single digit
    struct SLLNode_s *next;
} SLLNode;

typedef struct SLList_s {
    SLLNode *head;
} SLList;


// Function Prototypes
SLList *parse_string(char *str);
void print_number_recursive(SLLNode *node);
SLList *add(SLList *num1, SLList *num2);
int is_palindrome(SLList *num);

// Housekeeping Functions
SLLNode *sll_create_node(int val);
void sll_destroy_node(SLLNode *node);
SLList *sll_create_list();
void sll_destroy_list(SLList *list);

// Helper Functions
void sll_add_head(SLList *list, int val);
void sll_add_tail(SLList *list, int val);
int sll_get_size(SLList *list);
void print_number(SLList *list);
int char_to_int(char digit);
void remove_leading_zeroes(SLList *num);
void destroy_nodes(SLLNode *ptr);


// BEGIN: DO NOT MODIFY THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Open the file
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    // Safeguard in the event the file cannot be opened
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    int N;
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    
    // Determine how many pairs to process
    fscanf(ifile, "%d", &N);
    
    // For each pair of numbers (one pair per line)
    for(int i = 0; i < N; i++) {
        // Read two numeric strings
        fscanf(ifile, "%s %s", str1, str2);
        
        // Convert the strings into linked lists
        SLList *num1 = parse_string(str1);
        SLList *num2 = parse_string(str2);
        
        // Uncomment for the guide question
        //remove_leading_zeroes(num1);
        //remove_leading_zeroes(num2);
        
        // Get the sum of the two numbers
        SLList *sum = add(num1, num2);
        
        // Print the results
        print_number(sum);
        printf(" - ");
        
        // Check if the sum is palindrome
        if( is_palindrome(sum) )
            printf("Palindrome");
        else
            printf("Not Palindrome");
            
        printf("\n");
        
        // Deallocate the linked lists
        // because each parse_string() call
        // creates a brand new list; this
        // prevents any memory leak
        sll_destroy_list(sum);
        sll_destroy_list(num1);
        sll_destroy_list(num2);
    }
    
    // Close the file
    fclose(ifile);
    
    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION


// Function Definitions
SLList *parse_string(char *str) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    
    
    
    
    
    // TODO 1 END
}

void print_number_recursive(SLLNode *node) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    
    
    
    
    
    // TODO 2 END
}

SLList *add(SLList *num1, SLList *num2) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    
    
    
    
    
    // TODO 3 END
}

int is_palindrome(SLList *num) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    
    
    
    
    
    // TODO 4 END
}

SLLNode *sll_create_node(int val) {
    // Helper function to dynamically create
    // a single node
    SLLNode *n = malloc(sizeof(SLLNode));
    
    n->data = val;
    n->next = NULL;
    
    return n;
}

void sll_destroy_node(SLLNode *node) {
    // Destroy a node
    free(node);
}

SLList *sll_create_list() {
    // Helper function to dynamically create 
    // an empty linked list
    SLList *list = malloc(sizeof(SLList));
    
    list->head = NULL;
    
    return list;
}

void sll_destroy_list(SLList *list) {
    // Destroy a linked list and all its
    // corresponding nodes
    
    // if the list is not existing
    if(list == NULL) return;
    
    // Destory all the nodes first
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

void sll_add_head(SLList *list, int val) {
    // Helper function to add a node at
    // the head side of the linked list
    SLLNode *tmp = sll_create_node(val);
    
    tmp->next = list->head;
    list->head = tmp;
}

void sll_add_tail(SLList *list, int val) {
    // Helper function to add a node at
    // the tail side of the linked list
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

int sll_get_size(SLList *list) {
    // Helper function to determine the
    // size of a linked list
    int count = 0;
    SLLNode *ptr = list->head;
    
    while( ptr != NULL ) {
        count++;
        
        ptr = ptr->next;
    }
    return count;
}

void print_number(SLList *list) {
    // Wrapper function that simply calls
    // the actual function (recursive) that
    // prints a number on a single line
    print_number_recursive(list->head);
}

int char_to_int(char digit) {
    // Helper function that returns
    // a numeric representation
    // of a digit that is currently
    // treated as a character
    return digit - '0';
}

void remove_leading_zeroes(SLList *num) {
    // Helper function that removes any
    // leading zeroes; however if the
    // number is simply zero, it retains
    // a single node to represent it
    SLLNode *ptr = num->head;
    SLLNode *last_non_zero = ptr;
    
    // do this as long as
    // there is still a node
    while(ptr != NULL) {
        // if this node has a
        // non-zero digit, update
        // the tracker
        if(ptr->data != 0)
            last_non_zero = ptr;
            
        // go to the next node
        ptr = ptr->next;
    }
    
    // if the last non-zero node
    // has nodes after it, it means
    // they are all leading zeroes,
    // so destroy them
    if(last_non_zero->next != NULL) {
        destroy_nodes(last_non_zero->next);
        
        // update reference
        // to indicate that this
        // is now the last node
        last_non_zero->next = NULL;
    }
}

void destroy_nodes(SLLNode *ptr) {
    // Helper function that deallocates
    // all the nodes of a list starting
    // at the ptr node
    SLLNode *tmp;
    
    // do this as long as
    // there is still a node
    while(ptr != NULL) {
        // temporarily store the
        // reference of the next
        // node of the current node
        tmp = ptr->next;
        
        // destroy current node
        sll_destroy_node(ptr);
        
        // resume going to the
        // next node
        ptr = tmp;
    }
}
