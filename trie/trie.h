#ifndef TRIE_H       // Check if TRIE_H is not defined
#define TRIE_H       // Define TRIE_H so it won't be included again
                     // Put all your codes below this line


#include <stdio.h>
#include <stdlib.h>
#define LETTER_COUNT 26

// Sample C Implementation of a Trie.



// The TrieNode struct represents a Trie 
// Node that only has pointers to all
// the possible 26 child nodes.
typedef struct TrieNode_s {
    struct TrieNode_s *children[LETTER_COUNT];
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

// various operations, important
void trie_insert(Trie *trie, char *word);
int trie_search(Trie *trie, char *word);
void trie_remove(Trie *trie, char *word);
int trie_remove_recursive(TrieNode *node, char *word, int len, int pos);

// helper functions
int trie_has_children(TrieNode *node);
int trie_char_to_index(char alpha);
char trie_index_to_char(int idx);





// function definitions



#endif               // End TRIE_H -- Do not add any code below
