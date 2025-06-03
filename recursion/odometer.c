#include <stdio.h>
#include <stdlib.h>
#define NUM_COUNT 4

// Sample C Implementation of solution to odometer problem.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-18.


// function prototypes
int solve(int *res, int, int);
int check_solution(int *, int);
void print_array(int *, int);


int main(void) {
    // a temporary array that will contain the solution
    // we need this because of the recursion approach
    int *result = malloc(sizeof(int) * NUM_COUNT);

    // solve the problem recursively
    printf("%d", solve(result, NUM_COUNT, 0));

    // deallocate the array
    free(result);

    return 0;
}


int solve(int *solution, int size, int pos) {
    // Base Case
    // if we are able to fill in all the elements
    // in the solution array
    if(pos == size) {
        // check if this solution is correct
        int result = check_solution(solution, size);
        // if it is, then just print it
        if(result)
            print_array(solution, size);
        return result;
    }

    // Recursive Case
    // there are 10 digits 0-9, so try each of
    // them by filling the current position pos
    // then recursively call the function to
    // fill in the remaining elements

    // keep track how many correct results
    // we have seen so far
    int partial_result = 0;

    // for all the 10 digits, try to fill
    // in this current position of the solution
    // array, then recurse
    for(int d = 0; d <= 9; d++) {
        // we try this digit
        solution[pos] = d;

        // continue building the solution
        // while keeping track how many correct
        // solutions we will see if we go with
        // this digit for this position
        partial_result = partial_result + solve(solution, size, pos+1);
    }

    // return the partial results
    return partial_result;
}


int check_solution(int *solution, int size) {
    // helper function that checks if the proposed
    // solution is correct or not; it returns
    // 1 if it is, otherwise 0

    // correct if count of the 8 digit
    // is at least 3
    int count = 0;
    for(int i = 0; i < size; i++)
        if(solution[i] == 8)
            count++;
    return count >= 3;
}


void print_array(int *solution, int size) {
    // helper function that simply prints
    // the contents of an array
    for(int i = 0; i < size; i++)
        printf("%d ", solution[i]);
    printf("\n");
}
