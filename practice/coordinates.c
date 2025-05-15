#include <stdio.h>
#define DATA_COUNT 10
#define INPUT_FILE "lab1.txt"

// YOU ARE ONLY ALLOWED TO MODIFY A SPECIFIC
// SECTION OF THIS SOURCE CODE
// DO NOT ADD OR REMOVE ANYTHING BEYOND THAT

typedef struct Coordinate_s {
	int x;
	int y;
} Coordinate;


// function prototype
void print_coordinates(Coordinate *arr, int size);


int main(void) {
	// open input file
	FILE *ifile = fopen(INPUT_FILE, "r");

	// check if file was successfully opened
	if(ifile == NULL) {
		printf("Error. File Not Found!");
		return 1;
	}
	
	// create an array of coordinates
	// which will store all the data
	Coordinate points[DATA_COUNT];
	
	// read the contents of the file
	for(int i = 0; i < DATA_COUNT; i++) {
		// for each line, there will be
		// two integers: x and y
		// store them in the array of structs
		fscanf(ifile, "%d%d", &points[i].x, &points[i].y);
	}
	
	// close the file
	fclose(ifile);
	
	
	// print the contents of the array
	// of coordinates; use the helper function
	print_coordinates(points, DATA_COUNT);

	return 0;
}


void print_coordinates(Coordinate *arr, int size) {
	// TODO: Complete the function.
	// Print each coordinate with zero-padded
	// 2-digit format (e.g., (03 07))
	
	
	// TODO START (Add your codes below)
	
	
	
	
	
	
	// TODO END (Do not add anything beyond this)
}
