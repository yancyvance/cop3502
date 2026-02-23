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
    
    // Get the length of the numeric string
    // Note: We do not include the null character
    // in the count
    int len = strlen(str);
    
    // Create an empty linked list
    SLList *number = sll_create_list();
    
    // Perform an add to head len number of times
    // where each node corresponds to a digit
    // in the numeric string. Recall that
    // numbers will be represented in reverse
    // order that is why we are performing add
    // to head
    for(int i = 0; i < len; i++) {
        // We call our helper function that converts
        // a digit character into an integer
        sll_add_head( number, char_to_int(str[i]) );
    }
    
    // Return the populated linked list
    return number;
    
    // TODO 1 END
}

void print_number_recursive(SLLNode *node) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    
    // Base case is if there is no more node left
    // or we have reached the end of the list
    if(node == NULL)
        return;
        
    // Recall: The digits are in reverse order
    // in the linked list
    
    // Strategy: Head Recurisve
    // Recursive call first before processing
    // the next statements; recall that this is
    // similar to the count_up() behavior we did
    // during the discussion of recursion
    print_number_recursive(node->next);
    
    // Print the data of this node
    printf("%d", node->data);
    
    // TODO 2 END
}

SLList *add(SLList *num1, SLList *num2) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    
    // Strategy: Run through the two linked
    // lists in parallel
    SLLNode *ptr1 = num1->head;
    SLLNode *ptr2 = num2->head;
    
    // Prepare an empty linked list for the result
    SLList *result = sll_create_list();
    
    // d1 is the digit at ptr1
    // d2 is the digit at ptr2
    // d3 is the digit at result
    // They are all parallel to each other
    int d1, d2, d3;
    // carry will be an extra digit we
    // need to add in the next position
    // We initialize it to 0; as per algorithm
    int carry = 0;
    
    // While there is still a node in 
    // either num1 OR num2, we keep on computing
    while( ptr1 != NULL || ptr2 != NULL ) {
        // If there is no more node for num1,
        // we assume the digit is 0; otherwise
        // get the actual digit
        if(ptr1 == NULL)
            d1 = 0;
        else
            d1 = ptr1->data;
        
        // If there is no more node for num2,
        // we assume the digit is 0; otherwise
        // get the actual digit
        if(ptr2 == NULL)
            d2 = 0;
        else
            d2 = ptr2->data;
        
        // Get the sum of the two digits
        // and forward any carry from a previous
        // position; at the first iteration
        // it is 0; but in further positions
        // it may be non zero
        d3 = d1 + d2 + carry;
        
        // If the result is composed of 2 digits,
        // we extract the ones digit (right) and
        // retain and store it to be d3; the left
        // digit (usually a 1) will be set as the
        // carry for the next iteration
        if(d3 > 9) {
            carry = 1;      // for the next round
            d3 = d3 % 10;   // get one's digit (right)
        }
        else {
            carry = 0;      // Reset any leftover carry
        }
        
        // Add a new node at the tail side
        // of the result linked list, use the
        // digit held by d3 as the data
        sll_add_tail(result, d3);
        
        // Go to the next digit for num1, only if possible
        if(ptr1)
            ptr1 = ptr1->next;
            
        // Go to the next digit for num2, only if possible
        if(ptr2)
            ptr2 = ptr2->next;
    }
    
    // Do one more check if there is still a carry
    // and if there is, simply create one last node
    if(carry)
        sll_add_tail(result, carry);
    
    return result;
    
    // TODO 3 END
}

int is_palindrome(SLList *num) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    
    // Strategy: Instead of dealing with the
    // linked list where it is complicated to
    // perform a reverse traversal, we simply
    // create an auxiliary array and copy
    // all digits to the array; it is easier
    // to perform direct access with an array
    
    // Determine the size of the linked
    // list as this is needed to allocate
    // enough space for an auxiliary array
    int len = sll_get_size(num);
    
    // Dynamically allocate a temporary array
    int *arr = malloc(sizeof(int) * len);
    
    // Perform a traversal of all the nodes
    SLLNode *ptr = num->head;
    
    // Safe to assume that there will be
    // len iterations so we can use a for
    // loop instead of the typical while
    // loop we have
    for(int i = 0; i < len; i++) {
        // Simply set the elements of
        // the array
        arr[i] = ptr->data;
        
        ptr = ptr->next;
    }
    
    // This is the typical code to
    // check if an array is symmetric
    // or not; we assume that it is
    // symmetric unless proven otherwise
    int is_symmetric = 1;
    
    // note that we don't have to
    // traverse through the entire array
    // halfway through is enough
    for(int i = 0; i < len/2; i++) {
        // In the first instance of a
        // mismatch, stop as this
        // is not symmetric anymore
        if(arr[i] != arr[len-1-i]) {
            is_symmetric = 0;
            break;
        }
    }
    
    // deallocate the dynamic array
    free(arr);
    
    return is_symmetric;
    
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
