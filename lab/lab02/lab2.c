#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 101
#define INPUT_FILE "fruits.txt"


// Function Prototypes
char **create_and_populate_list(FILE *ifile, int *size);
void destroy_list(char **list, int size);
int index_of(char **list, int size, char *query);
void search_list(FILE *ifile, char **list, int size);


// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Open the file
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    // Safeguard in the event the file cannot be opened
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    // Create a list of words (array of strings)
    int count;
    char **fruits = create_and_populate_list( ifile, &count );   // notice &count
    
    // Perform some operations on the list
    search_list( ifile, fruits, count );
    
    // Destroy the list
    destroy_list( fruits, count );   // notice the need to pass the size of the list
    
    // Close the file
    fclose(ifile);

    return 0;
}
#endif
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION


// Function Definitions
char **create_and_populate_list(FILE *ifile, int *size) {
    // TODO: Complete this function
    // TODO 1 BEGIN





    // TODO 1 END
}

void destroy_list(char **list, int size) {
    // TODO: Complete this function
    // TODO 2 BEGIN





    // TODO 2 END
}

int index_of(char **list, int size, char *query) {
    // TODO: Complete this function
    // TODO 3 BEGIN





    // TODO 3 END
}

void search_list(FILE *ifile, char **list, int size) {
    // TODO: Complete this function
    // TODO 4 BEGIN





    // TODO 4 END
}
