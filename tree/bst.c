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

// Housekeeping for Binary Search Tree
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
    bst_destroy_node(node);
}

int bst_is_empty(BSTree *tree) {
    return tree->root == NULL;
}

int bst_search(BSTree *tree, int query) {
    // Uncomment the following and remove the other codes
    // and this function will simply act as a wrapper function
    // and will call the corresponding recursive function.
    //return bst_search_recursive( tree->root, query );
    
    BSTNode *ptr = tree->root;
    
    while( ptr != NULL ) {
        if( ptr->data == query )
            return 1;
            
        if( query <= ptr->data )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    return 0;
}

void bst_insert(BSTree *tree, int value) {
    // Uncomment the following and remove the other codes
    // and this function will simply act as a wrapper function
    // and will call the corresponding recursive function.
    //tree->root = bst_insert_recursive( tree->root, value );
    
    BSTNode *ptr = tree->root;
    BSTNode *trail = NULL;
    
    while( ptr != NULL ) {
        trail = ptr;
            
        if( value <= ptr->data )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    BSTNode *n = bst_create_node(value);
    
    // Non-root modification
    if( trail ) {
        // Determine whether left or right
        if( value <= trail->data )
            trail->left = n;
        else
            trail->right = n;
    }
    else {
        tree->root = n;
    }
}

void bst_remove(BSTree *tree, int query) {
    // Uncomment the following and remove the other codes
    // and this function will simply act as a wrapper function
    // and will call the corresponding recursive function.
    //tree->root = bst_remove_recursive( tree->root, query );
    
    BSTNode *ptr = tree->root;
    BSTNode *trail = NULL;
    
    while( ptr != NULL && ptr->data != query ) {
        trail = ptr;
            
        if( query <= ptr->data )
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    if( !ptr )
        return;
        
    // Determine the scenario. The general idea is to
    // begin with Scenario 3 because after copying the
    // successor, we will end up with a Scenario 1 or 2.
    
    // Scenario 3: Both Children
    if( ptr->left && ptr->right ) {
        BSTNode *s = ptr->right;
        BSTNode *s_parent = ptr;
        
        // Find the successor
        while( s->left != NULL ) {
            s_parent = s;
            s = s->left;
        }
        
        // Copy the data value
        ptr->data = s->data;
        
        // Do the actual deletion on this node.
        // So, we replace the nodes being referred to.
        trail = s_parent;
        ptr = s;
    }
    
    
    // Scenario 1: No Children
    if( ptr->left == NULL && ptr->right == NULL ) {
        if( trail == NULL ) {
            tree->root = NULL;
        }
        else if( ptr == trail->left ) {
            trail->left = NULL;
        }
        else {
            trail->right = NULL;
        }
        
        bst_destroy_node( ptr );
    }
    else if( ptr->left == NULL || ptr->right == NULL ) {
        // Scenario 2: One Child
        BSTNode *c = ptr->left ? ptr->left : ptr->right;
        
        if( trail == NULL ) {
            tree->root = c;
        }
        else if( ptr == trail->left ) {
            trail->left = c;
        }
        else {
            trail->right = c;
        }
        
        bst_destroy_node( ptr );
    }
}

BSTNode *bst_find_successor(BSTNode *node) {
    // Go to the right once
    BSTNode *ptr = node->right;
    
    // Find all the way to the left
    while( ptr->left != NULL )
        ptr = ptr->left;
        
    return ptr;
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
    if( node == NULL ) {
        return;
    }
    
    // LVR
    bst_inorder_recursive( node->left );
    printf("%d ", node->data);
    bst_inorder_recursive( node->right );
}

void bst_preorder_recursive(BSTNode *node) {
    if( node == NULL ) {
        return;
    }
    
    // VLR
    printf("%d ", node->data);
    bst_preorder_recursive( node->left );
    bst_preorder_recursive( node->right );
}

void bst_postorder_recursive(BSTNode *node) {
    if( node == NULL ) {
        return;
    }
    
    // LRV
    bst_postorder_recursive( node->left );
    bst_postorder_recursive( node->right );
    printf("%d ", node->data);
}

int bst_search_recursive(BSTNode *node, int query) {
    // If there is no node, then report failure of search
    if( node == NULL )
        return 0;
        
    // Check if the current node matches the query value
    if( node->data == query )
        return 1;
        
    // Otherwise, search either the left or right subtree
    // based on the value we are searching for
    if( query <= node->data )
        return bst_search_recursive( node->left, query );
        
    return bst_search_recursive( node->right, query );
}

BSTNode *bst_insert_recursive(BSTNode *node, int value) {
    // General Idea: Initially accept the root of the tree
    // where we want to insert the new node. Because it is
    // possible for the root to be modified, this function
    // returns a pointer to the root of the updated tree.
    // This is a recursive solution.
    
    // If node is non-existent, it means we are dealing
    // with an empty tree
    if( node == NULL ) {
        BSTNode *n = bst_create_node( value );
        return n;
    }
    
    // Otherwise, we want to look for an empty slot
    if( value <= node->data ) {
        node->left = bst_insert_recursive( node->left, value );
    }
    else {
        node->right = bst_insert_recursive( node->right, value );
    }
    
    return node;
}

BSTNode *bst_remove_recursive(BSTNode *node, int query) {
    // General Idea: Initially accept the root of the tree
    // where we want to perform the delete. Because it is
    // possible for the root to be modified, this function
    // returns a pointer to the root of the updated tree.
    // This is a recursive solution.
    
    // If node is non-existent, it means the tree is empty
    if( node == NULL ) {
        return NULL;
    }
    
    if( query < node->data ) {
        node->left = bst_remove_recursive( node->left, query );
    }
    else if( query > node->data ) {
        node->right = bst_remove_recursive( node->right, query );
    }
    else {
        // Check which scenario we are dealing with

        if( node->left == NULL && node->right == NULL ) {
            // Scenario 1: No Children
            bst_destroy_node(node);
            return NULL;
        }
        else if( node->left == NULL || node->right == NULL ) {
            // Scenario 2: One Child
            // Determine which child
            BSTNode *tmp = node->left ? node->left : node->right;
            bst_destroy_node(node);
            return tmp;
        }
        else {
            // Scenario 3: Both Children
            // Find the Successor
            BSTNode *s = bst_find_successor( node );
            
            // Copy the value
            node->data = s->data;
            
            // Remove that node on the right
            node->right = bst_remove_recursive( node->right, s->data );
        }
    }
    
    return node;
}
