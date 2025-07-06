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
BSTNode * bst_create_node(int value) {
    BSTNode *node = malloc( sizeof(BSTNode) );
    
    if(node == NULL) return NULL;
    
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void bst_destroy_node(BSTNode *node) {
    free(node);
}

void bst_destroy_recursive(BSTNode *node) {
    if(node == NULL)
        return;
        
    // postorder traversal: LRV
    bst_destroy_recursive(node->left);
    bst_destroy_recursive(node->right);
    free(node);
}

BSTree * bst_create() {
    BSTree *tree = malloc( sizeof(BSTree) );
    
    if(tree == NULL) return NULL;
    
    tree->root = NULL;
    
    return tree;
}

void bst_destroy(BSTree *tree) {
    // destroy all the nodes first
    // this can be accomplished via
    // post order traversal
    bst_destroy_recursive(tree->root);
    
    // destroy the tree
    free(tree);
}

int bst_is_empty(BSTree *tree) {
    return tree->root == NULL;
}

int bst_search(BSTree *tree, int query) {
    BSTNode *ptr = tree->root;
    
    while(ptr != NULL) {
        // is this what we are looking for?
        if( ptr->data == query )
            return 1;
            
        // where to go?
        if( query < ptr->data ) {
            // go to the left
            ptr = ptr->left;
        }
        else {
            // go to the right
            ptr = ptr->right;
        }
    }
    
    return 0;
}

void bst_insert(BSTree *tree, int value) {
    // check if the tree is empty first
    if( bst_is_empty(tree) ) {
        tree->root = bst_create_node(value);
        return;
    }
    
    // otherwise, just find the correct location
    BSTNode *ptr = tree->root;
    // to track the parent
    // initialized to the root to prevent
    // segmentation fault when inserting
    // a node to a BST where currently there is
    // only one node
    BSTNode *trail = ptr;
    
    while(ptr != NULL) {
        // remember the node first
        trail = ptr;
          
        // where to go?
        if( value < ptr->data ) {
            // go to the left
            ptr = ptr->left;
        }
        else {
            // go to the right
            ptr = ptr->right;
        }
    }
    
    // at this point, the location is
    // already found, so create the appropriate
    // child (L or R) based on value of trail
    if( value < trail->data )
        trail->left = bst_create_node(value);
    else
        trail->right = bst_create_node(value);
}

void bst_inorder(BSTree *tree) {
    // call the recursive starting at the root
    printf("Inorder: ");
    bst_inorder_recursive(tree->root);
    printf("\n");
}

void bst_preorder(BSTree *tree) {
    // call the recursive starting at the root
    printf("Preorder: ");
    bst_preorder_recursive(tree->root);
    printf("\n");
}

void bst_postorder(BSTree *tree) {
    // call the recursive starting at the root
    printf("Postorder: ");
    bst_postorder_recursive(tree->root);
    printf("\n");
}

void bst_inorder_recursive(BSTNode *node) {
    if(node == NULL)
        return;
        
    // LVR
    bst_inorder_recursive(node->left);
    printf("%d, ", node->data);
    bst_inorder_recursive(node->right);
}

void bst_preorder_recursive(BSTNode *node) {
    if(node == NULL)
        return;
    
    // VLR
    printf("%d, ", node->data);
    bst_preorder_recursive(node->left);
    bst_preorder_recursive(node->right);
}

void bst_postorder_recursive(BSTNode *node) {
    if(node == NULL)
        return;
        
    // LRV
    bst_postorder_recursive(node->left);
    bst_postorder_recursive(node->right);
    printf("%d, ", node->data);
}


#endif              // End BST_H -- Do not add any code below
