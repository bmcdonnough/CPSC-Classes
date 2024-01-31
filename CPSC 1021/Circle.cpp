#include "Circle.h"

#define M_TAU 6.28318530717958647693

bool Circle::setRadius(double len){
    bool validData = false;

    if (len >= 0){
        radius = len;
		validData = true;
    }

    return validData;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::calcArea(){
    return (M_TAU / 2.0) * pow(radius, 2);
}