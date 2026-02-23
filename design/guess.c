#include <stdio.h>
#include <ctype.h>
#define MAX_GUESS 7

int main(void) {
    int low = 1;
    int high = 100;
    char response;
    int count = 1;
    
    printf("No matter what number you choose, I will find it in %d guesses or fewer.\n", MAX_GUESS);
    //getchar();
    
    while( 1 ) {
        int guess = ( low + high ) / 2;
        
        if( count < MAX_GUESS ) {
            printf("Guess #%d: Your number is %d\n", count++, guess);
        }
        else {
            printf("I am 100%% sure that your number is %d\n", guess);
            break;
        }
        
        printf("Respond if my guess is [H]igh, [L]ow, or [Correct]: ");
        scanf(" %c", &response);
        
        response = toupper(response);
        
        if( response == 'H' )
            high = guess - 1;
        else if( response == 'L' )
            low = guess + 1;
        else
            break;
    }
    
    printf("Magic!\n");

    return 0;
}
