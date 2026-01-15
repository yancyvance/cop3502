#include <stdio.h>
#include <string.h>
#define MAX_LEN 101

// Write a program that keeps track of the cards held by a single player.

// TODO 1: Define a structure
typedef struct Card_s {
    int value;
    char suit[MAX_LEN];     // 100 characters + null character
} Card;

// Function Prototypes
void print_card(Card c);
void print_card2(Card *c);


int main(void) {
    // TODO 2: Create a single card and set fields
    Card card;
    
    card.value = 3;
    //card.suit = "spade";  // this is wrong!
    strcpy( card.suit, "spade" );
    
    //printf("%d %s\n", card.value, card.suit);
    print_card2(&card);
    
    
    // TODO 5: Represent a single player's hand holding 3 cards


    // TODO 6: Define a function that prints the cards held
    
    
    
    return 0;
}

// TODO 3: Define a function that prints the card details
void print_card(Card c) {
    printf("%d %s\n", c.value, c.suit);
}

// TODO 4: Define another function that does the same thing
void print_card2(Card *c) {
    //printf("%d %s\n", (*c).value, (*c).suit);
    printf("%d %s\n", c->value, c->suit);   // same with above
}
