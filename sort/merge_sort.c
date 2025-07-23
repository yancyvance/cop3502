#include <stdio.h>
#include <stdlib.h>
#define ELEMENT_COUNT 7

// Sample C Implementation of merge sort.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-12.


// function prototypes
void mergesort(int *arr, int, int);
void merge(int *, int, int, int, int);
void overwrite_array_segment(int *, int *, int, int);
void print_array_segment(int *, int, int);
void print_array(int *, int);


int main(void) {
    int nums[ELEMENT_COUNT] = {38, 27, 43, 3, 9, 82, 10};

    // print the array before sorting
    print_array(nums, ELEMENT_COUNT);

    // merge sort
    mergesort(nums, 0, ELEMENT_COUNT-1);

    // print the array after sorting
    print_array(nums, ELEMENT_COUNT);

    return 0;
}


void mergesort(int *arr, int start, int end) {
    if(start == end) {
        // the problem is small enough
        // because there is only one element
        // left, so stop and start solving
        // the problem
        return;
    }

    // Part 1: Divide
    // get the middle, inclusive
    // the minus 1 was to ensure
    // that the left side will be shorter
    int mid = (start+end-1) / 2;


    // Part 2: Conquer
    // recursively sort the left
    // and right sub-arrays;

    // we mergesort the left side sub-array
    mergesort(arr, start, mid);
    // we mergesort the right side sub-array
    mergesort(arr, mid+1, end);


    // Part 3: Combine
    // merge the two logical sub-arrays by
    // providing the start-end indices of the
    // left and the right sub-arrays
    merge(arr, start, mid, mid+1, end);
}


void merge(int *arr, int left_start, int left_end, int right_start, int right_end) {
    // this function receives an array which is logically
    // partitioned into two sub-arrays using the 2 pairs
    // of start-end indices; those two pairs of indices
    // will be the focus on this operation in which it
    // is assumed that elements in these sub-arrays
    // are already sorted; therefore this function
    // performs a linear sweep on the two sub-arrays
    // to combine them into a single one

    // we infer the size of the combine two sub-arrays
    // based on the left-start and right-end indices
    int size = right_end-left_start+1;

    // we temporarily allocate an array to hold
    // these combined sub-arrays
    int *tmp = malloc(sizeof(int) * size);

    // these are the trackers for the two sub-arrays
    int i = left_start;
    int j = right_start;

    // fill in the elements of the final array
    for(int pos = 0; pos < size; pos++) {
        // we are trying to fill in position
        // pos in the combined array

        if(i > left_end) {
            // no more elements on the left
            // array, so get the elements
            // from the remaining right array
            tmp[pos] = arr[j++];
        }
        else if(j > right_end) {
            // no more elements on the right
            // array, so get the elements
            // from the remaining left array
            tmp[pos] = arr[i++];
        }
        else {
            // we still have elements for both arrays
            // compare the current values from
            // the two arrays
            if(arr[i] < arr[j]) {
                // copy the value from the left array
                // then increment left tracker
                tmp[pos] = arr[i++];
            }
            else {
                // copy the value from the right array
                // then increment right tracker
                tmp[pos] = arr[j++];
            }
        }
    }

    // transfer all the values from the temporary array
    // to the original array (on the given segment only)
    overwrite_array_segment(arr, tmp, left_start, right_end);


    // deallocate the temporary array
    free(tmp);
}


void overwrite_array_segment(int *dest, int *src, int start_idx, int end_idx) {
    // this is a helper function that overwrites the
    // destination array with values from the source
    // array; it only does this for the elements beginning
    // at the start_idx up until end_idx (inclusive);
    // it is assumed that the size of the source array
    // corresponds to the end-start+1
    // overwrite
    for(int i = start_idx, pos = 0; i <= end_idx; i++, pos++) {
        dest[i] = src[pos];
    }
}


void print_array_segment(int *arr, int start, int end) {
    // this is a helper function that takes an array
    // and prints out the contents from a starting
    // index up until the end index (inclusive)
    for(int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
