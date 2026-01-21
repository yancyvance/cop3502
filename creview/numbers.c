#include <stdio.h>
#define MAX_NUMS 5

// Write a program that stores whole numbers.

int main(void) {
    // Declare an array
    int arr[MAX_NUMS];
    
    // Read the numbers
    for(int i = 0; i < MAX_NUMS; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Print the numbers
    for(int i = 0; i < MAX_NUMS; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
