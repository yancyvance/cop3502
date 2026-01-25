#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE "input.txt"

/*
    COP 3502C PA1
    This program is written by: Your Full Name
*/

typedef struct Cat_s {
    char *name;         // Cat's name (dynamic string)
    int age;            // Cat's age
    float weight;       // Cat's weight
    char *breed;        // Cat's breed (already allocated dynamic string)
    int status;         // Cat's status 0, 1, or 2 (default) [index to an array]
} Cat;

typedef struct Kennel_s {
    char *location;     // Kennel's location name (dynamic string)
    int occupancy;      // Actual number of cats currently residing
    Cat **cats;         // The cats residing (dynamic array of pointers to struct)
    int maxCapacity;    // The maximum number of cats that can reside
} Kennel;

typedef struct CatStore_s {
    Kennel *kennels;    // Kennels owned by the store (dynamic array)
    int numKennels;     // Number of kennels owned
    int **capacities;   // Dynamic 2D array indicating the constraints across kennels and breeds
} CatStore;


// Global Variable
const char CAT_STATUS[3][20] = {"ADOPTED", "PENDING", "AVAILABLE"};


// Function Prototypes (Required 14 Functions)
char **readBreeds(FILE *ifile, int *count);
char *lookupBreed(char **dictionary, int breedCount, char *breedName);
CatStore *createStore(FILE *ifile, int kennelCount, char **dictionary, int breedCount);
Kennel *createKennels(FILE *ifile, int kennelCount, char **dictionary, int breedCount, int **constraints);
Cat **createCats(FILE *ifile, char **dictionary, int breedCount, int catCount);
Cat *createSingleCat(FILE *ifile, char **dictionary, int breedCount);
int canMoveTo(CatStore *s, char *location, char *breed, char **dictionary, int breedCount);
Kennel *getKennelByCat(CatStore *s, Cat *cat);
int getCatIndex(Kennel *home, Cat *cat);
Cat *getCatByName(CatStore *s, char *catName);
void removeCatFromKennel(Kennel *k, Cat *cat);
void runQueries(FILE *ifile, CatStore *s, char **dictionary, int breedCount, int numQueries);
void freeBreeds(char **dictionary, int breedCount);
void freeStore(CatStore *store);

// You may add more functions if necessary




// BEGIN: DO NOT MODIFY THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {    
    // Open the input file for reading.
    // This is the only part of the entire code where the file
    // is going to be opened. You should not have any
    // fopen() function call in your functions. Simply
    // pass this existing FILE pointer when necessary.
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    char **dictionary;      // Dynamic array of dynamic strings
    int breedCount;         // The number of strings in dictionary
    
    // Allocate the array and populate it
    dictionary = readBreeds(ifile, &breedCount);
    
    // Read the number of kennels
    int kennelCount;
    fscanf(ifile, "%d", &kennelCount);
    
    // Create a store and populate it
    CatStore *s = createStore(ifile, kennelCount, dictionary, breedCount);
    
    // Read the number of queries
    int numQueries;
    fscanf(ifile, "%d", &numQueries);
    
    // Run the queries
    runQueries(ifile, s, dictionary, breedCount, numQueries);

    // Close the file
    fclose(ifile);
    
    // Deallocate the store and all memory associated within
    freeStore(s);
    
    // Deallocate the array of dynamic strings
    freeBreeds(dictionary, breedCount);
    
    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION



// Function Definitions
char **readBreeds(FILE *ifile, int *count) {
    // TODO: Complete this function
    // TODO 1 BEGIN





    // TODO 1 END
}

char *lookupBreed(char **dictionary, int breedCount, char *breedName) {
    // TODO: Complete this function
    // TODO 2 BEGIN





    // TODO 2 END
}

CatStore *createStore(FILE *ifile, int kennelCount, char **dictionary, int breedCount) {
    // TODO: Complete this function
    // TODO 3 BEGIN





    // TODO 3 END
}

Kennel *createKennels(FILE *ifile, int kennelCount, char **dictionary, int breedCount, int **constraints) {
    // TODO: Complete this function
    // TODO 4 BEGIN





    // TODO 4 END
}

Cat **createCats(FILE *ifile, char **dictionary, int breedCount, int catCount) {
    // TODO: Complete this function
    // TODO 5 BEGIN





    // TODO 5 END
}

Cat *createSingleCat(FILE *ifile, char **dictionary, int breedCount) {
    // TODO: Complete this function
    // TODO 6 BEGIN





    // TODO 6 END
}

int canMoveTo(CatStore *s, char *location, char *breed, char **dictionary, int breedCount) {
    // TODO: Complete this function
    // TODO 7 BEGIN





    // TODO 7 END
}

Kennel *getKennelByCat(CatStore *s, Cat *cat) {
    // TODO: Complete this function
    // TODO 8 BEGIN





    // TODO 8 END
}

int getCatIndex(Kennel *home, Cat *cat) {
    // TODO: Complete this function
    // TODO 9 BEGIN





    // TODO 9 END
}

Cat *getCatByName(CatStore *s, char *catName) {
    // TODO: Complete this function
    // TODO 10 BEGIN





    // TODO 10 END
}

void removeCatFromKennel(Kennel *k, Cat *cat) {
    // TODO: Complete this function
    // TODO 11 BEGIN





    // TODO 11 END
}

void runQueries(FILE *ifile, CatStore *s, char **dictionary, int breedCount, int numQueries) {
    // TODO: Complete this function
    // TODO 12 BEGIN





    // TODO 12 END
}

void freeBreeds(char **dictionary, int breedCount) {
    // TODO: Complete this function
    // TODO 13 BEGIN





    // TODO 13 END
}

void freeStore(CatStore *store) {
    // TODO: Complete this function
    // TODO 14 BEGIN





    // TODO 14 END
}

// You may add more functions if necessary
