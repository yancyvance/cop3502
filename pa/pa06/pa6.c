#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_FILE "adopt.txt"

/*
    COP 3502C PA6
    This program is written by: Your Full Name
*/


/* ---------- Global Modes ---------- */
typedef enum { 
    MODE_ADOPTION = 0,      /* Max-heap by adoption_key (higher is better)   */
    MODE_TRIAGE   = 1       /* Min-heap by triage_key   (lower is more urgent)*/
} Mode;

/* ---------- Core Cat Record ---------- */
typedef struct Cat {
    char *name; 		    /* dynamically allocated, unique string (<= 25 chars + '\0') */
    char *breed; 		    /* dynamically allocated string */
    int age; 		        /* years */
    int friendliness; 	    /* 0..100 */
    int health;       	    /* 0..100      (higher means healthier) */
    int arrival_id;   	    /* strictly increasing when ADDed */
    int quarantine;   	    /* 0 or 1 (1 => cannot be adopted; S1) */
    double key;         	/* cached priority value for the **active** mode */
} Cat;

/* ---------- Array-Based Binary Heap of Cat* ---------- */
typedef struct {
    Cat **arr;              /* array of Cat* implementing the heap */
    int size;         	    /* current number of elements */
    int capacity;     	    /* allocated capacity */
    Mode mode;         	    /* controls comparator semantics */
} CatHeap;

/* ---------- Global Shelter State ---------- */
typedef struct {
    Mode mode;		        /* MODE_ADOPTION or MODE_TRIAGE */
    char *featured_breed;	/* NULL => none; else dynamically allocated breed string */
    double alpha;		    /* multiplier for featured breed (>= 1.0; default 1.0)*/
    int next_arrival_id;    /* increments on each ADD */
    CatHeap heap;		    /* priority structure */
} Shelter;



// Function Prototypes
void myMain(FILE *ifile);

int find_cat_index(const CatHeap *heap, const char *name);
double compute_adoption_key(const Cat *c, const Shelter *S);
double compute_triage_key(const Cat *c);
void recompute_all_keys_and_build(Shelter *S);
void cmd_add (Shelter *S, const char *name, const char *breed, int age, int friendl, int health);
void cmd_update(Shelter *S, const char *name, const char *field, int new_value);
void cmd_remove(Shelter *S, const char *name);
void cmd_peek (const Shelter *S);
void cmd_serve(Shelter *S);
void cmd_mode  (Shelter *S, const char *mode_str);
void cmd_featured(Shelter *S, const char *breed, double alpha);
void cmd_print (const Shelter *S, int k);

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
    
    // Calls your own main function and passes the file stream
    myMain(ifile);
    
    // Close the file
    fclose(ifile);
    
    return 0;
}
#endif
// END: DO NOT MODIFY THE MAIN FUNCTION





// Function Definitions
void myMain(FILE *ifile) {
    // TODO: Complete this function
    // TODO BEGIN





    // TODO END
}
