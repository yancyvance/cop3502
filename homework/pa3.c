#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define INPUT_FILE_NAME "pa3_data.txt"

// COP 3502C Summer 2025
// Student Name: TODO_your_name_here
// File Name: pa3_yoursurname.c
// Note: Rename to use your actual surname. File name should be in lowercase.
// You must remove any whitespaces or dashes from your surname.
// Note: DO NOT modify or remove TODO comments as it will interfere 
// with the grading system.


// function prototypes defined here
// the function definitions are located below the main function
int count_at_level(BSTNode *root, int level);
int sum_at_level(BSTNode *root, int level);
void solve_mystery(BSTNode *root, int level, char *str, int *pos);
void display_info(BSTree *tree, int level);
char ascii_to_char(int ascii);


int main(void) {
    // read the input file
    FILE *ifile = fopen(INPUT_FILE_NAME, "r");
    
    // check if the file was opened
    if(ifile == NULL) {
        // if there was a problem, simply return a 1
        printf("There was a problem opening the file. Abort!\n");
        return 1;
    }
    
    // read level information
    int level;
    fscanf(ifile, "%d", &level);
    
    // read number of nodes from file
    int node_count;
    fscanf(ifile, "%d", &node_count);
    
    // create a tree
    BSTree *tree = bst_create();
    int value;
    
    // iterate and process one node at a time
    for(int i = 0; i < node_count; i++) {
        fscanf(ifile, "%d", &value);
        
        // insert the value to the tree
        bst_insert(tree, value);
    }
    
    // close the input file
    fclose(ifile);
    
    // display info
    display_info(tree, level);
    
    // destroy the tree
    bst_destroy(tree);

    return 0;
}


int count_at_level(BSTNode *root, int level) {
    // TODO 1 BEGIN
    // TODO: Complete the recursive function that takes a pointer to the root
    // of a binary search tree (root) and non-negative integer (level).
    // This function returns the number of nodes at the specified level.
    
    
    
    // TODO 1 END
}


int sum_at_level(BSTNode *root, int level) {
    // TODO 2 BEGIN
    // TODO: Complete the recursive function that takes a pointer to the root
    // of a binary search tree (root) and non-negative integer (level).
    // This function returns the sum of the values of all nodes at
    // the specified level.



    // TODO 2 END
}


void solve_mystery(BSTNode *root, int level, char *str, int *pos) {
    // TODO 3 BEGIN
    // TODO: Implement a recursive function that visits nodes at the given level,
    // converts their integer values (ASCII codes) to characters,
    // and appends these characters to the string `str` starting at index `pos`.
    // Make sure to update `pos` as characters are added.
    // The resulting string should have the characters arranged in ascending order.



    // TODO 3 END
}


void display_info(BSTree *tree, int level) {
    // helper function that prints all the
    // information derived from the function calls;
    // it also prints out the mystery word string
    
    // get the number of nodes at given level
    int nLevel = count_at_level(tree->root, level);
    
    // get the sum of nodes at given level
    int sLevel = sum_at_level(tree->root, level);
    
    // print all the computed info
    printf("Level: %d\n", level);
    printf("Node Count: %d\n", nLevel);
    printf("Node Sum: %d\n", sLevel);
    printf("Mystery Word: ");
    
    // check if there are nodes in the level
    if(nLevel > 0)
        // build a dynamic string that will hold
        // the mystery word
        char *str = malloc( sizeof(char) * (nLevel+1) );
        
        int pos = 0;
        solve_mystery(tree->root, level, str, &pos);
        str[pos] = '\n';
        printf("%s", str);
        
        // deallocate the string
        free(str);
    }
    else {
        // no nodes at this level
        printf("<None>");
    }
    
    // print a newline
    printf("\n");
}


char ascii_to_char(int ascii) {
    // helper function that converts an int
    // ascii into a char
    return (char)ascii;
}
