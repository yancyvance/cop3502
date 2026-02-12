#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 101
#define LIMIT_SECONDS 600
#define INPUT_FILE "songs.txt"

typedef struct Song_s {
    int song_id;                // Song's unique ID
    char title[MAX_LEN];        // Title (no whitespaces; Use _ as separator)
    int length;                 // Length of the song in seconds
} Song;


// Function Prototypes

// Permutation Related Functions
void permutation_init(const Song *songs, int n);
void permutation_fill(Song *solution, int size, int pos,
                      const Song *actual, int *is_used);
void permutation_print(const Song *solution, int size);

// Subset Related Functions
void subset_init(const Song *songs, int n);
int subset_fill(int *solution, int size, int pos, const Song *actual);
int subset_check(int *solution, int size, const Song *actual);
void subset_print(int *solution, int size, const Song *actual);

// Helper Functions
Song *read_songs(FILE *ifile, int *count);
void destroy_songs(Song *songs);
void song_print(const Song *s);


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
    
    // Keep track of the song count
    int song_count;
    
    // Dynamically allocate an array of songs
    Song *songs = read_songs(ifile, &song_count);
    
    // Close the file
    fclose(ifile);

    // Part 1: Permutations
    printf("Shuffle Playlists\n");
    printf("=================\n");
    permutation_init(songs, song_count);

    printf("\n");
    
    // Part 2: Subsets
    printf("Subset Playlists\n");
    printf("================\n");
    subset_init(songs, song_count);

    // Deallocate space
    destroy_songs(songs);

    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION


// Function Definitions
void permutation_init(const Song *songs, int n) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    
    // Allocate a temporary array of songs that will hold the solution
    Song *perm = malloc(sizeof(Song) * n);
    // Allocate the flag array and ensure they are all initialized
    // to 0; therefore, we use calloc() here
    int *is_used = calloc(n, sizeof(int));

    // Invoke the recursive function to generate the playlists
    permutation_fill(perm, n, 0, songs, is_used);
    
    // Deallocate the arrays
    free(perm);
    free(is_used);
    
    // TODO 1 END
}

void permutation_fill(Song *solution, int size, int pos,
                      const Song *actual, int *is_used) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    
    // Base case is when we have filled all the slots of the
    // solution array
    if( pos == size ) {
        // We simply print the array
        permutation_print(solution, size);
        
        return;     // Do not forget this! Otherwise, stack overflow!
    }
    
    // Strategy: Parallel Arrays
    // For each possible song that we can use to fill in the slot
    for(int i = 0; i < size; i++) {
        // Check first if it hasn't been used yet
        if( !is_used[i] ) {
            // Mark this song as used
            is_used[i] = 1;
            
            // Shallow copy the song from actual to the solution array
            // which we are using to fill in the slot
            solution[pos] = actual[i];
            
            // Recursive call to fill in the remaining slots
            permutation_fill(solution, size, pos+1, actual, is_used);
            
            // Unmark the song so that it is now unused
            is_used[i] = 0;
        } 
    }
    
    // TODO 2 END
}

void permutation_print(const Song *solution, int size) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    
    // Helper function to print playlist produced by permutation
    for(int i = 0; i < size; i++) {
        song_print( solution+i );       // pointer arithmetic
        
        // Logic to prevent the excess | for the last element
        if( i < size-1 )
            printf(" | ");              // separator
    }
    printf("\n");
    
    // TODO 3 END
}

void subset_init(const Song *songs, int n) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    
    // Allocate a temporary array of int that will hold the solution
    // This will be selection array (1 - inclusion; 0 - exclusion)
    // No need to initialize all elements to 0, so malloc is fine
    int *chosen = malloc(sizeof(int) * n);

    // This function promises to return the number of non-empty
    // playlists it can generate that are at most 10 minutes
    int count = subset_fill(chosen, n, 0, songs);
    
    // Print the result
    printf("%d\n", count);
    
    // Deallocate the array
    free(chosen);
    
    // TODO 4 END
}

int subset_fill(int *solution, int size, int pos, const Song *actual) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    
    // Base case is when we have filled all the slots of the
    // solution array
    if( pos == size ) {
        // Check if this candidate is a correct solution
        int res = subset_check(solution, size, actual);
        
        // We only want to print those correct solutions
        if( res ) {
            subset_print(solution, size, actual);
        }
        
        // Report back to the caller whether this candidate
        // is a correct solution or not
        return res;
    }
    
    // Accumulator which counts how many correct solutions
    // we have found for each decision branch
    // This is crucial and must be initialized (otherwise, garbage)
    int partial = 0;
    
    // Normally, we start with 0 then 1 but the effect would be descending
    // So, we swap the ordering to mark it as 1 then 0 so that it will
    // follow the ascending order; if this was a for loop, it should
    // be a countdown behavior instead of a countup
    // In short, we want to process from left to right the song list
    
    // Mark this song Included (notice the pair of codes)
    solution[pos] = 1;
    partial = partial + subset_fill(solution, size, pos+1, actual);
    
    // Mark this song Excluded (notice the pair of codes)
    solution[pos] = 0;
    partial = partial + subset_fill(solution, size, pos+1, actual);
    
    // Report back the total results after consolidating the 
    // results from the 0 and the 1 branches
    return partial;
    
    // TODO 5 END
}

int subset_check(int *solution, int size, const Song *actual) {
    // TODO: Complete this function
    // TODO 6 BEGIN
    
    // return 1 if the sum of all the duration of songs
    // is less than 10 minutes; otherwise return 0
    // constraint: it cannot be an empty list either
    // hard limit is 600 seconds but greater than 0
    int total = 0;
    
    // Add up all the duration of the chosen songs
    for(int i = 0; i < size; i++) {
        if( solution[i] )
            total = total + actual[i].length;
    }
    
    // If the total duration is between 0 (exclusive) AND 600 (inclusive)
    return total > 0 && total <= LIMIT_SECONDS;
    
    // TODO 6 END
}

void subset_print(int *solution, int size, const Song *actual) {
    // TODO: Complete this function
    // TODO 7 BEGIN
    
    // Strategy: Parallel Arrays!
    // Helper function to print playlist produced by subset
    int count = 0;
    for(int i = 0; i < size; i++) {
        // Print only the songs that are marked as included
        if( solution[i] ) {
            // Additional logic to prevent excess | at the end
            if( count++ > 0 )          // Notice the postfix increment
                printf(" | ");         // separator
            song_print( actual+i );    // pointer arithmetic
        }
    }
    printf("\n");
    
    // TODO 7 END
}

Song *read_songs(FILE *ifile, int *count) {
    // Helper function to read a file and populate a list of songs
    if(!ifile || !count) return NULL;

    // Read the number of songs
    fscanf(ifile, "%d", count);

    // Dynamically allocate an array of songs
    // Assumes that the songs are sorted within the file
    Song *songs = malloc(sizeof(Song) * (*count));
    if(!songs) return NULL;     // Safeguard in case malloc fails

    // Read the song information
    for(int i = 0; i < *count; i++) {
        fscanf(ifile, "%d", &songs[i].song_id);
        fscanf(ifile, "%s", songs[i].title);
        fscanf(ifile, "%d", &songs[i].length);
    }

    return songs;
}

void destroy_songs(Song *songs) {
    // Helper function to deallocate a list of songs
    free(songs);
}

void song_print(const Song *s) {
    // Helper function to print a single song
    printf("%s (%d)", s->title, s->length);
}
