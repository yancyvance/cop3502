#include <stdio.h>
#include <stdlib.h>
#define NUM_COUNT 6

// Sample C Implementation of solution to combination problem.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-18.


// function prototypes
int solve(int *, int, int, int *);
int check_solution(int *, int, int *);
void print_array(int *, int, int *);


int main(void) {
    // the actual array of numbers
    int actual_numbers[NUM_COUNT] = {3, 34, 4, 12, 5, 2};

    // a temporary array that will contain the solution
    // we need this because of the recursion approach
    // the solution here is a binary string 0 or 1
    // where it is a parallel array to nums to suggest
    // that it is a member of the subset or not
    int *binary_string = malloc(sizeof(int) * NUM_COUNT);

    // solve the problem recursively
    printf("%d", solve(binary_string, NUM_COUNT, 0, actual_numbers));

    // deallocate the array
    free(binary_string);

    return 0;
}


int solve(int *solution, int size, int pos, int *actual_nums) {
    // Base Case
    // if we are able to fill in all the elements
    // in the solution array
    if(pos == size) {
        // check if this solution is correct
        int result = check_solution(solution, size, actual_nums);
        // if it is, then just print it
        if(result)
            print_array(solution, size, actual_nums);
        return result;
    }

    // Recursive Case
    // there are 2 possible choices 0 or 1, so
    // try each of them by filling the current
    // position pos then recursively call the
    // function to fill in the remaining elements

    // keep track how many correct results
    // we have seen so far
    int partial_result = 0;

    // given two options 0 or 1, try to fill
    // in this current position of the solution
    // array, then recurse; afterward,
    // continue building the solution
    // while keeping track how many correct
    // solutions we will see if we go with
    // this digit for this position

    // What if bit at pos is 0?
    solution[pos] = 0;
    partial_result = partial_result + solve(solution, size, pos+1, actual_nums);

    // What if bit at pos is 1?
    solution[pos] = 1;
    partial_result = partial_result + solve(solution, size, pos+1, actual_nums);

    // return the partial results
    return partial_result;
}


int check_solution(int *solution, int size, int *actual_nums) {
    // helper function that checks if the proposed
    // solution is correct or not; it returns
    // 1 if it is, otherwise 0

    // correct if sum of the numbers is greater
    // than 55; note the parallel arrays
    int count = 0;
    for(int i = 0; i < size; i++)
        if(solution[i])
            count = count + actual_nums[i];
    return count > 55;
}


void print_array(int *solution, int size, int *actual_nums) {
    // helper function that simply prints
    // the contents of a parallel array based
    // on the value of another array
    for(int i = 0; i < size; i++)
        if(solution[i])
            printf("%3d ", actual_nums[i]);
        else
            printf("    ");
    printf("\n");
}
