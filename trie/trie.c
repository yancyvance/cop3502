#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHILD_COUNT 26
#define WORD_COUNT 6


typedef struct TrieNode_s {
    struct TrieNode_s *children[MAX_CHILD_COUNT];
    int is_end_of_word;
} TrieNode;

typedef struct Trie_s {
    TrieNode *root;
} Trie;


// Function Prototypes
TrieNode *trie_create_node();
void trie_destroy_node(TrieNode *node);
Trie *trie_create();
void trie_destroy(Trie *trie);
void trie_destroy_recursive(TrieNode *node);

void trie_insert(Trie *trie, char *word);
int trie_search(Trie *trie, char *word);
void trie_remove(Trie *trie, char *word);
TrieNode *trie_remove_recursive(TrieNode *node, char *word, int pos);
int trie_count(Trie *trie);
int has_children(TrieNode *node);


int main(void) {
    // create a trie
    Trie *trie = trie_create();
    
    // array of strings
    char words[WORD_COUNT][255] = {
        "hello", "hi", "helios", "hope", "hopeful", "hopefully"
    };

    // insert the following strings
    for(int i = 0; i < WORD_COUNT; i++)
        trie_insert(trie, words[i]);
        
    // print word count
    printf("Word Count: %d\n", trie_count(trie));
    
    // do a lookup
    printf("%d\n", trie_search(trie, "hi"));
    printf("%d\n", trie_search(trie, "hello"));
    printf("%d\n", trie_search(trie, "hopeful"));
    printf("%d\n", trie_search(trie, "world"));
    printf("%d\n", trie_search(trie, "hop"));

    // remove string
    trie_remove(trie, "hopefully");
    
    // print word count
    printf("Word Count: %d\n", trie_count(trie));

    // do a lookup
    printf("%d\n", trie_search(trie, "hopeful"));
    printf("%d\n", trie_search(trie, "hopefully"));

    // remove all the words
    for(int i = 0; i < WORD_COUNT; i++)
        trie_remove(trie, words[i]);
    
    printf("%d\n", trie_search(trie, "hopeful"));
    
    // print word count
    printf("Word Count: %d\n", trie_count(trie));

    // deallocate trie
    trie_destroy(trie);

    return 0;
}


// create and destroy nodes
TrieNode *trie_create_node() {
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

Trie *trie_create() {
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
        
    // do a postorder traversal
    for(int i = 0; i < MAX_CHILD_COUNT; i++) {
        trie_destroy_recursive(node->children[i]);
    }
    
    // deallocate this node
    trie_destroy_node(node);
}

void trie_insert(Trie *trie, char *word) {
    TrieNode *ptr = trie->root;
    
    for(int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        
        if( ptr->children[idx] == NULL ) {
            ptr->children[idx] = trie_create_node();
        }
        
        ptr = ptr->children[idx];
    }
    
    ptr->is_end_of_word = 1;    
}

int trie_search(Trie *trie, char *word) {
    TrieNode *ptr = trie->root;
    
    for(int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        
        if( ptr->children[idx] == NULL )
            return 0;
        
        ptr = ptr->children[idx];
    }
    
    return ptr->is_end_of_word;
}

void trie_remove(Trie *trie, char *word) {
    // Wrapper function
    trie->root = trie_remove_recursive( trie->root, word, 0 );
}

TrieNode *trie_remove_recursive(TrieNode *node, char *word, int pos) {
    // Base Case: No Node
    if( node == NULL )
        return NULL;
    
    // Base Case: Found the Word
    if( pos == strlen(word) ) {
        // Is this word found in the dictionary?
        if( !node->is_end_of_word )
            return node;
    
        // Unmark it if it is a word
        node->is_end_of_word = 0;
        
        // If this node does not have any children
        // and it is not the root node, destroy it
        if( !has_children(node) && pos > 0 ) {
            trie_destroy_node(node);
            return NULL;
        }
        
        return node;
    }
    
    // Proceed to the next letter (i.e., node)
    int idx = word[pos] - 'a';
    node->children[idx] = trie_remove_recursive(node->children[idx], word, pos+1);
    
    // If this node does not have any children; AND
    // it is not an end of word marker node; AND
    // it is not the root node, destroy it
    if( !has_children(node) && !node->is_end_of_word && pos > 0 ) {
        trie_destroy_node(node);
        return NULL;
    }
    
    return node;
}

int trie_count(Trie *trie) {
    // TODO: Implement this
    
    return -1;
}

int has_children(TrieNode *node) {
    for(int i = 0; i < MAX_CHILD_COUNT; i++) {
        if( node->children[i] )
            return 1;
    }
    return 0;
}
