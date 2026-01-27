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
char **remove_fruit(char **list, int *size, char *query);


// BEGIN: DO NOT MODIFY THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    // Open the file
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    // Safeguard in the event the file cannot be opened
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }

    // The reading of the contents of the file will be done
    // across several functions, that's why we are passing
    // ifile to those functions
    
    // Create a list of words (array of strings)
    int N;
    char **fruits = create_and_populate_list( ifile, &N );   // notice &count
    
    // Uncomment for Guide Question 4
    //fruits = remove_fruit( fruits, &N, "apple" );
    
    // Perform some operations on the list
    search_list( ifile, fruits, N );
    
    // Destroy the list
    destroy_list( fruits, N );   // notice the need to pass the size of the list
    
    // Close the file
    fclose(ifile);

    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION


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

char **remove_fruit(char **list, int *size, char *query) {
    // DO NOT MODIFY THIS FUNCTION
    // You need to understand what this function is doing
    
    // Do a lookup if the query exists
    int idx = index_of(list, *size, query);
    
    // If not found, do not make any modifications.
    // Simply return the original list.
    if( idx == -1) return list;
    
    // Remember the dynamic string as it will be overwritten
    char *tmp = list[idx];
    
    // Remove the fruit by shifting all the
    // elements to the left beginning at idx+1
    for(int i = idx; i < (*size)-1; i++) {     // notice the condition
        list[i] = list[i+1];    // move to the left
    }
    
    // Design choice: We deallocate the deleted dynamic string here
    free(tmp);

    // Design choice: We resize the array to lose one space
    int new_size = (*size) - 1;
    char **new_list = realloc( list, sizeof(char *) * new_size );
    
    // Update the *size parameter
    *size = new_size;
    
    // If realloc is successful, then we return the new list
    if( new_list != NULL ) {        
        // no need to deallocate the old list because realloc()
        // does this for you if it is successful
        return new_list;
    }
    
    // If realloc failed, we return the reference to the old list.
    // However, we already have made the shift.
    return list;
}
