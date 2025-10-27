#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Card.h"

class Deck
{
    private:
        std::vector<Card> deck;

    public:
        Deck();
        void shuffle();
        Card drawCard();
        int getDeckSize();
};
  

#endif // DECK_H_
