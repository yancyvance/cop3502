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





    // TODO 1 END
}

void playlist_print(Playlist *list) {
    // TODO: Complete this function
    // TODO 2 BEGIN





    // TODO 2 END
}

void playlist_add_song(Playlist *list, int s_id, char *s_title, int s_len) {
    // TODO: Complete this function
    // TODO 3 BEGIN





    // TODO 3 END
}

Song *playlist_find_longest_song(Playlist *list) {
    // TODO: Complete this function
    // TODO 4 BEGIN





    // TODO 4 END
}

void song_print(Song *s) {
    // TODO: Complete this function
    // TODO 5 BEGIN





    // TODO 5 END
}
