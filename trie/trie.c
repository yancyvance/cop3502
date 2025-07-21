#include <stdio.h>
#include "trie.h"
#define WORD_COUNT 6

// Sample Test Program for Trie.

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
