#include <stdio.h>
#define ELEMENT_COUNT 5

// Sample C Implementation of elementary sorting algorithms.
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-09.


// function prototypes
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void swap(int *, int *);
void print_array(int *, int);


int main(void) {
    int nums[ELEMENT_COUNT] = {5, 3, 8, 4, 2};

    // print the array before sorting
    print_array(nums, ELEMENT_COUNT);

    // selection sort
    //selection_sort(nums, ELEMENT_COUNT);

    // insertion sort
    //insertion_sort(nums, ELEMENT_COUNT);

    // bubble sort
    bubble_sort(nums, ELEMENT_COUNT);

    // print the array after sorting
    print_array(nums, ELEMENT_COUNT);

    return 0;
}


void selection_sort(int *arr, int size) {
    // fill in the element from left to right
    // you don't have to go all the way to the
    // last element because after filling
    // up the second to the last slot, it
    // is assumed that the last slot is already
    // in its correct location
    // anything to the left of this index i
    // is considered as already sorted
    // anything to the right (including i)
    // is part of the unsorted group
    for(int i = 0; i < size-1; i++) {
        // assume that the i-th element
        // is the minimum
        int min_idx = i;

        // we now try to find the minimum
        // element to the right side of i-th;
        // we check everything including the
        // last element
        for(int j = i+1; j < size; j++) {
            // check if this j-th element
            // happens to be smaller than
            // the current min we are looking for
            if(arr[j] < arr[min_idx]) {
                // update the idx to the index
                // of the new minimum element
                min_idx = j;
            }
        }

        // if a new min element was found
        // we swap the values
        if(min_idx != i) {
            // swap the values
            swap(&arr[i], &arr[min_idx]);
        }

        // inspect the array
        printf("\t");
        print_array(arr, size);
    }
}


void insertion_sort(int *arr, int size) {
    // we begin at the second element
    // because we assume that the first
    // element is already sorted
    // the idea is that the left part is
    // the sorted area while the right part
    // is the unsorted area; for each
    // element of the unsorted area
    // (the first one), we insert it to
    // its correct location in the sorted
    // area; we do this but shifting
    // or moving elements to the right
    // by one slot and we repeat
    // this until the current element is
    // in its correct location;
    // the left of i-th is sorted
    for(int i = 1, j; i < size; i++) {
        // we have to remember this element
        // the one we want to insert
        int tmp = arr[i];

        // start finding the correct location
        // of this unsorted element; consequently
        // shift one at a time; we do this
        // until the beginning of the array
        for(j = i-1; j >= 0 && tmp < arr[j]; j--) {
            // if the value we want to insert
            // is smaller than this current
            // element, shift to the right the
            // current element
            arr[j+1] = arr[j];
        }

        // we now found the correct location
        arr[j+1] = tmp;

        // inspect the array
        printf("\t");
        print_array(arr, size);
    }
}


void bubble_sort(int *arr, int size) {
    // the idea is that we want to "bubble down"
    // or push down heavier items to the right side
    // and we keep on doing this for size-1 times
    // because for each round, the heaviest value
    // of the unsorted part will end up to its
    // correct location, thereby becoming sorted;
    // the sorted part will be located on the
    // right side while the unsorted part will
    // be on the left side; thus the size of the
    // unsorted part gets smaller because for
    // each iteration of the loop, we end
    // up sorting one new element
    for(int i = 0; i < size-1; i++) {
        // for this round, bubble down the
        // current heaviest element in the sorted
        // part so that it ends up being in
        // the unsorted part (the first of the
        // the sorted part); thus you only need
        // to run this all the way until
        // you reach the sorted part
        for(int j = 0; j < size-1-i; j++) {
            // check if the current element
            // is not on its current location
            // relative to its right element
            // in short, the current element
            // is heavier than its right element
            if(arr[j] > arr[j+1]) {
                // swap the two elements
                swap(&arr[j], &arr[j+1]);
            }
        }

        // inspect the array
        printf("\t");
        print_array(arr, size);
    }
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
