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
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    // Keep track of the song count
    int song_count;
    
    // dynamically allocate an array of songs
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
    
    
    
    
    
    // TODO 1 END
}

void permutation_fill(Song *solution, int size, int pos,
                      const Song *actual, int *is_used); {
    // TODO: Complete this function
    // TODO 2 BEGIN
    
    
    
    
        
    // TODO 2 END
}

void permutation_print(const Song *solution, int size) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    
    
    
    
    
    // TODO 3 END
}

void subset_init(const Song *songs, int n) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    
    
    
    
    
    // TODO 4 END
}

int subset_fill(int *solution, int size, int pos, const Song *actual) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    
    
    
    
    
    // TODO 5 END
}

int subset_check(int *solution, int size, const Song *actual) {
    // TODO: Complete this function
    // TODO 6 BEGIN
    
    
    
    
    
    // TODO 6 END
}

void subset_print(int *solution, int size, const Song *actual) {
    // TODO: Complete this function
    // TODO 7 BEGIN
    
    
    
    
    
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
