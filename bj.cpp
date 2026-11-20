#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdint>
#include <random>
#include <thread>
#include <utility>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

enum class Suit { Spades, Diamonds, Clubs, Hearts };
enum class Rank { Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King }; // keep this order, later logic depends on it!


struct Card {
  Suit suit;
  Rank rank;
};

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

// 1. Convert Suit to a readable string
std::string suitToString(Suit s) {
const std::string spade   = "\u2660"; 
const std::string heart   = "\u2665"; 
const std::string diamond = "\u2666"; 
const std::string club    = "\u2663"; 
    switch (s) {
        case Suit::Spades:   return "Spades " + spade;
        case Suit::Diamonds: return "Diamonds " + diamond;
        case Suit::Clubs:    return "Clubs " + club;
        case Suit::Hearts:   return "Hearts " + heart;
        default:             return "Unknown";
    }
}

std::string rankToString(Rank r) {
  // converts to printable strings
  switch (r) {
      case Rank::Ace:   return "Ace";
      case Rank::Two:   return "2";
      case Rank::Three: return "3";
      case Rank::Four:  return "4";
      case Rank::Five:  return "5";
      case Rank::Six:   return "6";
      case Rank::Seven: return "7";
      case Rank::Eight: return "8";
      case Rank::Nine:  return "9";
      case Rank::Ten:   return "10";
      case Rank::Jack:  return "Jack";
      case Rank::Queen: return "Queen";
      case Rank::King:  return "King";
      default:          return "Unknown";
  }
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
  // defines 
  os << rankToString(c.rank) << " of " << suitToString(c.suit);
  return os;
}

void printDeck(const std::vector<Card>& deck) {
    for (const Card& card : deck) {
        std::cout << card << '\n';
    }
}

vector<Card> shuffleDeck( vector<Card> deck){
  std::mt19937 gen = getRandGen();
  std::shuffle(deck.begin(), deck.end(), gen);
}

  int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // use UTF-8 if using windows!
    #endif
    const std::string spade   = "\u2660"; 
    const std::string heart   = "\u2665"; 
    const std::string diamond = "\u2666"; 
    const std::string club    = "\u2663"; 
    //vector<vector<string>> deck = createDeckDynamic();
    vector<Card> deck = createDeck();
    printDeck(deck); // Don't need to print the deck now that we know it works! Re-use printDeck for hands as well.
    cout << spade << " Welcome to C++ Black Jack, by Pheadra Parsons! " << spade << "\n" ;
    //cout << getRandInt() << "\n";
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //cout << getRandInt() << "\n";
    cout << "shuffle 1\n";
    vector<card> deck2 = shuffleDeck(deck);
    printDeck(deck2);
    
  }
  



