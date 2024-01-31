#include <iostream>
#include <cmath>
using namespace std;

#ifndef CIRLCE_H
#define CIRCLE_H

class Circle{
    private:
       double radius;
    public:
        bool setRadius(double);
        double getRadius();
        double calcArea();
};
#endif