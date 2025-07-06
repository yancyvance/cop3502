#include <stdio.h>
#include "bst.h"

// Sample Test Program for Binary Search Tree.

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
