#include "Card.h"

Card::Card(int rank, Color color){
    //Sets the card rand and color based off the given values
    this->rank = rank;
    this->color = color;

    //Sets the value based off of the color
    //0 is purple and 1 is orange
    if(color == 0){
        value = rank;
    }
    else if(color == 1){
        value = rank * 2;
    }
}

std::string Card::printCard(){
    //Prints out the card by checking the cards color and then printing the 
    //color and rank of the card
    std::stringstream ss;
    if(color == 0){
        ss << "purple";
    }
    else if(color == 1){
        ss << "orange";
    }
    ss << ":";
    ss << rank;
    
    return ss.str();
}

int Card::getRank(){
    return rank;
}

Card::Color Card::getColor(){
    return color;
}

int Card::getValue(){
    return value;
}