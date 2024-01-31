#include "Square.h"

bool Square::setSide(double len){
    bool validData = false;

    if (len >= 0){
        side = len;
		validData = true;
    }

    return validData;
}

double Square::getSide()
{
    return side;
}

double Square::calcArea(){
    return pow(side, 2);
}