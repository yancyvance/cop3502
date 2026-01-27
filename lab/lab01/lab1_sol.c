#include <stdio.h>
#include <string.h>
#define MAX_LEN 101
#define MAX_COUNT 5
#define INPUT_FILE "songs.txt"

typedef struct Song_s {
    int song_id;                // Song's unique ID
    char title[MAX_LEN];        // Title (no whitespaces; Use _ as separator)
    int length;                 // Length of the song in seconds
} Song;

typedef struct Playlist_s {
    int list_id;                // Playlist's unique ID
    Song songs[MAX_COUNT];      // Songs added to the playlist
    int count;                  // Actual number of songs in the list
} Playlist;


// Function Prototypes
void playlist_init(Playlist *list, int id);
void playlist_print(Playlist *list);
void playlist_add_song(Playlist *list, int s_id, char *s_title, int s_len);
void song_print(Song *s);
Song *playlist_find_longest_song(Playlist *list);


// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION
#ifndef MAIN_FUNCTION
int main(void) {
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    Playlist p;
    
    // initialize the playlist
    playlist_init( &p, 101 );           // 101 here is an arbitrary ID value
    
    // Read 5 songs from a file
    
    // temporary variables
    int sid;
    char stitle[MAX_LEN];
    int slen;
    
    for(int i = 0; i < MAX_COUNT; i++) {
        // read the 3 information about the song
        fscanf(ifile, "%d", &sid);
        fscanf(ifile, "%s", stitle);    // Assumes no whitespace!
        fscanf(ifile, "%d", &slen);
        
        // add this song to the playlist
        playlist_add_song(&p, sid, stitle, slen);
    }
    
    fclose(ifile);
    
    // Print playlist
    playlist_print( &p );
    
    
    // Print the title of the song with the longest length
    Song *s = playlist_find_longest_song(&p);
    
    // Check if there was a song found
    if( s ) {
        printf("Longest Song: %s\n", s->title);
    }

    return 0;
}
#endif
// DO NOT MODIFY THIS PORTION OF THE MAIN FUNCTION


// Function Definitions
void playlist_init(Playlist *list, int id) {
    // TODO: Complete this function
    // TODO 1 BEGIN
    
    // Set the playlist's ID and initialize the count to 0
    list->list_id = id;
    list->count = 0;
    
    // TODO 1 END
}

void playlist_print(Playlist *list) {
    // TODO: Complete this function
    // TODO 2 BEGIN
    
    printf("Playlist ID: %d\n", list->list_id);
    
    // Use the actual count instead of the macro constant above
    for(int i = 0; i < list->count; i++)
        song_print( list->songs+i );
        
    // TODO 2 END
}

void playlist_add_song(Playlist *list, int s_id, char *s_title, int s_len) {
    // TODO: Complete this function
    // TODO 3 BEGIN
    
    // Get the current count and use it as the index
    int idx = list->count;
    
    // Copy the information about the song and store it in the array
    list->songs[ idx ].song_id = s_id;
    strcpy( list->songs[ idx ].title, s_title );
    list->songs[ idx ].length = s_len;
    
    // Increment the number of songs
    list->count++;
    
    // TODO 3 END
}

Song *playlist_find_longest_song(Playlist *list) {
    // TODO: Complete this function
    // TODO 4 BEGIN
    
    // Check first if there are any songs stored in the playlist
    if( list->count == 0 ) return NULL;
    
    // Assume that the max is the first element
    int max_idx = 0;
    
    // Check the other songs if there are any other songs longer
    // than the one currently stored at max_idx
    for(int i = 1; i < list->count; i++)
        if( list->songs[i].length > list->songs[max_idx].length )
            max_idx = i;
    
    // Return's the address of this element because the function
    // returns a pointer to a Song
    return &list->songs[max_idx];       // Same as &( list->songs[max_idx] )
    
    // TODO 4 END
}

void song_print(Song *s) {
    // TODO: Complete this function
    // TODO 5 BEGIN
    
    printf("%s - %d\n", s->title, s->length);
    
    // TODO 5 END
}
