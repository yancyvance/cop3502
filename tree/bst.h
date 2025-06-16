#ifndef BST_H       // Check if BST_H is not defined
#define BST_H       // Define BST_H so it won't be included again
                    // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>

// Sample C Implementation of a Binary Search Tree.



// The BSTNode struct represents a Binary Search 
// Tree Node that holds a single integer.
typedef struct BSTNode_s {
    int data;
    struct BSTNode_s *left;
    struct BSTNode_s *right;
} BSTNode;

// The BSTree struct represents a Binary Search 
// Tree that keeps track of the root node.
typedef struct BSTree_s {
    BSTNode *root;
} BSTree;


// function prototypes defined here

// create and destroy nodes
BSTNode * bst_create_node(int);
void bst_destroy_node(BSTNode *);

// create and destroy binary search tree
BSTree * bst_create();
void bst_destroy(BSTree *);

// various operations, important
int bst_search(BSTree *, int);
int bst_is_empty(BSTree *);
void bst_insert(BSTree *, int);
BSTNode * bst_remove(BSTree *, int);

// various operations, practice
void bst_inorder(BSTNode *);
void bst_preorder(BSTNode *);
void bst_postorder(BSTNode *);



// function definitions



#endif              // End BST_H -- Do not add any code below
