#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode_s {
    int data;
    struct BSTNode_s *left;
    struct BSTNode_s *right;
} BSTNode;

typedef struct BSTree_s {
    BSTNode *root;
} BSTree;


// Function Prototypes

// Housekeeping for Nodes
BSTNode *bst_create_node(int val);
void bst_destroy_node(BSTNode *node);

// Housekeeping for Linked List
BSTree *bst_create();
void bst_destroy(BSTree *tree);
void bst_destroy_recursive(BSTNode *node);

// Essential Operations
int bst_is_empty(BSTree *tree);
int bst_search(BSTree *tree, int query);
void bst_insert(BSTree *tree, int value);
void bst_remove(BSTree *tree, int query);

// Helper Functions
BSTNode *bst_find_successor(BSTNode *node);
void bst_remove_helper(BSTree *tree, BSTNode *n, BSTNode *p);

// Wrapper Functions
void bst_inorder(BSTree *tree);
void bst_preorder(BSTree *tree);
void bst_postorder(BSTree *tree);

// Recursive Functions
void bst_inorder_recursive(BSTNode *node);
void bst_preorder_recursive(BSTNode *node);
void bst_postorder_recursive(BSTNode *node);
int bst_search_recursive(BSTNode *node, int query);
BSTNode *bst_insert_recursive(BSTNode *node, int value);
BSTNode *bst_remove_recursive(BSTNode *node, int query);


int main(void) {
    // create a tree
    BSTree *tree = bst_create();
    
    // perform some operations here
    // insert some values
    bst_insert(tree, 50);
    bst_insert(tree, 30);
    bst_insert(tree, 100);
    bst_insert(tree, 90);
    bst_insert(tree, 80);
    bst_insert(tree, 70);
    bst_insert(tree, 60);
    
    // search
    printf("Is 60 in the BST? %d\n", bst_search(tree, 60));
    printf("Is 200 in the BST? %d\n", bst_search(tree, 200));
    
    // traversals
    bst_inorder(tree);
    bst_preorder(tree);
    bst_postorder(tree);
    
    // insert again
    bst_insert(tree, 55);
    
    // print contents
    bst_inorder(tree);

    // destroy the tree
    bst_destroy(tree);
    
    return 0;
}


// Function Definitions
BSTNode *bst_create_node(int value) {
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

BSTree *bst_create() {
    BSTree *tree = malloc( sizeof(BSTree) );
    
    if(tree == NULL) return NULL;
    
    tree->root = NULL;
    
    return tree;
}

void bst_destroy(BSTree *tree) {
    bst_destroy_recursive( tree->root );
    
    // destroy the tree
    free(tree);
}

void bst_destroy_recursive(BSTNode *node) {
    if(node == NULL)
        return;
        
    // postorder traversal: LRV
    bst_destroy_recursive(node->left);
    bst_destroy_recursive(node->right);
    free(node);
}

int bst_is_empty(BSTree *tree) {
    
}

int bst_search(BSTree *tree, int query) {
    
}

void bst_insert(BSTree *tree, int value) {
    
}

void bst_remove(BSTree *tree, int query) {
    
}

BSTNode *bst_find_successor(BSTNode *node) {
    
}

void bst_remove_helper(BSTree *tree, BSTNode *n, BSTNode *p) {
    
}

void bst_inorder(BSTree *tree) {
    bst_inorder_recursive( tree->root );
    printf("\n");
}

void bst_preorder(BSTree *tree) {
    bst_preorder_recursive( tree->root );
    printf("\n");
}

void bst_postorder(BSTree *tree) {
    bst_postorder_recursive( tree->root );
    printf("\n");
}

void bst_inorder_recursive(BSTNode *node) {

}

void bst_preorder_recursive(BSTNode *node) {
    
}

void bst_postorder_recursive(BSTNode *node) {
    
}

int bst_search_recursive(BSTNode *node, int query) {
    
}

BSTNode *bst_insert_recursive(BSTNode *node, int value) {
    
}

BSTNode *bst_remove_recursive(BSTNode *node, int query) {
    
}
