#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LETTER_COUNT 26
#define INPUT_FILE_NAME "pa4_data.txt"

// COP 3502C Summer 2025
// Student Name: TODO_your_name_here
// File Name: pa4_yoursurname.c
// Note: Rename to use your actual surname. File name should be in lowercase.
// You must remove any whitespaces or dashes from your surname.
// Note: DO NOT modify or remove TODO comments as it will interfere 
// with the grading system.


typedef struct TrieNode_s {
    struct TrieNode_s *children[LETTER_COUNT];
    int is_terminal;
} TrieNode;



// DO NOT MODIFY THIS PORTION
// function prototypes defined here
int max_num_prefix_words(TrieNode *);
TrieNode * trie_create_node();
void trie_destroy_node(TrieNode *);
int get_char_index(char);
void insert(TrieNode *, char *);
void trim_string(char *);



// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
int main(void) {
    FILE *input_file = fopen(INPUT_FILE_NAME, "r");

    // check if the file was opened
    if(input_file == NULL) {
        // if there was a problem, simply return a 1
        printf("There was a problem opening the file. Abort!\n");
        return 1;
    }

    // dynamically allocate the root node
    // of a trie
    TrieNode *root = trie_create_node();

    char word[256];

    // read all the words from the file
    while( fgets(word, 256, input_file) ) {
        // trim the string
        trim_string(word);

        // insert the word to the trie
        insert(root, word);
    }

    // close the file
    fclose(input_file);

    // output the answer
    printf("%d", max_num_prefix_words(root));

    // deallocate trie
    trie_destroy_node(root);

    return 0;
}
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION



int max_num_prefix_words(TrieNode *node) {
    // TODO 1 BEGIN
    // TODO: Given the root of a trie that
    // stores a dictionary of words, return
    // the maximum number of words that are
    // prefixes of a single word.






    
    // TODO 1 END
}


TrieNode * trie_create_node() {
    // dynamically create a new node
    TrieNode *node = malloc(sizeof(TrieNode));

    // set all children pointers to NULL
    for(int i = 0; i < LETTER_COUNT; i++) {
        node->children[i] = NULL;
    }

    // set the flag to false
    // indicating that this is not
    // a terminal node for a certain string
    node->is_terminal = 0;

    return node;
}


void trie_destroy_node(TrieNode *node) {
    // this is a postorder traversal
    // visit all the children first
    // then visit the current node
    // base case
    if(node == NULL)
        return;

    // postorder visit all the children
    // and individually destroy them
    for(int i = 0; i < LETTER_COUNT; i++) {
        trie_destroy_node(node->children[i]);
    }

    // deallocate this current node
    free(node);
}


int get_char_index(char alpha) {
    // change to lowercase first
    alpha = tolower(alpha);

    return alpha-'a';
}


void insert(TrieNode *root, char *str) {
    // create a pointer to the root
    TrieNode *ptr = root;

    // traverse through each character
    // of the string
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        int idx = get_char_index(str[i]);

        // check if there is no existing
        // node for this letter
        if(ptr->children[idx] == NULL) {
            // create a new node for that
            // letter
            ptr->children[idx] = trie_create_node();
        }

        // traverse to the next node
        ptr = ptr->children[idx];
    }

    // once we reached the last letter
    // ptr is pointing at the last node
    // therefore, set the flag of this
    // node to 1 or true
    ptr->is_terminal = 1;
}


void trim_string(char *str) {
    // helper function that will remove the extra new line
    // begin at location right before
    // the null terminator of the string
    int len = strlen(str) - 1;

    // from the right, keep moving to the left;
    // continue doing so until what you see right
    // now is not a newline character anymore
    while(len > 0) {
        // stop moving to the left once you don't
        // see a newline character anymore
        if(str[len] != '\n' && str[len] != '\r')
            break;

        len--;
    }

    // len is currently pointing at the
    // last character right before a newline
    // therefore, it should be immediately
    // followed by the null character
    str[len+1] = '\0';
}
