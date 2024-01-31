#include "Hand.h"
#include "Deck.h"
#include "Card.h"

Hand::Hand(Deck deck, int N){
    //Creates a hand by adding N number of cards from the deck
    //to the hand vector
    for (int i = 0; i < N; i++){
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand(){
    std::stringstream ss;

    //Print out the players hand by iterating through the hand vector
    for(long unsigned int i = 0; i < hand.size(); i++){
        ss << "[" << i+1 << "] ";
        ss << hand[i].printCard() ;
        ss << " ";
    }

    return ss.str();
}

Card Hand::dealCard(int num){
    //Deal the card from the player's hand
    //Also, erases the card being dealt
    Card deal = hand[num-1];
    hand.erase(hand.begin() + num - 1);
    return deal;    
}

int Hand::getHandSize(){
    return hand.size();
}