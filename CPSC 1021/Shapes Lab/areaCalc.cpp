//This program calculates the area of different shapes based on user input

#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Trapezoid.h"

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){

    int menuChoice;
    double circleRad,
        squareSide,
        rectangleLength,
        rectangleWidth,
        trapezoidBaseOne,
        trapezoidBaseTwo,
        trapezoidHeight;

    // bool continueFlag = true;
    bool continueFlag = false; // we are disabling continuations so that it only loops once.

    do {
        cout << "Program to calculate areas of objects" << endl;
        cout << "1 -- circle" << endl;
        cout << "2 -- square" << endl;
        cout << "3 -- rectangle" << endl;
        cout << "4 -- trapezoid" << endl;
        cout << "5 -- quit" << endl;
        cin >> menuChoice;

        switch (menuChoice) {

            case 1:
                Circle circleInstance;
                // cout << "Radius of the circle: ";
                cout << "Radius: ";
                cin >> circleRad;
                
                if(circleInstance.setRadius(circleRad)){
                    cout << setprecision(1) << fixed << showpoint<< "Area: " << circleInstance.calcArea() << endl;
                }
                

                break;

            case 2:
                Square squareInstance;
                // cout << "Side length of square: ";
                cout << "Side : ";
                cin >> squareSide;
            
                if(squareInstance.setSide(squareSide)){
                    cout << setprecision(1) << fixed << showpoint << "Area: " << squareInstance.calcArea() << endl;

                }
                

                break;

            case 3:
                Rectangle rectangleInstance;
                // cout << "Length of rectangle: ";
                cout << "Length: ";
                cin >> rectangleLength;
                

                // cout << "Width of rectangle: ";
                cout << "Width: ";
                cin >> rectangleWidth;
                
                if(rectangleInstance.setLength(rectangleLength) && rectangleInstance.setWidth(rectangleWidth)){
                    cout << setprecision(1) << fixed << showpoint << "Area: " << rectangleInstance.calcArea() << endl;
                }

                break;

            case 4:

                Trapezoid trapezoidInstance;

                // cout << "Trapezoid base 1: ";
                cout << "Base1: ";
                cin >> trapezoidBaseOne;

                // cout << "Trapezoid base 2: ";
                cout << "Base2: ";
                cin >> trapezoidBaseTwo;

                // cout << "Trapezoid height: ";
                cout << "Height: ";
                cin >> trapezoidHeight;

                if(trapezoidInstance.setBase1(trapezoidBaseOne)&&trapezoidInstance.setBase2(trapezoidBaseTwo)&&trapezoidInstance.setHeight(trapezoidHeight)){
                    cout << setprecision(1) << fixed << showpoint<< "Area: " << trapezoidInstance.calcArea() << endl;
                }

                    break;

            case 5:
                cout << "quitting program." << endl;
                continueFlag = false;

                break;

            default:
                cout << "invalid input. please type 1, 2, 3, 4, or 5." << endl;

        }
    } while (continueFlag);

    return 0;
}