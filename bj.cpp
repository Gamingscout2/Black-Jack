#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <random>
#include <thread>
#include <utility>
#include <algorithm>
using namespace std;

enum class Suit { Spades, Diamonds, Clubs, Hearts };
enum class Rank { Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King }; // keep this order, later logic depends on it!

struct Card {
  Suit Suit;
  Rank Rank;
}

vector<Card> createDeck(){
  // swithced to vector of card structs
  vector<Card> deck;
  deck.reserve(52);
  const vector<Suit> suits = { Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades};
    for (Suit s : suits) {
        // Loop through integer values of Rank
        for (int r = static_cast<int>(Rank::Ace); r <= static_cast<int>(Rank::King); ++r) {
            deck.push_back(Card{s, static_cast<Rank>(r)});
        }
    }
  return deck;
}

std::mt19937 getRandGen(){
  std::random_device rd;
  return std::mt19937(rd()); // get a seed
}

  int main(){
    //vector<vector<string>> deck = createDeckDynamic();
    vector<Card> deck = createDeck();
    printDeck(deck); // Don't need to print the deck now that we know it works! Re-use printDeck for hands as well.
    cout << "Welcome to C++ Black Jack, by Pheadra Parsons!\n";
    //cout << getRandInt() << "\n";
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //cout << getRandInt() << "\n";
    cout << "shuffle 1\n";
    vector<vector<string>> deck2 = shuffleDeck(deck);
    printDeck(deck2);
    
  }
  



