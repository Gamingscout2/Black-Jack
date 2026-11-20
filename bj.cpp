#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <random>
#include <thread>
#include <utility>
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
  vector<vector<string>> deck(2); // initialize with 2 empty rows instead

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      deck[0].push_back(values[j]);
      deck[1].push_back(suits[i]);
    }
  }
  return deck;
}

std::mt19937 getRandGen(){
  std::random_device rd;
  return std::mt19937(rd()); // get a seed
  //std::uniform_int_distribution<int64_t> dist(1, 9223372036854775807); // random up to 64 bit signed limit
  //int64_t result = dist(gen);
  //return result;
}

void printDeck( const vector<vector<string>>& deck ){
  if(deck.empty() ){ 
    cout << 0 << " Deck Empty\n"; 
    return;
  } // do not print if deck is empty!
  size_t nRows = deck.size(); // represent number of elements, unsigned int type size_t
  size_t nCols = deck[0].size();
  for(size_t col = 0; col < nCols; ++col){
    // iterate through the coloumns and print the cards!
    cout << deck[0][col] << " of "<<  deck[1][col] << "\n";
  }
}

vector <vector<string>> shuffleDeck( vector<vector<string>> deck ){
  if( deck.size() < 2 || deck[0].empty() ){
    cout << "Deck is Empty!\n";
    return {};
  }
 
  int numCards = deck[0].size();
  // Fisher-Yates shuffle algorithm
  for (int i = numCards - 1; i > 0; --i) {
        std::mt19937 gen = getRandGen();
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        // Swap BOTH row 0 (value) and row 1 (suit) at the same column indices
        std::swap(deck[0][i], deck[0][j]);
        std::swap(deck[1][i], deck[1][j]);
    }
  return deck;
  
}


  int main(){
    vector<vector<string>> deck = createDeckDynamic();
    printDeck(deck); // Don't need to print the deck now that we know it works! Re-use printDeck for hands as well.
    cout << "Welcome to C++ Black Jack, by Pheadra Parsons!\n";
    //cout << getRandInt() << "\n";
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //cout << getRandInt() << "\n";
    cout << "shuffle 1\n";
    vector<vector<string>> deck2 = shuffleDeck(deck);
    printDeck(deck2);
    
  }
  



