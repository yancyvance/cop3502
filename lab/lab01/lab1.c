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


int main(void) {
    FILE *ifile = fopen(INPUT_FILE, "r");
    
    if( ifile == NULL ) {
        printf("File Does Not Exist!\n");
        return 1;
    }
    
    Playlist p;
    
    // initialize the playlist
    playlist_init( &p, 101 );
    
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

void playlist_init(Playlist *list, int id) {



    
}

void playlist_print(Playlist *list) {




}

void playlist_add_song(Playlist *list, int s_id, char *s_title, int s_len) {




}

Song *playlist_find_longest_song(Playlist *list) {




}

void song_print(Song *s) {




}
