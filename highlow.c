#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int roll_dice(void) {
    int upper = 6;
    int lower = 1;
    srand(time(0));

    int rng = (rand() % (upper - lower + 1)) + lower;
    return rng; 
}

char ask_bet(void) {
    printf("Erwarten Sie als nächstes eine größere Zahl (>) oder eine kleinere Zahl (<): ");
    char bet;
    do
    {
        scanf(" %c", &bet);
    } while (bet != '>' && bet != '<');
    
    return bet;
}

int is_bet_right(char bet, int old, int new) {
    switch (bet)
    {
    case '>':
        return new > old;
    case '<':
        return new < old;
    
    default:
        return 0;
    }
}

int main(int argc, char const *argv[]) {
    int next_roll = roll_dice();
    int prev_roll;
    char bet;
    do
    {
        printf("Sie haben eine %d gewürfelt\n", next_roll);
        bet = ask_bet();
        prev_roll = next_roll;
        next_roll = roll_dice();
    } while (is_bet_right(bet, prev_roll, next_roll));
    
    printf("Leider haben Sie eine %d gewürfelt.\n", next_roll);
    
    return 0;
}
