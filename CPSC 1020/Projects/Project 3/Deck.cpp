#include "Deck.h"
#include "Card.h"

//Fills the deck with cards
Deck::Deck(){
    //Adds 10 purple cards with values 1-10
    for(int i = 0; i < 10; i++){
        deck.push_back(Card(i+1, Card::Color::purple));
    }

    //Adds 10 orange cards with values 1-10
    for(int i = 0; i < 10; i++){
        deck.push_back(Card(i+1, Card::Color::orange));
    } 
}

//Shuffles the deck
void Deck::shuffle(){
    srand((unsigned) time(NULL));
    int random = rand();

    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(random));
}

Card Deck::drawCard(){
    
    //Returns the first card from the deck and then 
    //erases that card from the deck
    Card first = deck[0];
    deck.erase(deck.begin());
    return first;
}

int Deck::getDeckSize(){
    return deck.size();
}

