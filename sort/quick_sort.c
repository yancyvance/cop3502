#include <stdio.h>
#define ELEMENT_COUNT 7

// Sample C Implementation of quick sort.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-16.


// function prototypes
void quicksort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int *);
void print_array(int *, int);


int main(void) {
    int nums[ELEMENT_COUNT] = {8, 3, 1, 7, 0, 10, 2};

    // print the array before sorting
    print_array(nums, ELEMENT_COUNT);

    // quick sort
    quicksort(nums, 0, ELEMENT_COUNT-1);

    // print the array after sorting
    print_array(nums, ELEMENT_COUNT);

    return 0;
}


void quicksort(int *arr, int start, int end) {
    // base case is if there is already
    // one element left
    if(start >= end) {
        // we don't do anything anymore
        return;
    }

    // Part 1: Divide
    // logically partition the array
    // around a pivot,

    // re-arrange the elements around
    // a pivot and determine the location
    // of the pivot (divider)
    int div_idx = partition(arr, start, end);


    // Part 2: Conquer
    // recursively sort the left
    // and right partitions; notice
    // that the partition is not part
    // of the two sub-arrays

    // we quicksort the left side sub-array
    quicksort(arr, start, div_idx-1);
    // we quicksort the right side sub-array
    quicksort(arr, div_idx+1, end);


    // Part 3: Combine
    // this is implied as a consequence
    // of the process performed above
}


int partition(int *arr, int start, int end) {
    // this function receives an array which
    // logically partitions; it does this
    // by re-arranging the elements based
    // on a pivot; afterward, it returns
    // the index in which the pivot was
    // placed in the end

    // find the index of the pivot; for our
    // approach, we assume it is the last element
    int pivot_idx = end;

    // traverse through the array from
    // start to end-1 index to split
    // into two sub-arrays: left and right
    // we use a logical divider, div_idx
    // to separate our current array
    // anything left to div_idx is less
    // than the pivot, otherwise it is
    // located to the right, including
    // the pivot later on; ultimately
    // div_idx is the final location
    // of the pivot will be later on
    int div_idx = start;

    // traverse from start to end-1
    for(int i = start; i < end; i++) {
        // is the current element less
        // than or equal to the pivot?
        if(arr[i] <= arr[pivot_idx]) {
            // swap the current element
            // with the leftmost element
            // in the right sub-array
            swap(&arr[i], &arr[div_idx]);

            // move the divider to the
            // right by one
            div_idx++;
        }
    }

    // final swap between the pivot, which
    // is the last element and the element,
    // currently at the divider, which is
    // at div_idx
    swap(&arr[pivot_idx], &arr[div_idx]);

    // return the index where the pivot
    // is now located (the divider), which
    // is currently at div_idx
    return div_idx;
}


void swap(int *a, int *b) {
    // this is a helper function
    // that just swaps the values of
    // two variables
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void print_array(int *arr, int size) {
    // this is a helper function
    // that simply prints the content
    // of the array
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
