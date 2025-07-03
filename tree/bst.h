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
BSTNode * bst_create_node(int value);
void bst_destroy_node(BSTNode *node);

// create and destroy binary search tree
BSTree * bst_create();
void bst_destroy(BSTree *tree);

// various operations, important
int bst_is_empty(BSTree *tree);
int bst_search(BSTree *tree, int query);
void bst_insert(BSTree *tree, int value);
BSTNode * bst_remove(BSTree *tree, int query);

// various operations, practice
void bst_inorder(BSTree *tree);
void bst_preorder(BSTree *tree);
void bst_postorder(BSTree *tree);

// various operations, recursive
void bst_inorder_recursive(BSTNode *node);
void bst_preorder_recursive(BSTNode *node);
void bst_postorder_recursive(BSTNode *node);
int bst_search_recursive(BSTNode *node, int query);
void bst_insert_recursive(BSTNode **node, int value);
BSTNode * bst_remove_recursive(BSTNode **node, int query);



// function definitions



#endif              // End BST_H -- Do not add any code below
