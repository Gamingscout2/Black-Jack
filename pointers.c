/******************************************************************************

Simple, yet effective, Black Jack game in C. The game generates random hands for 
both the player and the dealer, simulating a basic round of Black Jack. 
The player's and dealer's hands are displayed, allowing for a straightforward 
comparison of their values.

Phaedra Parsons 2026

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <string.h>

#define ROWS 52
#define COLS 2

char *a = "Ace";
char *b = "Two";
char *c = "Three";
char *d = "Four";  
char *e = "Five";
char *f = "Six";
char *g = "Seven";
char *h = "Eight";
char *i = "Nine";
char *j = "Ten";
char *k = "Jack";
char *l = "Queen";
char *m = "King";

char *aa = "Spades";
char *bb = "Hearts";
char *cc = "Diamonds";
char *dd = "Clubs";

char **build_deck(void) {
    // this function will build a deck of cards
    // using an array of pointers to strings, where each string represents a card in the deck
    // first dimension is card name / value, second dimension is suit
    // the names will be converted to integers for the purpose of calculating the value of the hand
    int o, p;
    char *suits[] = {aa, bb, cc, dd};
    char *values[] = {a, b, c, d, e, f, g, h, i, j, k, l, m};
    char *deck[52][2];

    for(o = 0; o < 4; o++) {
        for(p = 0; p < 13; p++) {
            deck[o * 13 + p][0] = values[p];
            deck[o * 13 + p][1] = suits[o];
        }
    }

    char *deck2[52][2];
    for(int q = 0; q < 52; q++) {
        deck2[q][0] = deck[q][0];
        deck2[q][1] = deck[q][1];
    }

    // debug print the contents of the deck
    printf("Deck of Cards:\n");
    for(int q = 0; q < 52; q++) {
        printf("%s of %s\n", deck2[q][0], deck2[q][1]);
    }

    return deck;
}

int rnd_num(void) {
    // try to get a number based on current time
    // the time changes help to introduce some extra randomness
    // and make the pseudo-random rand function more
    // effective
    srand(time(NULL) % 2);
    srand(rand());
    int x = rand();
    _sleep(500); // Windows equivalent of sleep(0.5)
    srand(x);
    int y = rand();
    srand(y);
    _sleep(200); // Windows equivalent of sleep(0.2)
    srand(time(NULL));
    // int hand = ((rand() % 21) + 1) + ((rand() % 21) + 1);
    // if(hand > 21){
    //     hand = rnd_num();
    // }
    int hand = rand() % 52; // generate a random number between 0 and 51 to simulate a card draw, 
    // then use that value as the index to access the deck array and get the card value
    return hand;
}

void shuffle(char *deck[52][2]){
    
    // this function will shuffle the deck of cards
    // using the Fisher-Yates shuffle algorithm
    int o, p;
    char *temp[52][2];
    for(o = 0; o < 52; o++) {
        temp[o][0] = deck[o][0];
        temp[o][1] = deck[o][1];
    }
    for(o = 51; o > 0; o--) {
        p = rand() % (o + 1);
        temp[o][0] = deck[p][0];
        temp[o][1] = deck[p][1];
        temp[p][0] = deck[o][0];
        temp[p][1] = deck[o][1];
    }
    printf("Shuffled Deck of Cards:\n");
    for(o = 0; o < 52; o++) {
        printf("%s of %s\n", temp[o][0], temp[o][1]);
    }
    // verify that the deck is shuffled by printing the contents of the deck
    // Especially check to ensure that the shuffle algorithm doesn't duplicate any cards or leave out cards
}

int get_hand_value_old(char *hand[ROWS][COLS]){
    // this function will calculate the value of a hand of cards
    // by iterating through the hand array and adding up the values of the cards
    int o, value = 0;
    for(o = 0; o < ROWS; o++) {
        if(hand[o][0] == a) {
            value += 11;
            if (value > 21) {
                // case to handle Ace's variable value
                // of 1 or 11 based on how each value affects hand value
                value -= 10;
            }
        } else if(hand[o][0] == b) {
            value += 1;
        } else if(hand[o][0] == c) {
            value += 2;
        } else if(hand[o][0] == d) {
            value += 3;
        } else if(hand[o][0] == e) {
            value += 4;
        } else if(hand[o][0] == f) {
            value += 5;
        } else if(hand[o][0] == g) {
            value += 6;
        } else if(hand[o][0] == h) {
            value += 7;
        } else if(hand[o][0] == i) {
            value += 8;
        } else if(hand[o][0] == j) {
            value += 9;
        } else if(hand[o][0] == k || hand[o][0] == l || hand[o][0] == m) {
            value += 10;
        }
    }
    return value;

}

int get_hand_value(char *hand[ROWS][COLS]){
    // this function will calculate the value of a hand of cards
    // by iterating through the hand array and adding up the values of the cards
    int o, value = 0;
    for(o = 0; o < ROWS; o++) {
        if(hand[o][0] == a) {
            value += 11;
            if (value > 21) {
                // case to handle Ace's variable value
                // of 1 or 11 based on how each value affects hand value
                value -= 10;
            }
        } else if(strcmp(hand[o][0], j) == 0 ||
                  strcmp(hand[o][0], k) == 0 ||
                  strcmp(hand[o][0], l) == 0 ||
                  strcmp(hand[o][0], m) == 0) {
            value += 10;
        } else if(strcmp(hand[o][0], b) == 0) {
            value += 2;
        } else if(strcmp(hand[o][0], c) == 0) {
            value += 3;
        } else if(strcmp(hand[o][0], d) == 0) {
            value += 4;
        } else if(strcmp(hand[o][0], e) == 0) {
            value += 5;
        } else if(strcmp(hand[o][0], f) == 0) {
            value += 6;
        } else if(strcmp(hand[o][0], g) == 0) {
            value += 7;
        } else if(strcmp(hand[o][0], h) == 0) {
            value += 8;
        } else if(strcmp(hand[o][0], i) == 0) {
            value += 9;
        }
    }
    return value;

}


int main(void) {
    // eventually this game will use an array data type
    // to store the entire deck of cards and their values, but for now we will just
    // generate random numbers to simulate the hands of the player and dealer
    printf("Black Jack\n");
    //int player_seed = rnd_num(); // player and dealer hands
    //_sleep(1000); // Windows equivalent of sleep(1)
    //int dealer_seed = rnd_num();
    char *deck[52][2] = build_deck();
    
    //printf("You Have %d and Dealer Has %d\n", player, dealer);
    
}

