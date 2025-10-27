#include "Trapezoid.h"

bool Trapezoid::setBase1(double len){
    bool validData = false;

    if (len >= 0){
        base1 = len;
		validData = true;
    }

    return validData;
}

bool Trapezoid::setBase2(double len){
    bool validData = false;

    if (len >= 0){
        base2 = len;
		validData = true;
    }

    return validData;
}

bool Trapezoid::setHeight(double hgt){
    bool validData = false;

    if (height >= 0){
        height = hgt;
		validData = true;
    }

    return validData;
}

double Trapezoid::getBase1()
{
    return base1;
}

double Trapezoid::getBase2()
{
    return base2;
}

double Trapezoid::getHeight()
{
    return height;
}

double Trapezoid::calcArea(){
    return ( base1 + base2 ) * height / 2.0;
}