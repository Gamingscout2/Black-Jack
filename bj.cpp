#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <random>
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

int64_t getUnixTime(){
  // return Unix timestamp, agnostic of the OS
  using namespace std::chrono;
  const auto now = system_clock::now(); // get current system time
  //int64_t seconds = duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
  int64_t milliseconds = duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
  // return the milliseconds since 1970 for random number generation!
  return milliseconds;
}

int64_t getRandInt(){
  int64_t time = getUnixTime(); // store current time in ms
  std::random_device rd;
  static std::mt19937 gen(rd()); // one-time seed
  std::uniform_int_distribution<int64_t> dist(1, 500); // store a modifier value
  modifier = dist(gen);

  std::uniform_int_distribution<int64_t> dist1(1, 6); // dice roll modifier
  operand = dist1(gen); // this determines what operation to do to the random numbers!

  switch(operand) {
    case 1:
      int64_t resultA = time / modifier;
      int64_t resultB = modifier + resultA;
      return resultB;
    case 2:
      int64_t resultA = time + modifier;
      int64_t resultB = resultA / modifier;
      return resultB;
    case 3:
      int64_t resultA = modifier / time;
      int64_t resultB = time * resultA;
      int64_t resultC = resultB + modifier;
      return resultC;
    case 4:
      int64_t resultA = time / modifier;
      int64_t resultB = resultA * operand;
      int64_t resultC = resultB + resultA;
      return resultC;
    case 5:
      int64_t resultA = modifier * ((time / operand) / operand);
      int64_t resultB = resultA + (modifier * ((operand * resultA) / modifier);
      return resultB;
  }
  
}

void printDeck( const vector<vector<string>>& deck ){
  if(deck.empty() ){ cout << 0 << " Deck Empty\n"; } // do not print if deck is empty!
  size_t nRows = deck.size(); // represent size in bytes, unsigned int type size_t
  size_t nCols = deck[0].size();
  for(size_t col = 0; col < nCols; ++col){
    // iterate through the coloumns and print the cards!
    cout << deck[0][col] << " of "<<  deck[1][col] << "\n";
  }
}

vector<vector<string>> shuffleDeck( const vector<vector<string>>& deck ){
  
}


  int main(){
    vector<vector<string>> deck = createDeckDynamic();
    //printDeck(deck); // Don't need to print the deck now that we know it works! Re-use printDeck for hands as well.
    cout << "Welcome to C++ Black Jack, by Pheadra Parsons!";
    
  }
  



