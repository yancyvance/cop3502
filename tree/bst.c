#include <stdio.h>
#include "bst.h"

// Sample Test Program for Binary Search Tree.

int main(void) {
    // create a tree
    BSTree *tree = bst_create();
    
    // perform some operations here
    // insert some values
    bst_insert(tree, 50);
    bst_insert(tree, 25);
    bst_insert(tree, 75);
    bst_insert(tree, 10);
    bst_insert(tree, 40);
    bst_insert(tree, 60);
    bst_insert(tree, 100);
    
    // search
    printf("Is 60 in the BST? %d\n", bst_search(tree, 60));
    printf("Is 200 in the BST? %d\n", bst_search(tree, 200));
    
    // traversals
    bst_inorder(tree);
    bst_preorder(tree);
    bst_postorder(tree);
    
    
    
    // destroy the tree
    bst_destroy(tree);
    
    return 0;
}
