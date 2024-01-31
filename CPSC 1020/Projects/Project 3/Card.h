#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <sstream>

class Card
{
    public:
        enum Color {purple, orange};
    private:
        int rank;
        Color color;
        int value;

    public:
        Card() : rank(0), color(purple), value(0){};
        Card(int rank, Color color);
        std::string printCard();
        int getRank();
        Color getColor();
        int getValue();

};
  

#endif // CARD_H_
