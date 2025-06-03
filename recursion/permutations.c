#include <stdio.h>
#include <stdlib.h>
#define NAME_COUNT 3

// Sample C Implementation of solution to permutation problem.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-18.


// function prototypes
void solve(char *, int, int, char *, int *);
void print_array(char *, int);
void init_array(int *, int);


int main(void) {
    // the actual array of names
    char actual_names[NAME_COUNT] = {'a', 'b', 'c'};

    // two temporary parallel arrays that will contain
    // the solution as a well a way for us to keep track
    // which elements have been used already as we
    // build our solution (i.e., flags)
    char *solution = malloc(sizeof(char) * NAME_COUNT);
    int *is_used = calloc(NAME_COUNT, sizeof(int));

    // ensure that we initialize the
    // array to prevent garbage values
    // uncomment if using calloc()
    //init_array(is_used, NAME_COUNT);

    // solve the problem recursively
    solve(solution, NAME_COUNT, 0, actual_names, is_used);

    // deallocate the arrays
    free(solution);
    free(is_used);

    return 0;
}


void solve(char *solution, int size, int pos, char *actual_names, int *is_used) {
    // Base Case
    // if we are able to fill in all the elements
    // in the solution array
    if(size == pos) {
        // simply print this solution
        print_array(solution, size);
        return;
    }

    // Recursive Case
    // there are multiple elements to choose from
    // to put in the current position pos, so try
    // them all; however, once it has been already
    // used in an earlier position, it cannot
    // be used again; therefore, we keep track
    // of this information so that it doesn't
    // appear multiple times in the solution array
    for(int i = 0; i < size; i++) {
        // only if this element is not yet used
        if( !is_used[i] ) {
            // we try putting this element
            // in at position pos of our solution
            solution[pos] = actual_names[i];

            // then mark it as used
            is_used[i] = 1;

            // continue building the solution
            // by passing existing knowledge
            solve(solution, size, pos+1, actual_names, is_used);

            // after attempting this path,
            // we simply unmark it so that
            // it can be used again in
            // the future recursive call
            is_used[i] = 0;
        }
    }
}


void print_array(char *solution, int size) {
    // helper function that simply prints
    // the contents of an array
    for(int i = 0; i < size; i++)
        printf("%c ", solution[i]);
    printf("\n");
}


void init_array(int *arr, int size) {
    // helper function that sets all
    // the elements of an int array
    // to 0 to prevent garbage values
    for(int i = 0; i < size; i++)
        arr[i] = 0;
}
