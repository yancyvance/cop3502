#include <stdio.h>

// Sample C Implementation of a Recursive 
// Solution to the Tower of Hanoi Problem
// This combines all the codes covered during the lecture.
// Please report any bug you may find.
// This code was last updated on 2025-04-04.


// function prototype
void move(int, char, char, char);


int main(void) {
    int disk_count;

    // ask the user how many disks in this game
    printf("How Many Disks: ");
    scanf("%d", &disk_count);

    // assuming I have N disks
    // there are 3 named poles: A, B, C
    // all the N disks are currently in Pole A;
    // therefore A takes on the role of the init pole
    // we want to move the N disks to Pole C;
    // therefore C takes on the role of the goal pole
    // Pole B takes on the role of the spare pole
    move(disk_count, 'A', 'C', 'B');

    return 0;
}


void move(int n, char init, char goal, char spare) {
    // base case in which we only have one disk
    if(n == 1) {
        // we simply move this single disk from the init pole to the goal pole
        printf("Move Disk %d from Pole %c to Pole %c\n", n, init, goal);

        // ensure that the remaining statements (recursive case)
        // are not called anymore because we are dealing
        // with the base case
        return;
    }

    // transition from init state to state 1
    // move the n-1 disks (above the largest n-th disk
    // from the init pole to the spare pole
    // notice the change in the roles where in this process
    // the "goal" is to put all these n-1 disks to the spare
    // thus, the arguments are arranged as such
    move(n-1, init, spare, goal);

    // transition from state 1 to state 2
    // we now want to move the n-th disk from the init pole to the goal pole
    // notice that this is different from the base case because currently
    // the assumption is that there were more than 1 disk in the
    // entire game
    printf("Move Disk %d from Pole %c to Pole %c\n", n, init, goal);

    // transition from state 2 to state 3
    // now that the n-th largest disk is in the goal pole
    // we now move the n-1 disks which are currently in the spare pole
    // to the goal pole
    // notice the change in the roles where in this process
    // the "init" location of the disks is the spare pole
    // thus, the arguments are arranged as such
    move(n-1, spare, goal, init);
}
