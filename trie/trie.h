#ifndef TRIE_H       // Check if TRIE_H is not defined
#define TRIE_H       // Define TRIE_H so it won't be included again
                     // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHILD_COUNT 26

// Sample C Implementation of a Trie.



// The TrieNode struct represents a Trie 
// Node that only has pointers to all
// the possible 26 child nodes.
typedef struct TrieNode_s {
    struct TrieNode_s *children[MAX_CHILD_COUNT];
    int is_end_of_word;
} TrieNode;

// The Trie struct represents a Trie 
// that keeps track of the root node.
typedef struct Trie_s {
    TrieNode *root;
} Trie;


// function prototypes defined here

// create and destroy nodes
TrieNode * trie_create_node();
void trie_destroy_node(TrieNode *node);

// create and destroy trie
Trie * trie_create();
void trie_destroy(Trie *trie);
void trie_destroy_recursive(TrieNode *node);

// various operations, important
void trie_insert(Trie *trie, char *word);
int trie_search(Trie *trie, char *word);
void trie_remove(Trie *trie, char *word);
int trie_remove_recursive(TrieNode *node, char *word, int len, int pos);

// helper functions
int trie_has_children(TrieNode *node);
int trie_is_marked(TrieNode *node);
int trie_char_to_index(char alpha);
char trie_index_to_char(int idx);

// application
int trie_count(Trie *trie);
int trie_count_recursive(TrieNode *node);



// function definitions

// create and destroy nodes
TrieNode * trie_create_node() {
    TrieNode *node = malloc( sizeof(TrieNode) );
    
    if(node == NULL) return NULL;
    
    // initialize the fields
    node->is_end_of_word = 0;
    
    // loop through all the child pointers
    // and set them all to NULL
    for(int i = 0; i < MAX_CHILD_COUNT; i++)
        node->children[i] = NULL;
        
    return node;
}

void trie_destroy_node(TrieNode *node) {
    // deallocate the node itself
    free(node);
}

// create and destroy trie
Trie * trie_create() {
    Trie *trie = malloc( sizeof(Trie) );
    
    if(trie == NULL) return NULL;
    
    // create the root
    trie->root = trie_create_node();
    
    return trie;
}

void trie_destroy(Trie *trie) {
    // partially implemented
    trie_destroy_recursive(trie->root);
    
    free(trie);
}

void trie_destroy_recursive(TrieNode *node) {
    // base case
    if(node == NULL)
        return;
        
    // do a postorder traversal, LRV
    for(int i = 0; i < MAX_CHILD_COUNT; i++) {
        trie_destroy_recursive(node->children[i]);
    }
    
    // deallocate this node
    trie_destroy_node(node);
}

void trie_insert(Trie *trie, char *word) {
    // get the length of the string
    int len = strlen(word);
    TrieNode *ptr = trie->root;
    
    for(int i = 0; i < len; i++) {
        char alpha = word[i];
        int idx = trie_char_to_index(alpha);
        
        // check if there is an existing path
        if(!(ptr->children[idx])) {
            // if there is none, create one
            ptr->children[idx] = trie_create_node();
        }

        // then go to that path
        ptr = ptr->children[idx];
    }
    
    // finally, mark the last node
    ptr->is_end_of_word = 1;
}

int trie_search(Trie *trie, char *word) {
    // get the length of the string
    int len = strlen(word);
    TrieNode *ptr = trie->root;
    
    for(int i = 0; i < len; i++) {
        char alpha = word[i];
        int idx = trie_char_to_index(alpha);
        
        // check if there is an existing path
        if(!(ptr->children[idx])) {
            // if there is none, terminate
            return 0;
        }

        // go to that path
        ptr = ptr->children[idx];
    }
    
    // finally, check if the last node
    // is a marker
    return ptr->is_end_of_word == 1;
}

void trie_remove(Trie *trie, char *word) {
    int len = strlen(word);
    
    // wrapper to remove a word
    trie_remove_recursive(trie->root, word, len, 0);
}

int trie_remove_recursive(TrieNode *node, char *word, int len, int pos) {
    // base case
    if(len == pos) {
        // check if this is a marker
        if(node->is_end_of_word) {
            // unmark the node
            node->is_end_of_word = 0;
            return 1;
        }
        else
            return 0;
    }
    
    // get the character and the corresponding
    // index for the child node of that letter
    char alpha = word[pos];
    int idx = trie_char_to_index(alpha);
    
    if(!(node->children[idx]))
        return 0;
    
    // go to the next position
    int has_removed = trie_remove_recursive(node->children[idx], word, len, pos+1);
    
    // if didn't remove, report it
    if( !has_removed ) return 0;
    
    // check if this is a node we can delete
    // we cannot delete if this node has other child
    // or it is a marked node
    if( trie_has_children(node->children[idx]) ||  trie_is_marked(node->children[idx]) )
        return 0;
    else {
        // deallocate that node
        trie_destroy_node( node->children[idx] );
        
        // set the field to NULL
        node->children[idx] = NULL;
        
        return 1;
    }
}

int trie_has_children(TrieNode *node) {
    for(int i = 0; i < MAX_CHILD_COUNT; i++)
        if(node->children[i])
            return 1;
    return 0;
}

int trie_is_marked(TrieNode *node) {
    return node->is_end_of_word;
}

int trie_char_to_index(char alpha) {
    return (int)(alpha-'a');
}

int trie_count(Trie *trie) {
    // call the recursive function and
    // pass the root of the trie
    return trie_count_recursive(trie->root);
}

int trie_count_recursive(TrieNode *node) {
    if(node == NULL)
        return 0;
        
    // keep track how many marked nodes
    // are found
    int count = node->is_end_of_word;
    
    for(int i = 0; i < MAX_CHILD_COUNT; i++)
        count = count + trie_count_recursive( node->children[i] );
        
    return count;
}


#endif               // End TRIE_H -- Do not add any code below
