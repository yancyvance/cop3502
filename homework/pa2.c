#include <stdio.h>
#include <string.h>
#include "sll.h"
#define MAX_NUMBER_LENGTH 501
#define INPUT_FILE_NAME "pa2_data.txt"

// COP 3502C Summer 2025
// Student Name: TODO_your_name_here
// File Name: pa2_yoursurname.c
// Note: Rename to use your actual surname. File name should be in lowercase.
// You must remove any whitespaces or dashes from your surname.
// Note: DO NOT modify or remove TODO comments as it will interfere 
// with the grading system.


// function prototypes defined here
// the function definitions are located below the main function
SLList * parse_string(char *str);
void print_number_recursive(SLLNode *node);
SLList * add(SLList *num1, SLList *num2);
int compare_recursive(SLLNode *a, SLLNode *b);
void remove_leading_zeroes(SLList *num);
void destroy_nodes(SLLNode *head);
void sort_number_list(SLList **numbers, int count);
void display_sum(SLList **numbers, int count);
void print_number_list(SLList **numbers, int count);
void print_number(SLList *list);
int compare(SLList *num1, SLList *num2);
int char_to_int(char digit);
void clear_buffer_file(FILE *ifile);


int main(void) {
    // read the input file
    FILE *ifile = fopen(INPUT_FILE_NAME, "r");
    
    // check if the file was opened
    if(ifile == NULL) {
        // if there was a problem, simply return a 1
        printf("There was a problem opening the file. Abort!\n");
        return 1;
    }
    
    // read number of numbers from file
    int number_count;
    fscanf(ifile, "%d", &number_count);
    
    clear_buffer_file(ifile);
    
    // create a dynamic list of numbers 
    // each number is represented by a linked list
    // therefore, this is an array of linked lists
    SLList **numbers = malloc( sizeof(SLList *) * number_count );
    
    // temporary variable holders for the number
    // it will be read as a string
    char str[MAX_NUMBER_LENGTH];
    
    // iterate and process one number at a time
    for(int i = 0; i < number_count; i++) {
        fscanf(ifile, "%s", str);
        
        // parse the number and convert it
        // to a linked list
        numbers[i] = parse_string(str);
        
        // remove leading zeroes
        remove_leading_zeroes( numbers[i] );
    }
    
    // close the input file
    fclose(ifile);
    
    // sort the numbers
    sort_number_list(numbers, number_count);
    
    // print all the numbers
    print_number_list(numbers, number_count);
    
    // print sum of two largest numbers
    // this assumes that the list is sorted
    display_sum(numbers, number_count);
    
    // destroy all the linked lists
    for(int i = 0; i < number_count; i++) {
        sll_destroy_list( numbers[i] );
    }
    
    // destroy the dynamic array
    free(numbers);

    return 0;
}


SLList * parse_string(char *str) {
    // TODO 1 BEGIN
    // TODO: Implement this function to parse a 
    // numeric string (e.g., "12345") into a singly 
    // linked list, with each digit being stored in
    // a single node.



    // TODO 1 END
}


void print_number_recursive(SLLNode *node) {
    // TODO 2 BEGIN
    // TODO: Recursively print the digits in a linked list.
    // It prints all the digits on a single line.


    
    // TODO 2 END
}


SLList * add(SLList *num1, SLList *num2) {
    // TODO 3 BEGIN
    // TODO: Implement addition of two numbers 
    // represented as linked lists. Store the 
    // result in a new linked list.
    
    
    
    // TODO 3 END
}


int compare_recursive(SLLNode *a, SLLNode *b) {    
    // TODO 4 BEGIN
    // TODO: Recursively compare two numbers
    // represented as linked lists.
    // Return -1 if a < b, 1 if a > b, or 0 if they are equal.
    
    
    
    // TODO 4 END
}


void remove_leading_zeroes(SLList *num) {
    // helper function that removes any
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
    // helper function that deallocates
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


void sort_number_list(SLList **numbers, int count) {
    // helper function that accepts an array of numbers
    // and sorts it in ascending order
    for(int i = 0; i < count-1; i++) {
        for(int j = i+1; j < count; j++) {
            if( compare( numbers[i], numbers[j] ) > 0 ) {
                // swap positions
                SLList *tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
}


void display_sum(SLList **numbers, int count) {
    // helper function that gets the sum
    // of the two largest numbers in the list
    // this assumes that the list is sorted in
    // ascending order
    
    // the sum is stored in a new linked list
    SLList *result = add(numbers[count-2], numbers[count-1]);
    
    // print the result
    print_number(numbers[count-2]);
    printf(" + ");
    print_number(numbers[count-1]);
    printf(" = ");
    print_number(result);
    
    // deallocate result
    sll_destroy_list(result);
}


void print_number_list(SLList **numbers, int count) {
    // helper function that simply prints all
    // the numbers in the list
    for(int i = 0; i < count; i++) {
        print_number(numbers[i]);
        printf("\n");
    }
}


void print_number(SLList *list) {
    // wrapper function that simply calls
    // the actual function (recursive) that
    // prints a number on a single line
    print_number_recursive(list->head);
}


int compare(SLList *num1, SLList *num2) {
    // wrapper function that simply calls
    // the actual function (recursive) that
    // compares two numbers
    return compare_recursive(num1->head, num2->head);
}


int char_to_int(char digit) {
    // helper function that returns
    // a numeric representation
    // of a digit that is currently
    // treated as a character
    return digit - '0';
}


void clear_buffer_file(FILE *ifile) {
    // helper function that clears the file buffer
    int c;
    while( (c = fgetc(ifile)) != '\n' && c != EOF );
}
