#include <stdio.h>
#include "trie.h"

// Sample Test Program for Trie.

int main(void) {
    // create a trie
    Trie *trie = trie_create();


    // insert the following strings
    trie_insert(trie, "hello");
    trie_insert(trie, "hi");
    trie_insert(trie, "helios");
    trie_insert(trie, "hope");
    trie_insert(trie, "hopeful");
    trie_insert(trie, "hopefully");

    // do a lookup
    printf("%d\n", trie_search(trie, "hi"));
    printf("%d\n", trie_search(trie, "hello"));
    printf("%d\n", trie_search(trie, "hopeful"));

    // remove string
    trie_remove(trie, "hopefully");

    // do a lookup
    printf("%d\n", trie_search(trie, "hopeful"));
    printf("%d\n", trie_search(trie, "hopefully"));


    // deallocate trie
    trie_destroy(trie);

    return 0;
}
