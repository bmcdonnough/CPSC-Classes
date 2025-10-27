#include "Rectangle.h"

bool Rectangle::setLength(double len){
    bool validData = false;

    if (len >= 0){
        length = len;
        validData = true;
    }

    return validData;
}

bool Rectangle::setWidth(double wid){
    bool validData = false;

    if (wid >= 0){
        width = wid;
        validData = true;
    }

    return validData;
}

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::calcArea(){
    return length * width;
}