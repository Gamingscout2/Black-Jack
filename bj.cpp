#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> createDeckStatic(){
  // create a deck vector, 2D string array
  vector<vector<string>> deck = {
  {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"},
  {"Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Spades", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Diamonds", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Clubs", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts", "Hearts"}
  };
  // our new deck order is Spades, Diamonds, Clubs, Hearts in ascending order. As if sorted by hand
  return deck;
}

vector <vector<string>> createDeckDynamic(){
  // dynamically generate the deck so that we don't need to check our static list by hand
  vector<string> suits = { "Spades", "Diamonds", "Clubs", "Hearts"  }; // this way the loop can call 0-3 and append them into the second dimension
  vector<string> values = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" }; // 13 card values, 4 suits
  vector<vector<string>> deck(2, vector<string>(52));

  for(i = 0, i < 4, i++){
    for(j = 0, j < 14, j++){
      
    }
  }
  
}


