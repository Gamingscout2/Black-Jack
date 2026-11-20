#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <thread>
#include <algorithm>
#include <chrono>
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
        cout << card << '\n';
    }
}

void shuffleDeck( vector<Card>& deck ){
  std::mt19937 gen = getRandGen();
  std::shuffle(deck.begin(), deck.end(), gen);
  //return deck;
}

vector<Card> dealCard( vector<Card>& deck, vector<Card> hand ){
  if( deck.size() < 1 || deck.empty() ){
    cout << "Deck is Empty!";
    return hand;
  }
  // deal a card
  Card theCard = deck.front();
  deck.erase(deck.begin());
  hand.push_back(theCard);
  return hand;
}

int getCardValue(Card card){
  int cardRank = static_cast<int>(card.rank);
  int result;
  switch(cardRank){
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      result = cardRank;
      break;
    case 11:
      result = 10;
      break;
    case 12:
      result = 10;
      break;
    case 13:
      result = 10;
      break;
  }
  return result;
}

int getHandValue(vector<Card>& hand){
  if( hand.size() < 1 || hand.empty() ) {
    cout << "Hand is Empty!";
    return 0;
  }
  int nCols = hand.size();
  int value = 0;
  int acesDetected = 0;
  for(int i = 0; i < nCols; ++i){
    if(hand[i].rank == Rank::Ace){
      acesDetected += 1;
    }
    value += getCardValue(hand[i]);
  }
  if(acesDetected > 0){
    if((value +  10) <= 21){
      value += 10;
    }
    }
  return value;
}

bool aceCheck(vector<Card>& hand){
// dealer checks hand, if it is a soft ace hand will hit over 17.
  if( hand.size() < 1 || hand.empty() ) {
    cout << "Hand is Empty!";
    return 0;
  }
  int nCols = hand.size();
  int value = 0;
  int acesDetected = 0;
  for(int i = 0; i < nCols; ++i){
    if(hand[i].rank == Rank::Ace){
      acesDetected += 1;
    }
    value += getCardValue(hand[i]);
  }
  if(acesDetected > 0){
    if((value +  10) <= 21){
      value += 10;
      return true;
    }
    else{
      return false;
    }
    }
  else{
    return false;
  }
}


int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // use UTF-8 if using windows!
    #endif
    const std::string spade   = "\u2660"; 
    const std::string heart   = "\u2665"; 
    const std::string diamond = "\u2666"; 
    const std::string club    = "\u2663"; 
    vector<Card> deck = createDeck();
    //printDeck(deck); // Don't need to print the deck now that we know it works! Re-use printDeck for hands as well.
    cout << spade << " Welcome to C++ Black Jack, by Pheadra Parsons! " << spade << "\n" ;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //cout << "shuffle 1\n";
    shuffleDeck(deck);
    //printDeck(deck);
    shuffleDeck(deck);
    std::this_thread::sleep_for(std::chrono::milliseconds(78)); // wait a bit before shuffling our final time
    shuffleDeck(deck);
    shuffleDeck(deck);
    vector<Card> playerHand;
    vector<Card> dealerHand;
    playerHand = dealCard(deck, playerHand);
    dealerHand = dealCard(deck, dealerHand);
    playerHand = dealCard(deck, playerHand);
    dealerHand = dealCard(deck, dealerHand);
    cout << "Dealer Shows: " << dealerHand[1] << "\n"; // shows the dealers second card
    cout << "You Have:\n";
    printDeck(playerHand);
    cout << "\n";
    //cout << getHandValue(playerHand) << "\n";
    bool playerBust = false;
    bool dealerBust = false;
    bool playerEndTurn = false;
    bool dealerTurn = false;
    bool dealerSoftAce = false;
    if( getHandValue(dealerHand) > 21 ){
      dealerBust = true; // nothin happens yet because the player cannot see the dealer's hand
      // also I am fairly certain (99.99% sure) this condition can NEVER fire, it is just in case
    }

    // PLAYER TURN
    while ( (!playerBust && !playerEndTurn) && !dealerBust){
      cout << "\n";
      cout << "Your Hand Value is: " << getHandValue(playerHand) << "\n";
      cout << "Would you like to hit? Y/N: ";
      string hit;
      cin >> hit;
      if((hit == "Y") || (hit == "y")){
        playerHand = dealCard(deck, playerHand);
        cout << "You Now Have: \n";
        printDeck(playerHand);
        if( getHandValue(playerHand) > 21){
          playerBust = true;
          //cout << "Player Busts!";
          break;
        }
      }
      else{
        playerEndTurn = true;
        break;
      }
    }
  //END PLAYER TURN

  // DEALER TURN
  dealerTurn = true;
  dealerSoftAce = aceCheck(dealerHand);
  cout << "Dealer Flips Their First Card! It is: " << dealerHand[0] << "\n";
  cout << "Dealer's Hand Value is: " << getHandValue(dealerHand) << "\n";
  while(dealerTurn){
    // dealer stands on 17+, hits on a soft 17, stands on soft 18+
    // only take turn if the player hasn't busted!
    if( !playerBust && !dealerBust && ( (!dealerSoftAce && getHandValue(dealerHand) < 17) || (dealerSoftAce && getHandValue(dealerHand) <= 17 ) ) ){
      cout << "\n";
      cout << "Dealer Hits\n";
      dealerHand = dealCard(deck, dealerHand);
      cout << "Dealer Showing: \n";
      printDeck(dealerHand);
      // show all dealer's cards
      // card 0 is now shown since it was "flipped over"
      // on the dealer's turn
      dealerSoftAce = aceCheck(dealerHand);
      if( getHandValue(dealerHand) > 21 ) {
        cout << "Dealer Busts!";
        dealerBust = true;
        dealerTurn = false;
        break;
      }
    }
    else{
      dealerTurn = false;
      break;
    }
  }
  // END DEALER TURN
  cout << "\n";
  cout << "Your Hand Value: " << getHandValue(playerHand) << "\n";
  cout << "Dealer's Hand Value: " << getHandValue(dealerHand) << "\n";
  if( dealerBust && !playerBust ){
    cout << "You win!\n";
  }
  else if ( !dealerBust && playerBust ){
    cout << "You Lose, Dealer Wins!\n";
  }
  else if ( getHandValue(playerHand) > getHandValue(dealerHand) ){
    cout << "You Win!\n";
  }
  else if ( getHandValue(playerHand) < getHandValue(dealerHand) ){
    cout << "You Lose! Dealer Wins!\n"; 
  }
  else if ( getHandValue(playerHand) == getHandValue(dealerHand) ){
    cout << "Tie! All bets returned.\n"; // handle returned bets!
  }
  return 0;
  }
  



