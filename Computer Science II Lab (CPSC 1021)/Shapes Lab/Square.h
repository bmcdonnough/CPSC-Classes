#include <iostream>
#include <cmath>
using namespace std;

#ifndef SQUARE_H
#define SQUARE_H

class Square{
    private:
       double side;
    public:
        bool setSide(double);
        double getSide();
        double calcArea();
};
#endif